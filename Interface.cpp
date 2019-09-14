#include "Interface.hpp"

//Show the main loading information
void Interface::mainLoading () {
   system("cls");

   lineDesign ('*');
   cout << "Welcome to Timeline" << endl;
   lineDesign ('-');
   cout << "Developed by Alejandro g. Surio" << endl;
   lineDesign ('*');
   cout << endl;

};

//Show the first selectable menu
void Interface::mainMenu () {
   centerWords("Main", ' ');
   lineDesign('=');
   cout << "1. Nuevo evento" << endl;
   cout << "2. Mostrar linea temporal" << endl;
   cout << "3. Buscar" << endl;
   cout << "4. Salir" << endl;
   lineDesign('=');
   cout << "Tu seleccion: ";
};

//Print line with a select character
void Interface::lineDesign (char sim) {
   for (int i = 0; i < width; i++) {
      cout << sim;
   }

   cout << endl;
};

//Prints a word centered with given char
void Interface::centerWords (string word, char sim) {
   int midWord = word.length()/2;
   int mid = width/2;

   for(int i = 0; i < mid - midWord; i++) {
      cout << sim;
   };
   cout << word;
   for(int i = 0; i < width - mid; i++) {
      cout << sim;
   };
   cout << endl;
};
