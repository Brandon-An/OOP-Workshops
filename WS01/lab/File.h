#ifndef _FILE_H_
#define _FILE_H_
#include <cstdio>
#include "ShoppingRec.h"

namespace sdds{

const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
bool openFileForRead();
bool openFileForOverwrite();
void closeFile();
bool freadShoppingRec(ShoppingRec* rec);
void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif