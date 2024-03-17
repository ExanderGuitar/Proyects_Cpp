// Name: Terminal.hpp
// Proyect: Space Communication
// Creator: Alejandro G. Surio
// Date: 29 February 2024

#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <string>
#include <vector>
#include <iostream>
#include "../headers/Satellite.hpp"

struct Terminal
{
    std::string name = "";
    std::string os = "";
    std::string version = "";
    std::string debugMessage = "";
    bool state = false;
    std::vector<Satellite> trackingSatellites;
    std::vector<Satellite> worldSatellites;
    bool terminalUsed = false;

    Terminal(std::vector<Satellite> &listOfSatellites);

    std::string terminalState();
    std::string turnOff();
    std::string switchOn();

    void mainMenu();
    void mainMenuControl();

    void showTrackedSatellites();
    void addSatellite();
    void requestSatelliteNumber(std::vector<Satellite> existentSatellites, std::string number);
    void removeSatellite();
};

#endif