/*/////////////////////////////////////////////////////////////////////////
Workshop - #2 (P1)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

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
   // TODO: read functions go here
   bool read(char* empName) {
      bool okay = false;
      if (fscanf(fptr, "%[^\n]\n", empName) == 1) {
         okay = true;
      }
      //fscanf(fptr, ",%[^\n]\n", empName) == 1
      return okay; 
   }
   bool read(int& empNum) {
      bool okay = false;
      if (fscanf(fptr, "%d,", &empNum) == 1) {
         okay = true;
      }
      return okay;
   }
   bool read(double& empSalary) {
      bool okay = false;
      if (fscanf(fptr, "%lf,", &empSalary) == 1) {
         okay = true;
      }
      return okay;
   }
}