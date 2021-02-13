// Workshop 1:
// Version: 0.9
// Date: 2021/10/16
// Author: Fardad Soleimanloo
// Description:
// w1p1.cpp
///////////////////////////////////////////////////
//==============================================
// Name:           Brandon An
// Student Number: 152900197
// Email:          ban4@myseneca.ca
// Date:	          Jan 20 2021
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include "File.h"
#include "Utils.h"
#include "ShoppingList.h"

// set to false when compling on Linux
const bool APP_OS_WINDOWS = false;

using namespace std;
using namespace sdds;


extern FILE* sfptr;


int listMenu();

int main() {
   bool done = false;
   loadList();
   while (!done) {
      system(APP_OS_WINDOWS ? "cls" : "clear");
      switch (listMenu()) {
      case 1:
         toggleBought();
         break;
      case 2:
         addItemToList();
         break;
      case 3:
         removeItemfromList();
         break;
      case 4:
         removeBoughtItems();
         break;
      case 5:
         clearList();
         break;
      default:
         done = true;
      }
   }
   saveList();
   return 0;
}

int listMenu() {
   cout << "-->>> My Shopping List <<<--" << endl;
   displayList();
   cout << "----------------------------" << endl
      << "1- Toggle bought Item" << endl
      << "2- Add Shopping Item" << endl
      << "3- Remove Shopping Item" << endl
      << "4- Remove bought Items" << endl
      << "5- Clear List" << endl
      << "0- Exit" << endl << "> ";
   return readInt(0, 5);
}

