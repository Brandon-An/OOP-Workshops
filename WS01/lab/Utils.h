#ifndef _UTILS_H_
#define _UITLS_H_

namespace sdds{

void flushkeys();
bool ValidYesResponse(char ch);
bool yes();
void readCstr(char cstr[], int len);
int readInt(int min, int max);
}

#endif