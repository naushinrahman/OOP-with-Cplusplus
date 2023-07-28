/*/////////////////////////////////////////////////////////////////////////
Workshop - #2 (P1)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include "Population.h"
#include "File.h"
#include "cstring.h"
#include <iostream>

using namespace std;
namespace sdds {
   int noOfAreas;
   Population* populations;

   void sort() {
      int i, j;
      Population temp;
      for (i = noOfAreas - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (populations[j].m_population > populations[j + 1].m_population) {
               temp = populations[j];
               populations[j] = populations[j + 1];
               populations[j + 1] = temp;
            }
         }
      }
   }

   bool load(Population& populations) {
      bool ok = false;
      char postalCode[124];

      if (((read(postalCode)) && read(populations.m_population))) {
         strCpy(populations.m_postalCode, postalCode);
         ok = true;
      }
      return ok;
   }

   bool load(const char filename[]) {
      bool ok = false;
      int i = 0;
      if (!openFile(filename)) {
         cout << "Could not open data file :" << filename << endl;
      }
      else {
         noOfAreas = noOfRecords();
         populations = new Population[noOfAreas];

         for (; i < noOfAreas; i++) {
            if (load(populations[i])) {
               ok = true;
            }
         }
      }
      closeFile();
      return ok;
   }

   void display() {
      cout << "Postal Code: population\n-------------------------" << endl;
      int sum = 0;
      sort();
      for (int i = 0; i < noOfAreas; i++) {
         cout << i + 1 << "- ";
         display(populations[i]);
         sum += populations[i].m_population;
      }
      cout << "-------------------------\nPopulation of Canada: " << sum << endl;
   }

   void display(const Population& population) {
      cout << population.m_postalCode << ":  " << population.m_population << endl;
   }       

   void deallocateMemory() {
      if (populations != NULL) {
         delete[] populations;
         populations = nullptr;
      }
   }
}