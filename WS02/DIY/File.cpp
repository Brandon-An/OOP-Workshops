#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read (char *string) {
      int fr;
      fr = fscanf(fptr, "%[^,],", string);
      if (fr == 1)
      	return true;
      else
        return false;
   }

   bool read(int &number) {
      int fr;
      fr = fscanf(fptr, "%d\n", &number);
      if (fr == 1)
      	return true;
      else
        return false;
   }

   

}