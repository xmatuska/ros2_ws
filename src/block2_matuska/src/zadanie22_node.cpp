#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <iostream>
#include "abb_irb4600_ikfast/abb_irb4600_ikfast.h"
#include <Eigen/Geometry>
#include <vector>

Eigen::MatrixXd Matica(double t0, double tf) {
    Eigen::MatrixXd m(6, 6);
    m <<    1, t0, pow(t0, 2), pow(t0, 3), pow(t0, 4), pow(t0, 5),
            0, 1, 2 * t0, 3 * pow(t0, 2), 4 * pow(t0, 3), 5 * pow(t0, 4),
            0, 0, 2, 6 * t0, 12 * pow(t0, 2), 20 * pow(t0, 3),
            1, tf, pow(tf, 2), pow(tf, 3), pow(tf, 4), pow(tf, 5),
            0, 1, 2 * tf, 3 * pow(tf, 2), 4 * pow(tf, 3), 5 * pow(tf, 4),
            0, 0, 2, 6 * tf, 12 * pow(tf, 2), 20 * pow(tf, 3);

    return m;
}

std::vector<double> hodnoty(double t, const Eigen::VectorXd &a) {

    double pozicia = a[0] + a[1] * t + a[2] * pow(t, 2) + a[3] * pow(t, 3) + a[4] * pow(t, 4) + a[5] * pow(t, 5);
    double rychlost = a[1] + 2 * a[2] * t + 3 * a[3] * pow(t, 2) + 4 * a[4] * pow(t, 3) + 5 * a[5] * pow(t, 4);
    double zrychlenie = 2 * a[2] + 6 * a[3] * t + 12 * a[4] * pow(t, 2) + 20 * a[5] * pow(t, 3);

    return {pozicia, rychlost, zrychlenie};
}


Eigen::VectorXd computeIK(const Eigen::VectorXd& vector, const Eigen::VectorXd& current_joint_positions, rclcpp::Logger logger) {
   

    double x = vector(0);
    double y = vector(1);
    double z = vector(2);
    double rx = vector(3);
    double ry = vector(4);
    double rz = vector(5);

    // vstupna poloha
    RCLCPP_INFO(logger, "Pose x, y, z, rx, ry, rz: %f %f %f %f %f %f", x, y, z, rx, ry, rz);

    // vytvorenie polohy ako Eigen::Affine3d object
    Eigen::Affine3d pose = Eigen::Translation3d(Eigen::Vector3d(x, y, z)) *
                           Eigen::AngleAxisd(rx, Eigen::Vector3d::UnitX()) *
                           Eigen::AngleAxisd(ry, Eigen::Vector3d::UnitY()) *
                           Eigen::AngleAxisd(rz, Eigen::Vector3d::UnitZ());

    
    ikfast_abb::Solutions solutions = ikfast_abb::computeIK(pose);

   
    RCLCPP_INFO(logger, "Computed IK for pose with %lu solutions", solutions.size());

    if (solutions.empty()) {
        RCLCPP_ERROR(logger, "No IK solutions found for the given pose.");
        return Eigen::VectorXd();
    }

    
    double min_distance = std::numeric_limits<double>::max();
    Eigen::VectorXd best_solution(6);

    for (const auto& solution : solutions) {
        //riesenie na vektor
        Eigen::VectorXd solution_vec(6);
        for (size_t i = 0; i < 6; ++i) {
            solution_vec(i) = solution[i];
        }

        
        Eigen::VectorXd diff = solution_vec - current_joint_positions;

        
        double distance = diff.norm(); // euklidova vzdialenost

        // porovnavanie lepsieho vysledku
        if (distance < min_distance) {
            min_distance = distance;
            best_solution = solution_vec;
        }
    }

    
    RCLCPP_INFO(logger, "Best Solution: %f %f %f %f %f %f", best_solution(0), best_solution(1), best_solution(2), best_solution(3), best_solution(4), best_solution(5));

    return best_solution;
}



