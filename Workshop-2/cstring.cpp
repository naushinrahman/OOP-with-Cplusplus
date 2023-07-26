/*/////////////////////////////////////////////////////////////////////////
Workshop - #1 (P2)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"

namespace sdds {
   // Copies the srouce character string into the destination
   void strCpy(char* des, const char* src) {
      int i;
      des[500];
      for (i = 0; src[i] != '\0'; i++)
      {
         des[i] = src[i];
      }
      des[i] = '\0';
   }
   // Copies the source character string into the destination upto "len"
   // characters. The destination will be null terminated only if the number
   // of the characters copied is less than "len"
   void strnCpy(char* des, const char* src, int len) {
      int i, j;
      for (j = 0; src[j] != '\0'; j++);
      for (i = 0; i < len; i++)
      {
         des[i] = src[i];
      }
   }

   // Compares two C-strings 
   // returns 0 i thare the same
   // return > 0 if s1 > s2
   // return < 0 if s1 < s2
   int strCmp(const char* s1, const char* s2) {
      int i,j,k;
      for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
      if ((int)s1[i] > (int)s2[i]) {
         j = (int)s1[i] - (int)s2[i];
         return j;
      }
      else if ((int)s1[i] < (int)s2[i]) {
         k = (int)s1[i] - (int)s2[i];
         return k;
      }
      else {
         return 0;
      }
   }

   // returns 0 i thare the same
   // return > 0 if s1 > s2
   // return < 0 if s1 < s2
   int strnCmp(const char* s1, const char* s2, int len) {
      int i,j, k;
      for (i = 0; i < len; i++) {
         if (s1[i] != s2[i]) {
            if ((int)s1[i] > (int)s2[i]) {
               j = (int)s1[i] - (int)s2[i];
               i = len;
               return j;
            }
            else if ((int)s1[i] < (int)s2[i]) {
               k = (int)s1[i] - (int)s2[i];
               i = len;
               return k;
            }
         }
      }
      return 0;
   }

   // returns the lenght of the C-string in characters
   int strLen(const char* s) {
      int i;
      for (i = 0; s[i] != '\0'; i++);
      return i;
   }

   // returns the address of first occurance of "str2" in "str1"
   // returns nullptr if no match is found
   const char* strStr(const char* str1, const char* str2) {
      int j,k,l;
      char* null = { NULL };
      for (j = 0; str1[j] != '\0'; j++) {
         if (str2[0] == str1[j]) {
         break;
         }
      }
      l = j;
      for (k = 0; str2[k] != '\0'; k++) {
         if (str2[k] == str1[l]) {
            l++;
         }
         else {
            return null;
         }
      }
      return &str1[j];
   }

   // Concantinates "src" C-string to the end of "des"
   void strCat(char* des, const char* src) {
      int i,j;
      for (i = 0; des[i] != '\0'; i++);
      for (j = 0; src[j] != '\0'; j++) {
         des[i] = src[j];
         i++;
      }
      des[i] = '\0';
   }
}
