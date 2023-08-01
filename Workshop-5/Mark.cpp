/*/////////////////////////////////////////////////////////////////////////
Workshop - #4 (P2)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "Mark.h"
using namespace std;
namespace sdds {
   
   void Mark::setEmpty() {
      m_mark = 0;
   }

   Mark::Mark() {
      setEmpty();
   }

   Mark::Mark(int i) {
      m_mark = i;
   }

   Mark::operator int() const {
      return (m_mark < 0 || m_mark > 100) ? 0 : m_mark;
   }

   Mark::operator char() const {
      char grade = 'X';
      if (m_mark > 0 && m_mark <= 49) {
         grade = 'F';
      }
      else if (m_mark >= 50 && m_mark <= 59) {
         grade = 'D';
      }
      else if (m_mark >= 60 && m_mark <= 69) {
         grade = 'C';
      }
      else if (m_mark >= 70 && m_mark <= 79) {
         grade = 'B';
      }
      else if (m_mark >= 80 && m_mark <= 100) {
         grade = 'A';
      }
      return grade;
   }

   Mark::operator double() const {
      double gpa = 0.0;
      if (m_mark >= 50 && m_mark <= 59) {
         gpa = 1.0;
      }
      else if (m_mark >= 60 && m_mark <= 69) {
         gpa = 2.0;
      }
      else if (m_mark >= 70 && m_mark <= 79) {
         gpa = 3.0;
      }
      else if (m_mark >= 80 && m_mark <= 100) {
         gpa = 4.0;
      }
      return gpa;
   }

   int& operator+=(int& i, const Mark& M) {
      if ((int(M)) <= 100 && (int(M)) >= 0) {
         i += int(M);
      }
      return i;
   }

   Mark& Mark::operator+=(int i) {
      if ((i+ m_mark) >= 0 && (i + m_mark) <= 100) {
         m_mark += i;
      }
      else {
         setEmpty();
      }
      return *this;
   }

   Mark& Mark::operator=(int i) {
      setEmpty();
      m_mark = i;
      return *this;
   }

}