int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("ik_solver_example");

    auto publisher = node->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
   
    std::vector<std::string> joint_names = {"joint_1", "joint_2", "joint_3", "joint_4", "joint_5", "joint_6"};
  
    sensor_msgs::msg::JointState joint_state;
    joint_state.name = joint_names;
    joint_state.position.resize(joint_names.size(), 0.0);
    joint_state.velocity.resize(joint_names.size(), 0.0);
    joint_state.effort.resize(joint_names.size(), 0.0);

    int frequency = 100;  // Hz
    double max_time = 9.0;  // s

    rclcpp::Rate loop_rate(frequency); 

    // matica 1
    Eigen::MatrixXd matica1 = Matica(0, 1);
    RCLCPP_INFO_STREAM(node->get_logger(), "matica 1 = \n" << matica1);

    // matica 2
    Eigen::MatrixXd matica2 = Matica(1, 2);
    RCLCPP_INFO_STREAM(node->get_logger(), "matica 2 = \n" << matica2);

    // matica 3
    Eigen::MatrixXd matica3 = Matica(2, 3);
    RCLCPP_INFO_STREAM(node->get_logger(), "matica 3 = \n" << matica3);

    // matica 4
    Eigen::MatrixXd matica4 = Matica(3, 4);
    RCLCPP_INFO_STREAM(node->get_logger(), "matica 4 = \n" << matica4);

    // matica 5
    Eigen::MatrixXd matica5 = Matica(4, 5);
    RCLCPP_INFO_STREAM(node->get_logger(), "matica 5= \n" << matica5);

    // matica 9
    Eigen::MatrixXd matica9 = Matica(5, 9);
    RCLCPP_INFO_STREAM(node->get_logger(), "matica 6= \n" << matica9);


    Eigen::VectorXd postzero(6);
    postzero << 1, 0, 1.6, 0, M_PI / 2, 0;
    RCLCPP_INFO_STREAM(node->get_logger(), "pozicia v tzero = \n" << postzero);    

    Eigen::VectorXd post0(6);
    post0 << 1, 0, 1, 0, M_PI / 2, 0;
    RCLCPP_INFO_STREAM(node->get_logger(), "pozicia v t0 = \n" << post0);

    Eigen::VectorXd post1(6);
    post1 << 1, 0, 1, 0, M_PI / 2, M_PI / 2;
    RCLCPP_INFO_STREAM(node->get_logger(), "pozicia v t1 = \n" << post1);

    Eigen::VectorXd post2(6);
    post2 << 1, 0, 1, 0, M_PI / 2, M_PI / 2;
    RCLCPP_INFO_STREAM(node->get_logger(), "pozicia v t2 = \n" << post2);

    Eigen::VectorXd post3(6);
    post3 << 1, 0.5, 1, 0, M_PI / 2, M_PI / 2;
    RCLCPP_INFO_STREAM(node->get_logger(), "pozicia v t3 = \n" << post3);

    Eigen::VectorXd post4(6);
    post4 << 1, 0.5, 1.6, 0, M_PI / 2, 0;
    RCLCPP_INFO_STREAM(node->get_logger(), "pozicia v t4 = \n" << post4);

    Eigen::VectorXd post5(6);
    post5 << 1, 0, 1.6, 0, M_PI / 2, 0;
    RCLCPP_INFO_STREAM(node->get_logger(), "pozicia v t5 = \n" << post5);

    Eigen::VectorXd post9(6);
    post9 << 1, 0, 1.6, 0, M_PI / 2, 0;
    RCLCPP_INFO_STREAM(node->get_logger(), "pozicia v t9 = \n" << post9);


    // 
    // Eigen::VectorXd a1 = matica1.inverse() * best_klb1;
    // RCLCPP_INFO_STREAM(node->get_logger(), "a1 = \n" << a1);

    Eigen::VectorXd best_klb0 = computeIK(postzero, post0, node->get_logger());
    Eigen::VectorXd best_klb1 = computeIK(post0, post1, node->get_logger());
    Eigen::VectorXd best_klb2 = computeIK(post1, post2, node->get_logger());
    Eigen::VectorXd best_klb3 = computeIK(post2, post3, node->get_logger());
    Eigen::VectorXd best_klb4 = computeIK(post3, post4, node->get_logger());
    Eigen::VectorXd best_klb5 = computeIK(post4, post5, node->get_logger());
    Eigen::VectorXd best_klb9 = computeIK(post5, post9, node->get_logger());

    //cas od 0 do 1s
    Eigen::VectorXd qt1_j0(6);
    qt1_j0 << best_klb0[0], 0, 0, best_klb1[0], 0, 0;
    Eigen::VectorXd a1_j0 = matica1.inverse() * qt1_j0;

    Eigen::VectorXd qt1_j1(6);
    qt1_j1 << best_klb0[1], 0, 0, best_klb1[1], 0, 0;
    Eigen::VectorXd a1_j1 = matica1.inverse() * qt1_j1;

    Eigen::VectorXd qt1_j2(6);
    qt1_j2 << best_klb0[2], 0, 0, best_klb1[2], 0, 0;
    Eigen::VectorXd a1_j2 = matica1.inverse() * qt1_j2;

    Eigen::VectorXd qt1_j3(6);
    qt1_j3 << best_klb0[3], 0, 0, best_klb1[3], 0, 0;
    Eigen::VectorXd a1_j3 = matica1.inverse() * qt1_j3;

    Eigen::VectorXd qt1_j4(6);
    qt1_j4 << best_klb0[4], 0, 0, best_klb1[4], 0, 0;
    Eigen::VectorXd a1_j4 = matica1.inverse() * qt1_j4;

    Eigen::VectorXd qt1_j5(6);
    qt1_j5 << best_klb0[5], 0, 0, best_klb1[5], 0, 0;
    Eigen::VectorXd a1_j5 = matica1.inverse() * qt1_j5;


    //cas od 1 do 2s
    Eigen::VectorXd qt2_j0(6);
    qt2_j0 << best_klb1[0], 0, 0, best_klb2[0], 0, 0;
    Eigen::VectorXd a2_j0 = matica2.inverse() * qt2_j0;
    
    Eigen::VectorXd qt2_j1(6);
    qt2_j1 << best_klb1[1], 0, 0, best_klb2[1], 0, 0;
    Eigen::VectorXd a2_j1 = matica2.inverse() * qt2_j1;

    Eigen::VectorXd qt2_j2(6);
    qt2_j2 << best_klb1[2], 0, 0, best_klb2[2], 0, 0;
    Eigen::VectorXd a2_j2 = matica2.inverse() * qt2_j2;

    Eigen::VectorXd qt2_j3(6);
    qt2_j3 << best_klb1[3], 0, 0, best_klb2[3], 0, 0;
    Eigen::VectorXd a2_j3 = matica2.inverse() * qt2_j3;

    Eigen::VectorXd qt2_j4(6);
    qt2_j4 << best_klb1[4], 0, 0, best_klb2[4], 0, 0;
    Eigen::VectorXd a2_j4 = matica2.inverse() * qt2_j4;

    Eigen::VectorXd qt2_j5(6);
    qt2_j5 << best_klb1[5], 0, 0, best_klb2[5], 0, 0;
    Eigen::VectorXd a2_j5 = matica2.inverse() * qt2_j5;

    //cas od 2 do 3s
    Eigen::VectorXd qt3_j0(6);
    qt3_j0 << best_klb2[0], 0, 0, best_klb3[0], 0, 0;
    Eigen::VectorXd a3_j0 = matica3.inverse() * qt3_j0;

    Eigen::VectorXd qt3_j1(6);
    qt3_j1 << best_klb2[1], 0, 0, best_klb3[1], 0, 0;
    Eigen::VectorXd a3_j1 = matica3.inverse() * qt3_j1;

    Eigen::VectorXd qt3_j2(6);
    qt3_j2 << best_klb2[2], 0, 0, best_klb3[2], 0, 0;
    Eigen::VectorXd a3_j2 = matica3.inverse() * qt3_j2;

    Eigen::VectorXd qt3_j3(6);
    qt3_j3 << best_klb2[3], 0, 0, best_klb3[3], 0, 0;
    Eigen::VectorXd a3_j3 = matica3.inverse() * qt3_j3;
    
    Eigen::VectorXd qt3_j4(6);
    qt3_j4 << best_klb2[4], 0, 0, best_klb3[4], 0, 0;
    Eigen::VectorXd a3_j4 = matica3.inverse() * qt3_j4;

    Eigen::VectorXd qt3_j5(6);
    qt3_j5 << best_klb2[5], 0, 0, best_klb3[5], 0, 0;
    Eigen::VectorXd a3_j5 = matica3.inverse() * qt3_j5;

    //cas od 3 do 4s
    Eigen::VectorXd qt4_j0(6);
    qt4_j0 << best_klb3[0], 0, 0, best_klb4[0], 0, 0;
    Eigen::VectorXd a4_j0 = matica4.inverse() * qt4_j0;

    Eigen::VectorXd qt4_j1(6);
    qt4_j1 << best_klb3[1], 0, 0, best_klb4[1], 0, 0;
    Eigen::VectorXd a4_j1 = matica4.inverse() * qt4_j1;

    Eigen::VectorXd qt4_j2(6);
    qt4_j2 << best_klb3[2], 0, 0, best_klb4[2], 0, 0;
    Eigen::VectorXd a4_j2 = matica4.inverse() * qt4_j2;

    Eigen::VectorXd qt4_j3(6);
    qt4_j3 << best_klb3[3], 0, 0, best_klb4[3], 0, 0;
    Eigen::VectorXd a4_j3 = matica4.inverse() * qt4_j3;

    Eigen::VectorXd qt4_j4(6);
    qt4_j4 << best_klb3[4], 0, 0, best_klb4[4], 0, 0;
    Eigen::VectorXd a4_j4 = matica4.inverse() * qt4_j4;

    Eigen::VectorXd qt4_j5(6);
    qt4_j5 << best_klb3[5], 0, 0, best_klb4[5], 0, 0;
    Eigen::VectorXd a4_j5 = matica4.inverse() * qt4_j5;

    //cas od 4 do 5s
    Eigen::VectorXd qt5_j0(6);
    qt5_j0 << best_klb4[0], 0, 0, best_klb5[0], 0, 0;
    Eigen::VectorXd a5_j0 = matica5.inverse() * qt5_j0;

    Eigen::VectorXd qt5_j1(6);
    qt5_j1 << best_klb4[1], 0, 0, best_klb5[1], 0, 0;
    Eigen::VectorXd a5_j1 = matica5.inverse() * qt5_j1;

    Eigen::VectorXd qt5_j2(6);
    qt5_j2 << best_klb4[2], 0, 0, best_klb5[2], 0, 0;
    Eigen::VectorXd a5_j2 = matica5.inverse() * qt5_j2;

    Eigen::VectorXd qt5_j3(6);
    qt5_j3 << best_klb4[3], 0, 0, best_klb5[3], 0, 0;
    Eigen::VectorXd a5_j3 = matica5.inverse() * qt5_j3;

    Eigen::VectorXd qt5_j4(6);
    qt5_j4 << best_klb4[4], 0, 0, best_klb5[4], 0, 0;
    Eigen::VectorXd a5_j4 = matica5.inverse() * qt5_j4;

    Eigen::VectorXd qt5_j5(6);
    qt5_j5 << best_klb4[5], 0, 0, best_klb5[5], 0, 0;
    Eigen::VectorXd a5_j5 = matica5.inverse() * qt5_j5;

    //cas od 5 do 9s
    Eigen::VectorXd qt9_j0(6);
    qt9_j0 << best_klb5[0], 0, 0, best_klb9[0], 0, 0;
    Eigen::VectorXd a9_j0 = matica9.inverse() * qt9_j0;

    Eigen::VectorXd qt9_j1(6);
    qt9_j1 << best_klb5[1], 0, 0, best_klb9[1], 0, 0;
    Eigen::VectorXd a9_j1 = matica9.inverse() * qt9_j1;

    Eigen::VectorXd qt9_j2(6);
    qt9_j2 << best_klb5[2], 0, 0, best_klb9[2], 0, 0;
    Eigen::VectorXd a9_j2 = matica9.inverse() * qt9_j2;

    Eigen::VectorXd qt9_j3(6);
    qt9_j3 << best_klb5[3], 0, 0, best_klb9[3], 0, 0;
    Eigen::VectorXd a9_j3 = matica9.inverse() * qt9_j3;

    Eigen::VectorXd qt9_j4(6);
    qt9_j4 << best_klb5[4], 0, 0, best_klb9[4], 0, 0;
    Eigen::VectorXd a9_j4 = matica9.inverse() * qt9_j4;

    Eigen::VectorXd qt9_j5(6);
    qt9_j5 << best_klb5[5], 0, 0, best_klb9[5], 0, 0;
    Eigen::VectorXd a9_j5 = matica9.inverse() * qt9_j5;

    joint_state.header.stamp = node->get_clock()->now();

    while (1) {

        for (double t = 0; t <= 9; t += 0.01) {
            
            if (t <= 1) {

                joint_state.position[0] = hodnoty(t, a1_j0)[0];
                joint_state.position[1] = hodnoty(t, a1_j1)[0];
                joint_state.position[2] = hodnoty(t, a1_j2)[0];
                joint_state.position[3] = hodnoty(t, a1_j3)[0];
                joint_state.position[4] = hodnoty(t, a1_j4)[0];
                joint_state.position[5] = hodnoty(t, a1_j5)[0];  
            }

            if (t > 1 && t <= 2) {

                joint_state.position[0] = hodnoty(t, a2_j0)[0];
                joint_state.position[1] = hodnoty(t, a2_j1)[0];
                joint_state.position[2] = hodnoty(t, a2_j2)[0];
                joint_state.position[3] = hodnoty(t, a2_j3)[0];
                joint_state.position[4] = hodnoty(t, a2_j4)[0];
                joint_state.position[5] = hodnoty(t, a2_j5)[0];  
            }

            if (t > 2 && t <= 3) {

                joint_state.position[0] = hodnoty(t, a3_j0)[0];
                joint_state.position[1] = hodnoty(t, a3_j1)[0];
                joint_state.position[2] = hodnoty(t, a3_j2)[0];
                joint_state.position[3] = hodnoty(t, a3_j3)[0];
                joint_state.position[4] = hodnoty(t, a3_j4)[0];
                joint_state.position[5] = hodnoty(t, a3_j5)[0];  
            }

            if (t > 3 && t <= 4) {

                joint_state.position[0] = hodnoty(t, a4_j0)[0];
                joint_state.position[1] = hodnoty(t, a4_j1)[0];
                joint_state.position[2] = hodnoty(t, a4_j2)[0];
                joint_state.position[3] = hodnoty(t, a4_j3)[0];
                joint_state.position[4] = hodnoty(t, a4_j4)[0];
                joint_state.position[5] = hodnoty(t, a4_j5)[0];  
            }

            if (t > 4 && t <= 5) {

                joint_state.position[0] = hodnoty(t, a5_j0)[0];
                joint_state.position[1] = hodnoty(t, a5_j1)[0];
                joint_state.position[2] = hodnoty(t, a5_j2)[0];
                joint_state.position[3] = hodnoty(t, a5_j3)[0];
                joint_state.position[4] = hodnoty(t, a5_j4)[0];
                joint_state.position[5] = hodnoty(t, a5_j5)[0];  
            }

            if (t > 5 && t <= 9) {

                joint_state.position[0] = hodnoty(t, a9_j0)[0];
                joint_state.position[1] = hodnoty(t, a9_j1)[0];
                joint_state.position[2] = hodnoty(t, a9_j2)[0];
                joint_state.position[3] = hodnoty(t, a9_j3)[0];
                joint_state.position[4] = hodnoty(t, a9_j4)[0];
                joint_state.position[5] = hodnoty(t, a9_j5)[0];  
            }


            

            joint_state.header.stamp = node->get_clock()->now();
            publisher->publish(joint_state);
            loop_rate.sleep();

        }
    }
    rclcpp::shutdown();
    return 0;

    

}