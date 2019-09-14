#include <iostream>
#include "Interface.hpp"
#include "SaveLogic.hpp"
using namespace std;

int main () {

   Interface gui;
   SaveLogic file;

   gui.mainLoading();
   gui.mainMenu();

   return 0;
};
