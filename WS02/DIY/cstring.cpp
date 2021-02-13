#include "cstring.h"
namespace sdds {
   void strCpy(char* des, const char* src) {
      while (*src) {
         *des++ = *src++;
      }
      *des = 0;
   }
   void strnCpy(char* des, const char* src, int len) {
      int i = 0;
      while ( i < len - 1 && src[i]) {
         des[i] = src[i];
         i++;
      }
      des[i] = src[i];
   }
   int strCmp(const char* s1, const char* s2) {
      int i = 0;
      while (s1[i] && s2[i] && s1[i] == s2[i]) {
         i++;
      }
      return s1[i] - s2[i];
   }
   int strnCmp(const char* s1, const char* s2, int len) {
      int i = 0;
      while ( i<len-1 && s1[i] && s2[i] && s1[i] == s2[i]) {
         i++;
      }
      return s1[i] - s2[i];
   }
   int strLen(const char* s) {
      int i = -1;
      while (s[++i]);
      return i;
   }
   const char* strStr(const char* str, const char* find) {
      const char* faddress = nullptr;
      int i, flen = strLen(find), slen = strLen(str);
      for (i = 0; i < slen - flen && strnCmp(&str[i], find, flen); i++);
      if (i < slen - flen) faddress = &str[i];
      return faddress;
   }
   void strCat(char* des, const char* src) {
      int len = strLen(des);
      int i = 0;
      while (src[i]) {
         des[i + len] = src[i];
         i++;
      }
      des[i + len] = 0;
   }

}