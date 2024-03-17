// Name: Satellite.hpp
// Proyect: Space Communication
// Creator: Alejandro G. Surio
// Date: 1 March 2024

#ifndef SATELLITE_HPP
#define SATELLITE_HPP

#include <string>
#include <iostream>

struct Satellite
{
    std::string name = "";
    std::string description = "";
    std::string manufacturer = "";
    std::string trackingNumber = "";
    int operativeDays = 0;
    double speed = 0;
    float altitude = 0;

    void specsDescription();
};

#endif
