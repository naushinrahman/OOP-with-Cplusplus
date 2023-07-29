/*/////////////////////////////////////////////////////////////////////////
Workshop - #3 (P2)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {
   //to access the calorie sum so it can be displayed in the footer
   int CalorieList::calSum()const {  
      int sum = 0;
      for (int i = 0; i < m_numOfFoods; i++) {
         sum += m_food[i].calories();
      }
      return sum;
   }

   void CalorieList::header()const {
      cout << "+----------------------------------------------------+" << endl;
      if (isValid()) {
         cout << "|  Daily Calorie Consumption                         |" << endl;
      }
      else {
         cout << "| Invalid Calorie Consumption list                   |" << endl;
      }
      cout << "+--------------------------------+------+------------+" << endl;
      cout << "| "; cout.width(30); cout.fill(' '); cout.setf(ios::left); cout << "Food name";
      cout << " | "; cout.width(4); cout.fill(' '); cout << "Cals";
      cout << " | "; cout.width(10); cout.fill(' '); cout << "When"; cout.unsetf(ios::left);
      cout << " |" << endl;
      cout << "+--------------------------------+------+------------+" << endl;
   }

   void CalorieList::footer()const {
      cout << "+--------------------------------+------+------------+" << endl;
      if (isValid()) {
         cout << "|    Total Calories for today:   ";
         cout.setf(ios::right); cout.width(6); cout.fill(' '); cout << calSum(); cout.unsetf(ios::right); cout << " |            |" << endl;
      }
      else {
         cout << "|    Invalid Calorie Consumption list                |" << endl;
      }
      cout << "+----------------------------------------------------+" << endl;
   }

   void CalorieList::setEmpty() {
      m_food = nullptr;
   }
   //check if each member of the food pointer is valid by accessing the isValid function in the Food class and iterating through it
   bool CalorieList::isValid()const {
      if (m_numOfFoods > 0 && m_food != nullptr) {
         int i = 0;
         // if both condition are true i is incremented
         while (i < m_numOfFoods && m_food[i].isValid()) {
            i++;
         }
         // if all are true i should be the same as m_numOfFoods and return true so valid header and footer are displayed
         // if even one is not valid you get the invalid header and footer instead
         if (i == m_numOfFoods) {
            return true;
         }
         else { return false; }
      }
      else { return false; }
      
   }
   // sets the CalorieList to accept the "size" number of Food Items. 
   // This function is called to prepare the CalorieList for accepting food items
   void CalorieList::init(int size) {
      if (size < 0) {
         setEmpty();
      }
      else {
         // dynamically allocating memory depending on how many values are initialized
         m_numOfFoods = size;
         m_food = new Food[m_numOfFoods];
         for (int i = 0; i < m_numOfFoods; i++) {
            m_food[i].setEmpty();
         }
         m_foodsadded = 0;
      }
   }
   // Adds Food Items using their Name, Calorie count and time of consumption up to 
   // the number set in the init() function, returns true if successful.
   bool CalorieList::add(const char* item_name, int calories, int time) {
      if (m_foodsadded < m_numOfFoods) {
         m_food[m_foodsadded].set(item_name, calories, time);
         m_foodsadded += 1;
         return true;
      }
      else {
         return false;
      }
   }
   // Displays the report with food information and the total calorie consumed in the day
   // as shown in the report sample
   void CalorieList::display()const {
      header();
      for (int i = 0; i < m_numOfFoods; i++) {
         m_food[i].display();
      }
      footer();
   }
   // Releases all the memory used. After this function init() can be called for another
   // report;
   void CalorieList::deallocate() {
      if (m_food != nullptr) {
         delete[] m_food;
         m_food = nullptr;
      }
   }
}