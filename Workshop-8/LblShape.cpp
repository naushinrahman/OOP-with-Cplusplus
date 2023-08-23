#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"
using namespace std;

namespace sdds {
   const char* LblShape::label()const {
      return m_label;
   }
   LblShape::LblShape() {
      m_label = nullptr;
   }
   LblShape::LblShape(const char* label) {
      if (label != nullptr) {
         m_label = new char[strlen(label) + 1];
         strcpy(m_label, label);
      }
   }
   LblShape::~LblShape() {
      delete[] m_label;
   }
   void LblShape::getSpecs(std::istream& is) {
      if (m_label != nullptr) {
         delete[] m_label;
      }
      char label[100];
      is.getline(label, 100, ',');
      m_label = new char[strlen(label) + 1];
      strcpy(m_label, label);
   }
}
