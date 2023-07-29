/*/////////////////////////////////////////////////////////////////////////
Workshop - #3 (P1)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"
#include "Item.h"

using namespace std;
namespace sdds {
   void Item::setName(const char* name) {
      if (name != nullptr) {
         strnCpy(m_itemName, name, 20);
      }
   }

   void Item::setEmpty() {
      m_itemName[0] = '\0';
      m_price = 0.0;
   }

   void Item::set(const char* name, double price, bool taxed) {
      setName(name);
      m_taxed = taxed;
      if (price <= 0 || name == nullptr) {
         setEmpty();
      }
      else {
         m_price = price;
      }
   }

   void Item::display()const {
      if (isValid() == true) {   //prints out item name formatted 
         cout << "| ";
         cout.width(20); cout.fill('.'); cout.setf(ios::left);
         cout << m_itemName;
         cout.unsetf(ios::left);
         cout << " | ";          //prints out item price formatted
         cout.setf(ios::right); cout.setf(ios::fixed); cout.width(7); cout.precision(2);
         cout.fill(' ');
         cout << m_price;
         cout.unsetf(ios::right);
         cout << " | ";
         if (m_taxed == true) {
            cout << "Yes" << " | " << endl;
         }
         else {
            cout << "No" << "  | " << endl;
         }
      }
      else {
         cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
      }
   }

   bool Item::isValid()const {
      return (m_itemName != nullptr && m_price != 0.0);
   }

   double Item::price()const {
      return m_price;
   }
   double Item::tax()const {
      if (!m_taxed) {
         return 0.0;
      }
      else {
         return m_price * m_taxRate;
      }
   }

}