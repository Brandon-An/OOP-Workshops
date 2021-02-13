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
   
   
   bool read(int &number) {
      int fr;
      fr = fscanf(fptr, "%d,", &number);
      if (fr == 1)
      	return true;
      else
        return false;
   }
   bool read(double &salary) {
      int fr;
      fr = fscanf(fptr, "%lf,", &salary);
      if (fr == 1)
      	return true;
      else
        return false;
   }
   bool read (char *string) {
      int fr;
      fr = fscanf(fptr, "%[^\n]\n", string);
      if (fr == 1)
      	return true;
      else
        return false;
   }
   

   
}
