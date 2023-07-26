/*/////////////////////////////////////////////////////////////////////////
Workshop - #1 (P2)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
have done all the coding by myselfand only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef _SDDS_CSTRING_H_
#define _SDDS_CSTRING_H_

namespace sdds {

   void strCpy(char* des, const char* src);

   void strnCpy(char* des, const char* src, int len);

   int strCmp(const char* s1, const char* s2);

   int strnCmp(const char* s1, const char* s2, int len);

   int strLen(const char* s);

   const char* strStr(const char* str1, const char* str2);

   void strCat(char* des, const char* src);
}
#endif 
