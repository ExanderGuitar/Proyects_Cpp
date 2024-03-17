// Name: Terminal.cpp
// Proyect: Space Communication
// Creator: Alejandro G. Surio
// Date: 29 February 2024

#ifndef TERMINAL_CPP
#define TERMINAL_CPP

#include "../headers/Terminal.hpp"

Terminal::Terminal(std::vector<Satellite> &listOfSatellites) {
    worldSatellites = listOfSatellites;
}

std::string Terminal::terminalState() {
    state ? debugMessage = "The terminal is already on." : 
        debugMessage = "The terminal is off.";
    return debugMessage;
}

std::string Terminal::turnOff() {
    if (state) {
        debugMessage = "Turning off the terminal.";
        state = false;
    }
    else {
        debugMessage = "The terminal is already off.";
    }
    return debugMessage;
}

std::string Terminal::switchOn() {
    if (state) {
        debugMessage = "The terminal is already running.";
    }
    else {
        debugMessage = "Switching on the terminal.";
        state = true;
    }
    return debugMessage;
}

void Terminal::mainMenu() {
    std::cout << "Electronic Orbital Monitoring Solutions (EOMS)\n";
    std::cout << "Low orbit satellites tracking system\n";
    std::cout << "Version 0.1\n";
    std::cout << "** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **\n";
    std::cout << '\n';
    std::cout << "1. List of tracked satellites.\n";
    std::cout << "2. Open satellite comunication.\n";
    std::cout << "3. Add new satellite tracking number.\n";
    std::cout << "4. Remove a satellite from the tracking system.\n";
    std::cout << "5. Leave the terminal.\n";
}

void Terminal::mainMenuControl() {
    
    while(terminalUsed) {
        Terminal::mainMenu();
        int userInput = 0;
        std::cout << ">> ";
        std::cin >> userInput;
        std::cout << '\n';

        switch(userInput) {
            case 1:
                Terminal::showTrackedSatellites();
                break;
            case 2:
                std::cout << "Stablishing communication...\n";
                break;
            case 3:
                Terminal::addSatellite();
                break;
            case 4:
                Terminal::removeSatellite();
                break;
            case 5:
                std::cout << "Closing session.\n";
                terminalUsed = false;
                break;
            default:
                std::cout << "Input error.\n";
                break;
        }
    }
}

void Terminal::showTrackedSatellites() {
    if(trackingSatellites.empty()) {
        std::cout << "There isn't any monitored satellite.\n";
        std::cout << '\n';
    }
    else {
        std::cout << "List of monitored satellites\n";
        std::cout << "-- --- -- --- -- --- -- --- --\n";

        for(size_t i = 0; i < trackingSatellites.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << trackingSatellites[i].name << ". ";
            std::cout << "Tracking number: ";
            std::cout << trackingSatellites[i].trackingNumber << ".\n";
        }

        std::cout << '\n';
        std::cout << "Do you want more information about a satellite?\n";
        std::cout << "1. Yes.\n";
        std::cout << "2. No.\n";
        std::cout << ">> ";

        int userInput = 0;
        std::cin >> userInput;

        if(userInput == 1) {
            std::cout << "Select the number of the satellite.\n";
            std::cout << ">> ";

            int satSelected = 0;
            std::cin >> satSelected;
            satSelected -= 1;
            std::cout << '\n';

            if(satSelected >= 0 && satSelected < trackingSatellites.size()) {
                trackingSatellites[satSelected].specsDescription();
            }
            else {
                std::cout << "Incorrect selection.\n";
            }
        }

        std::cout << '\n';
    }
}

void Terminal::addSatellite() {
    std::cout << "Electronic Orbital Monitoring Solutions (EOMS)\n";
    std::cout << "Low orbit satellites tracking system\n";
    std::cout << "Version 0.1\n";
    std::cout << "** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **\n";
    std::cout << '\n';
    std::cout << "Add new tracking satellite number.\n";
    std::cout << "Number: ";

    std::string trackingNumber = "";
    std::cin >> trackingNumber;
    Terminal::requestSatelliteNumber(worldSatellites, trackingNumber);

    std::cout << '\n';
}

void Terminal::requestSatelliteNumber(std::vector<Satellite> existentSatellites, std::string number) {
    Satellite satellite;

    for(size_t i = 0; i < existentSatellites.size(); i++) {
        if(existentSatellites[i].trackingNumber == number) {
            satellite = existentSatellites[i];
        }
    }

    if(satellite.name.empty()) {
        std::cout << "Satellite not found.\n";
    }
    else {
        trackingSatellites.push_back(satellite);
        std::cout << "Satellite added to the tracking list.\n";
    }
}

void Terminal::removeSatellite() {
    std::cout << "Electronic Orbital Monitoring Solutions (EOMS)\n";
    std::cout << "Low orbit satellites tracking system\n";
    std::cout << "Version 0.1\n";
    std::cout << "** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **\n";
    std::cout << '\n';

    if(trackingSatellites.empty()) {
        std::cout << "There are not tracked satellites\n";
    }
    else {
        std::cout << "Remove a satellite from the tracking list.\n";
        std::cout << "Select which satellite you want to remove.\n";
        std::cout << '\n';
    
        std::cout << "List of monitored satellites\n";
        std::cout << "-- --- -- --- -- --- -- --- --\n";
    
        for(size_t i = 0; i < trackingSatellites.size(); i++) {
            std::cout << i + 1 << ". ";
            std::cout << trackingSatellites[i].name << ". ";
            std::cout << "Tracking number: ";
            std::cout << trackingSatellites[i].trackingNumber << ".\n";
        }
    
        std::cout << "Select the number of the satellite.\n";
        std::cout << ">> ";
    
        int satSelected = 0;
        std::cin >> satSelected;
        satSelected -= 1;
    
        if(satSelected >= 0 && satSelected < trackingSatellites.size()) {
            trackingSatellites.erase(trackingSatellites.begin() + satSelected);
            std::cout << "Satellite untracked\n";
        }
    }
}
#endif
