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
#include "Food.h"
#include "cstring.h"

using namespace std;
namespace sdds {
   // returns calories needed to sum calories later
   int Food::calories()const {         
      return m_calories;
   }

   //set food module to safe empty state
   void Food::setEmpty() {
      m_foodName[0] = '\0';          
      m_calories = 0;
      m_time = 0;
   }

   // ensure calories and time of consumption are valid values before setting
   void Food::set(const char* name, int calories, int time) {  
      if (name == nullptr || (time <= 0 || time >= 5) || (m_calories < 0 || m_calories > 3000)) {
         setEmpty();
      }
      else {
         strnCpy(m_foodName, name, 30);                     
         m_calories = calories;
         m_time = time;
      }
   }

   //prints out item name formatted 
   void Food::display()const {
      if (isValid()) {     
         cout << "| "; cout.width(30); cout.fill('.'); cout.setf(ios::left); cout << m_foodName; cout.unsetf(ios::left);
         cout << " |"; cout.width(5); cout.fill(' '); cout.setf(ios::right); cout << m_calories; cout.unsetf(ios::right);
         cout << " | "; cout.width(10); cout.fill(' '); cout.setf(ios::left);
         switch (m_time) {
         case 1:
            cout << "Breakfast";
            break;
         case 2:
            cout << "Lunch";
            break;
         case 3:
            cout << "Dinner";
            break;
         case 4:
            cout << "Snack";
            break;
         }
         cout.unsetf(ios::left);
         cout << " |" << endl;
      }
      else {
         cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
      }
   }

   // checking if foodName is nullptr, calories is between 0-3000 inclusive and time is between 1-4 and only returning true if all conditions are true
   bool Food::isValid()const {
      if (m_foodName != nullptr && (!(m_calories < 0 || m_calories > 3000)) && (!(m_time <= 0 || m_time >= 5))) {
         return true;
      }
      else {
         return false;
      }
   }
}

