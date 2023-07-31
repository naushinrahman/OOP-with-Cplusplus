/*/////////////////////////////////////////////////////////////////////////
Workshop - #4 (P1)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include <cstring>
#include "Canister.h"
using namespace std;
namespace sdds {
   const double pi = 3.14159265;

   void Canister::setToDefault() {
      m_contentName = nullptr;
      m_height = 13.0;
      m_diameter = 10.0;
      m_contentVolume = 0.0;
      m_usable = true;
   }

   void Canister::setName(const char* Cstr) {
      if (isEmpty() && Cstr != nullptr) {
         delete[] m_contentName;
         m_contentName = new char[strlen(Cstr) + 1]; //deallocate later
         strcpy(m_contentName, Cstr);
      }
   }

   bool Canister::isEmpty()const {
      bool ret = false;
      if (m_contentVolume < 0.00001) {
         ret = true;
      }
      return ret;
   }
   
   bool Canister::hasSameContent(const Canister& C)const {
      bool ret = false;
      if (m_contentName != nullptr && C.m_contentName != nullptr && (strcmp(m_contentName, C.m_contentName)==0)) {
         ret = true;
      }
      return ret;
   }

   Canister::Canister() {
      setToDefault();
   }

   Canister::Canister(const char* contentName) {
      setToDefault();
      setName(contentName);
   }

   Canister::Canister(double height, double diameter,
      const char* contentName) {
      setToDefault();
      if (height >= 10 && height <= 40 && diameter >= 10 && diameter <= 30) {
         setName(contentName);
         m_height = height;
         m_diameter = diameter;
      }
      else {
         m_usable = false;
      }
   }

   Canister::~Canister() {
      if (m_contentName != nullptr) {
         delete[] m_contentName;
         m_contentName = nullptr;
      }
   }
  
   Canister& Canister::setContent(const char* contentName) {
      if (contentName == nullptr) {
         m_usable = false;
      }
      else if (isEmpty()) {
         setName(contentName);
      }
      else if (strcmp(m_contentName, contentName) != 0) {
         m_usable = false;
      }
      return *this;
   }

   Canister& Canister::pour(double quantity) {
      if (quantity > 0 && m_usable && ((quantity + m_contentVolume) <= capacity())) {
         m_contentVolume += quantity;
      }
      else {
         m_usable = false;
      }
      return *this;
   }

   Canister& Canister::pour(Canister& C) {
      setContent(C.m_contentName);
      if (C.volume() > (capacity() - volume())) {
         C.m_contentVolume -= (capacity() - volume());
         m_contentVolume = capacity();
      }
      else {
         pour(C.m_contentVolume);
         C.m_contentVolume = 0.0;
      }
      return *this;
   }

   double Canister::volume()const {
      return m_contentVolume;
   }

   std::ostream& Canister::display()const {
      cout.width(7); cout.fill(' '); cout.setf(ios::fixed);  cout.precision(1); cout << capacity();
      cout << "cc ("; cout << m_height; cout << "x"; cout << m_diameter; cout << ") Canister";
      if (m_usable == false) {
         cout << " of Unusable content, discard!";
      }
      else if (m_contentName != nullptr) {
         cout << " of "; cout.width(7); cout.fill(' '); cout << m_contentVolume;
         cout << "cc   "; cout << m_contentName;
      }
      return cout;
   }

   double Canister::capacity()const {
      // Capacity = PI x(H - 0.267) x(D / 2) x(D / 2)
      return (pi * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2));
   }

   void Canister::clear() {
      if (m_contentName != nullptr) {
         delete[] m_contentName;
         m_contentName = nullptr;
      }
      m_contentVolume = 0.0;
      m_usable = true;
   }

}