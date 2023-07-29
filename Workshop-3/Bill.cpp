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
#include "Bill.h"
using namespace std;
namespace sdds {
   double Bill::totalTax()const {
      double taxSum = 0.0;
      for (int i = 0; i < m_noOfItems; i++) {
         taxSum += m_items[i].tax();
      }
      return taxSum;
   }
   double Bill::totalPrice()const {
      double priceSum = 0.0;
      for (int i = 0; i < m_noOfItems; i++) {
         priceSum += m_items[i].price();
      }
      return priceSum;
   }
   void Bill::Title()const {
      cout << "+--------------------------------------+" << endl;
      if (isValid()) {
         cout << "| ";
         cout.width(36);
         cout.setf(ios::left);
         cout << m_title;
         cout.unsetf(ios::left);
         cout << " |" << endl;
      }
      else {
         cout << "| Invalid Bill                         |" << endl;
      }
      cout << "+----------------------+---------+-----+" << endl
         << "| Item Name            | Price   + Tax |" << endl
         << "+----------------------+---------+-----+" << endl;
     
   }
   void Bill::footer()const {
      cout << "+----------------------+---------+-----+" << endl;
      if (isValid()) {
         cout << "|                Total Tax: "; cout.width(10); cout.fill(' '); cout.setf(ios::right); cout.precision(2); cout << totalTax();cout << " |" << endl;
         cout << "|              Total Price: "; cout.width(10); cout.fill(' '); cout.precision(2); cout << totalPrice(); cout << " |" << endl;
         cout << "|          Total After Tax: "; cout.width(10); cout.fill(' '); cout.precision(2); cout << totalTax() + totalPrice(); cout << " |" << endl;
         cout.unsetf(ios::right);
      }
      else {
         cout << "| Invalid Bill                         |" << endl;
      }
      cout << "+--------------------------------------+" << endl;
   }
   void Bill::setEmpty() {
      m_title[0] = '\0';
      m_items = nullptr;
   }
   bool Bill::isValid()const {
      if (m_title != nullptr && m_items != nullptr) {
         int i = 0;
         while (i < m_noOfItems && m_items[i].isValid()) {
            i++;
         }
         if (i == m_noOfItems) {
            return true; 
         }
         else { return false; }
      }
      else { return false; }
   }
   void Bill::init(const char* title, int noOfItems) {
      if (title == nullptr || noOfItems <= 0) {
         setEmpty();
      }
      else {
         m_noOfItems = noOfItems;
         m_items = new Item[m_noOfItems];
         m_itemsAdded = 0;
         strnCpy(m_title, title, 36);
         for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].setEmpty();
         }
      }
   }
   bool Bill::add(const char* item_name, double price, bool taxed) {
      if (m_itemsAdded < m_noOfItems) {
         m_items[m_itemsAdded].set(item_name, price, taxed);
         m_itemsAdded += 1;
         return true;
      }
      else {
         return false;
      }
   }
   void Bill::display()const {
      Title();
      for (int i = 0; i < m_noOfItems; i++) {
         m_items[i].display();
      }
      footer();
   }
   void Bill::deallocate() {
      if (m_items != nullptr) {
         delete[] m_items;
         m_items = nullptr;
      }
   }

}