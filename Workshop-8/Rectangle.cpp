#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include "Rectangle.h"
using namespace std;

namespace sdds {
   Rectangle::Rectangle() : LblShape() {
      m_height = 0;
      m_width = 0;
   }
   Rectangle::Rectangle(const char* label, int width, int height) 
      : LblShape(label), m_width(width), m_height(height) {
      if (m_height < 3 || (unsigned int)m_width < strlen(LblShape::label() + 2)) {
         m_width = 0;
         m_height = 0;
      }
   }
   void Rectangle::draw(ostream& os) const {
      if (m_width > 0 && m_height > 0) {
         os << "+";
         for (int i = 0; i < m_width - 2; i++) { os << "-"; }
         os << "+" << endl;
         os << "|" << left << setw(m_width - 2) << label() << "|" << endl;
         for (int j = 0; j < m_height - 3; j++)
         {
            os << "|";
            for (int i = 0; i < m_width - 2; i++) { os << " "; }
            os << "|" << endl;
         }
         os << "+";
         for (int i = 0; i < m_width - 2; i++) { os << "-"; }
         os << "+";
      }
   }
   void Rectangle::getSpecs(istream& is) {
      LblShape::getSpecs(is);
      string str;
      is >> m_width;
      is.ignore();
      is >> m_height;
      is.ignore(100, '\n');
   }
}
