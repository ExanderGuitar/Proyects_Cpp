#include "Interface.hpp"

void Interface::mainLoading () {
   lineDesign ('*');
   cout << "Welcome to Timeline" << endl;
   lineDesign ('-');
   cout << "Developed by Alejandro g. Surio" << endl;
   lineDesign ('*');
   cout << endl;

};

void Interface::mainMenu () {
   centerWords("Main");
   lineDesign('-');
   cout << "1. Salir" << endl;
};

void Interface::lineDesign (char sim) {
   for (int i = 0; i < width; i++) {
      cout << sim;
   }

   cout << endl;
};

void Interface::centerWords (string word) {
   int midWord = word.length()/2;
   int mid = width/2;

   for(int i = 0; i < mid - midWord; i++) {
      cout << " ";
   };
   cout << word;
   for(int i = 0; i < width - mid; i++) {
      cout << " ";
   };
   cout << endl;
};
