/*/////////////////////////////////////////////////////////////////////////
Workshop - #3 (P2)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"

namespace sdds {
   class CalorieList {
      Food* m_food;
      int m_numOfFoods;
      int m_foodsadded;
      int calSum()const;
      void header()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;
   public:
      void init(int size);
      bool add(const char* item_name, int calories, int when);
      void display()const;
      void deallocate();
  };
  
}

#endif // !SDDS_CALORIELIST_H
