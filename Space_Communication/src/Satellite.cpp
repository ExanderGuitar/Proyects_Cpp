// Name: main.cpp
// Proyect: Space Communication
// Creator: Alejandro G. Surio
// Date: 1 March 2024

#ifndef SATELLITE_CPP
#define SATELLITE_CPP

#include "../headers/Satellite.hpp"

void Satellite::specsDescription() {
    std::cout << "Name: " << name << '\n';
    std::cout << "Description: " << description << '\n';
    std::cout << "Tracking number: " << trackingNumber << '\n';
    std::cout << "Manufacturer: " << manufacturer << '\n';
    std::cout << "Days operative: " << operativeDays << '\n';
    std::cout << "Orbital speed: " << speed << "Km/h\n";
    std::cout << "Altitude: " << altitude << "Km\n";
    std::cout << '\n';
}
#endif
