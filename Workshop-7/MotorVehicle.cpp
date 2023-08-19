#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "MotorVehicle.h"

using namespace std;
namespace sdds {
   MotorVehicle::MotorVehicle(const char* licence, int year) {
      strcpy(m_address, "Factory");
      strcpy(m_license, licence);
      m_year = year;
   }
   void MotorVehicle::moveTo(const char* address) {
      cout << '|'; 
      cout.setf(ios::right); cout.width(8); cout.fill(' '); 
      cout << m_license << "| |";
      cout.width(20);                 //formatted cout
      cout << m_address;
      cout.unsetf(ios::right);
      cout << " ---> ";
      if ((strcmp(address,m_address) != 0)) {
         strcpy(m_address, address);    //move address if different from current address
      }
      cout.setf(ios::left); cout.width(20); cout.fill(' ');
      cout << m_address << '|' << endl; 
      cout.unsetf(ios::left);
   }
   std::ostream& MotorVehicle::write(std::ostream& os)const {  //query to insert content of object into os
      os << "| " << m_year << " | " << m_license << " | " << m_address;
      return os;
   }
   std::istream& MotorVehicle::read(std::istream& in) {  //mutator that reads from in the data for current object
      cout << "Built year: ";
      in >> m_year;              
      if (in.fail()) {         
         in.clear();           
      }
      cout << "License plate: ";
      in >> m_license;
      if (in.fail()) {
         in.clear();
      }
      cout << "Current location: ";
      in >> m_address;
      if (in.fail()) {
         in.clear();
      }
      return in;
   }
   ostream& operator<<(ostream& ostr, const MotorVehicle& motorVehicle) {
      return motorVehicle.write(ostr);
   }
   istream& operator>>(istream& istr, MotorVehicle& motorVehicle) {
      return motorVehicle.read(istr);
   }
}