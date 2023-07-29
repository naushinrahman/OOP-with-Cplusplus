/*/////////////////////////////////////////////////////////////////////////
Workshop - #3 (P2)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_BILL_H
#define SDDS_BILL_H
namespace sdds {
   class Food {
      char m_foodName[30];
      int m_calories;
      int m_time;
   public:
      int calories()const;
      void display()const;
      bool isValid()const;
      void set(const char *name, int time, int calories);
      void setEmpty();
   };
}
#endif // !SDDS_BILL_H

