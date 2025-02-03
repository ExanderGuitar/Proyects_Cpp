#include <iostream>
#include <string>
#include <fstream>

struct AminoAcid {
    std::string name;
    float molecularWeight;
    std::string threeLetters;
    char oneLetter;
};

AminoAcid newAminoAcid();

int main(int argc, char *argv[]) {
    AminoAcid aas[23];
    int aasCount = 0;

    std::string inputSequence = "";

    std::cout << "Enter the protein sequence 1 amino acid letter." << std::endl;
    std::cout << "Sequence: ";
    std::cin >> inputSequence;

    std::cout << inputSequence << std::endl;

    if (*argv[1] == 'D') {

        aas[aasCount] = newAminoAcid();
        aasCount++;

        std::cout << aas[0].name << std::endl;

    }

    return 1;
}

AminoAcid newAminoAcid() {
    AminoAcid aa;
    std::cout << "New amino acid entry" << std::endl;
    std::cout << "Name: ";
    std::cin.ignore();
    std::getline(std::cin, aa.name);

    std::cout << "Molecular weight: ";
    std::cin >> aa.molecularWeight;

    std::cout << "Three letters designation: ";
    std::cin >> aa.threeLetters;

    std::cout << "One letter designation: ";
    std::cin >> aa.oneLetter;

    std::cout << "Amino acid stored." << std::endl;
    return aa;
}

