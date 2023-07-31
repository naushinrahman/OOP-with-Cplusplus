/*/////////////////////////////////////////////////////////////////////////
Workshop - #4 (P2)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Label.h"
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {
   const int macChar = 70;
   void Label::readLabel() {
      char input[70];
      cin.getline(input, 70);
      if (m_content != nullptr) {
         delete[] m_content;
         m_content = nullptr;
      }
      m_content = new char[strlen(input) + 1];
      strcpy(m_content, input);
   }
   
   void Label::setToDefault() {      
      m_content = nullptr;
   }

   Label::Label() {
      strncpy(m_frame, "+-+|+-+|", 8);
      m_frame[8] = '\0';
      m_content = nullptr;
   }

   Label::Label(const char* frameArg) {
      if (frameArg != nullptr) {
         strncpy(m_frame, frameArg, 8);
         m_frame[8] = '\0';
         setToDefault();
      }
   }

   Label::Label(const char* frameArg, const char* content) {
      if (frameArg != nullptr && content != nullptr) {
         strcpy(m_frame, frameArg);
         m_content = new char[strlen(content) + 1];
         strcpy(m_content, content);
      }
      else {
         setToDefault();
      }
   }

   Label::~Label() {
      if (m_content != nullptr){
         delete[] m_content;
         m_content = nullptr;
      }
   }


   std::ostream& Label::printLabel()const {
      if (m_content != nullptr) {
         cout << m_frame[0] << setw(strlen(m_content) + 3) << setfill(m_frame[1]) << m_frame[2] << endl;
         cout << m_frame[7] << setw(strlen(m_content) + 3) << setfill(' ') << m_frame[3] << endl;
         cout << m_frame[7] << ' ' << m_content << ' ' << m_frame[3] << endl;
         cout << m_frame[7] << setw(strlen(m_content) + 3) << setfill(' ') << m_frame[3] << endl;
         cout << m_frame[6] << setw(strlen(m_content) + 3) << setfill(m_frame[5]) << m_frame[4];
      }
      return cout;
   }
}