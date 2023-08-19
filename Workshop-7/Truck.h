#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include <iostream>
#include "MotorVehicle.h"
namespace sdds {
   class Truck: public MotorVehicle {
      float m_capacity;
      float m_cargo;
   public:
      Truck(const char* license, int year, float capacity, const char* address);
      bool addCargo(double cargo);
      bool unloadCargo();
      std::ostream& write(std::ostream& os)const;
      std::istream& read(std::istream& in);
   };
   std::ostream& operator<<(std::ostream& ostr, const Truck& truck);
   std::istream& operator>>(std::istream& istr, Truck& truck);
}
#endif
