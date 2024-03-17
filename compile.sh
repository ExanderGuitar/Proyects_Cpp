# Compiler script for the Space Communication proyect
clear
echo Space Communication compiler
echo = = = = = = = = = = = = = = =

# List of files to compile
echo List of files to be compiled:
echo - main.cpp
echo - Terminal.cpp
echo - Satellite.cpp

# Change to the source folder and execute compiler command
cd ../scr
g++ main.cpp Terminal.cpp Satellite.cpp -o "Space Communication" -std=c++2a

# Move the executable to the executable folder and come back to the support folder
mv "Space Communication" ../executable
cd ../support

# Information about the executable
echo ""
echo Program generated as Space Communication is in the folder executable
