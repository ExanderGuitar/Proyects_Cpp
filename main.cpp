// Name: main.cpp
// Proyect: Space Communication
// Creator: Alejandro G. Surio
// Date: 29 February 2024

#include <iostream>
#include <vector>
#include "../headers/Terminal.hpp"
#include "../headers/Satellite.hpp"

void mainMenu (std::string_view msg);
Satellite generateSatellite1();
Satellite generateSatellite2();

int main () {
    std::vector<Satellite> lowOrbitSatellites;
    Satellite satellite1 = generateSatellite1();
    Satellite satellite2 = generateSatellite2();
    lowOrbitSatellites.push_back(satellite1);
    lowOrbitSatellites.push_back(satellite2);

    Terminal terminal(lowOrbitSatellites);
    bool gameRunning = true;
    std::string message = "";

    while (gameRunning) {
        system("clear");
        mainMenu(message);

        int userChoice = 0;
        char ignoreInput = 'a';
        std::cout << ">> ";
        std::cin >> userChoice;
        std::cout << '\n';

        switch (userChoice) {
            case 1:
                message = terminal.terminalState();
                break;
            case 2:
                if(terminal.state) {
                    terminal.terminalUsed = true;
                    system("clear");
                    terminal.mainMenuControl();
                }
                else {
                    message = "The terminal is off or not working.";
                }
                break;
            case 3:
                message = terminal.switchOn();
                break;
            case 4:
                message = terminal.turnOff();
                break;
            case 5:
                std::cout << "List of comercial operative satellites.\n";
                for(size_t i = 0; i < lowOrbitSatellites.size(); i++) {
                    std::cout << i + 1 << ". " << lowOrbitSatellites[i].name << ". Tracking number: "
                    << lowOrbitSatellites[i].trackingNumber << ".\n";
                }
                std::cout << "Enter something and press enter to continue.\n";
                std::cin >> ignoreInput;
                break;
            case 6:
                std::cout << "Closing Space Communication\n";
                gameRunning = false;
                break;
            default:
                std::cout << "Input error\n";
        }
    }

    return 0;
}

void mainMenu (std::string_view msg) {
    std::cout << '\n';
    std::cout << "       Space Communication        \n";
    std::cout << "--------------------------------- \n";
    std::cout << " Status: " << msg << '\n';
    std::cout << "--------------------------------- \n";
    std::cout << "1. Check the terminal.\n";
    std::cout << "2. Access to the terminal.\n";
    std::cout << "3. Switch on the terminal.\n";
    std::cout << "4. Turn off the terminal.\n";
    std::cout << "5. Show list of comercial satellites.\n";
    std::cout << "6. Exit.\n";
}


Satellite generateSatellite1() {
    Satellite satellite1;
    satellite1.name = "Seasat";
    satellite1.manufacturer = "JPL";
    satellite1.description = "Remote sensing of Earth's oceans";
    satellite1.speed = 28800;
    satellite1.operativeDays = 78;
    satellite1.trackingNumber = "2D389L";
    satellite1.altitude = 300;
    return satellite1;
}

Satellite generateSatellite2() {
    Satellite satellite2;
    satellite2.name = "Kosmos 1";
    satellite2.manufacturer = "Yuzhnoye";
    satellite2.description = "Measurement of Earth's ionosfere";
    satellite2.speed = 28239.40;
    satellite2.operativeDays = 32;
    satellite2.trackingNumber = "5R128K";
    satellite2.altitude = 1050;
    return satellite2;
}
