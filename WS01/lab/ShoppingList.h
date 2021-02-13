#ifndef _SHOPPING_LIST_H_
#define _SHOPPING_LIST_H_
#include "ShoppingRec.h"

namespace sdds{

bool loadList();
void displayList();
void removeBoughtItems();
void removeItem(int index);
bool saveList();
void clearList();
void toggleBought();
void addItemToList();
void removeItemfromList();
bool listIsEmpty();
}

#endif