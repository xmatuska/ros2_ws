#include <iostream>
#include "cviko1/robot.hpp"

int main() {
    Robot robot;
    char input;

    std::cout << "ovladanie robota pomocou wasd\n";

    while (true) {
        std::cin >> input;
        
        if (input == 'q') {
            std::cout << "koniec \n";
            break;
        }

        switch (input) {
            case 'w':
                robot.move(0, 1);
                break;
            case 's':
                robot.move(0, -1);
                break;
            case 'a':
                robot.move(-1, 0);
                break;
            case 'd':
                robot.move(1, 0);
                break;
            default:
                std::cout << "Pouzivaj len wasd alebo q.\n";
                continue;
        }

        std::cout << "poloha robota: (" << robot.getX() << ", " << robot.getY() << ")\n";
    }

    return 0;
}
