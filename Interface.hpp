#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
using namespace std;

class Interface {
   public:
	void mainLoading();
	void mainMenu();
   private:
	void lineDesign (char sim);
	void centerWords (string word);
	int width = 40;

};

#endif
