#include <iostream>
#include "Truck.h"
using namespace std;

namespace sdds {
   Truck::Truck(const char* license, int year, float capacity, const char* address) : MotorVehicle(license, year) {
      m_cargo = 0;
      m_capacity = capacity;
      MotorVehicle::moveTo(address);
   }
   bool Truck::addCargo(double cargo) {
      bool ret = false;
      if (m_cargo + cargo <= m_capacity) { //check if cargo is added to current load does not exceed capacity
         m_cargo += cargo;
         ret = true;
      }
      else if (m_cargo < m_capacity) {
         double remainder = m_capacity - m_cargo;
         m_cargo += remainder;
         ret = true;
      }
      return ret;
   }
   bool Truck::unloadCargo() {
      bool ret = false;
      if (m_cargo > 0) { //check if cargo is greater than zero before unloading cargo
         m_cargo = 0;
         ret = true;
      }
      return ret;
   }
   std::ostream& Truck::write(std::ostream& os)const {
      MotorVehicle::write(os);
      os << " | " << m_cargo << '/' << m_capacity;
      return os;
   }
   std::istream& Truck::read(std::istream& in) {
      MotorVehicle::read(in);
      cout << "Capacity: ";
      in >> m_capacity;
      if (in.fail()) {
         in.clear();
      }
      cout << "Cargo: ";
      in >> m_cargo;
      if (in.fail()) {
         in.clear();
      }
      return in;
   }

   std::ostream& operator<<(std::ostream& ostr, const Truck& truck) {
      return truck.write(ostr);
   }
   std::istream& operator>>(std::istream& istr, Truck& truck) {
      return truck.read(istr);
   }

}