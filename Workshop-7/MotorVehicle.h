#ifndef SDDS_MVEHICLE_H_
#define SDDS_MVEHICLE_H_
#include <iostream>
#define PLATE_LENGTH 9
#define ADDRESS_LENGTH 64
namespace sdds {
   class MotorVehicle {
      char m_license[PLATE_LENGTH] = { '\0' };
      char m_address[ADDRESS_LENGTH] = { '\0' };
      int m_year;
   public:
      MotorVehicle(const char* licence, int year);
      void moveTo(const char* address);
      std::ostream& write(std::ostream& os)const;
      std::istream& read(std::istream& in);
   };
   std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& V1);
   std::istream& operator>>(std::istream& istr, MotorVehicle& V1);
}
#endif // !
