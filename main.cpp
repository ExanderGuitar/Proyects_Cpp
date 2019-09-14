#include <iostream>
#include "Interface.hpp"
using namespace std;

int main () {

   Interface gui;

   int mainSelection = 0;

   while (mainSelection != 4) {
      gui.mainLoading();
      gui.mainMenu();
      cin >> mainSelection;

      switch (mainSelection) {
         case 1: {
            cout << "Creating event" << endl;
            break;
         };
         case 2: {
            cout << "Shown all line events" << endl;
            break;
         };
         case 3: {
            cout << "Searching menu" << endl;
            break;
         };
         case 4: {
            cout << "Closing program" << endl;
            break;
         };
         default: {
            cout << "Wrong selection" << endl;
            break;
         };
      };
   };

   system("cls");
   return 0;
};
