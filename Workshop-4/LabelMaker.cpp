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
#include "LabelMaker.h"
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {
   LabelMaker::LabelMaker() {
      m_labels = nullptr;
   }

   LabelMaker::LabelMaker(int noOfLabels) {
      if (noOfLabels > 0) {
         m_noOfLabels = noOfLabels;
         m_labels = new Label[m_noOfLabels];
      }
   }

   void LabelMaker::readLabels() {
      cout << "Enter " << m_noOfLabels << " labels:" << endl;
      for (int i = 0; i < m_noOfLabels; i++) {
         cout << "Enter label number " << i + 1 << endl;
         cout << "> ";
         m_labels[i].readLabel();
      }
   }

   void LabelMaker::printLabels()const {
      for (int i = 0; i < m_noOfLabels; i++) {
         m_labels[i].printLabel();
         cout << endl;
      }
   }

   void LabelMaker::setEmpty() {
      m_labels = nullptr;
   }

   LabelMaker::~LabelMaker() {
      if (m_labels != nullptr) {
         delete[] m_labels;
         m_labels = nullptr;
      }
   }
}