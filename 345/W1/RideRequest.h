/*/////////////////////////////////////////////////////////////////////////
Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NCC

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

#include <iostream>

extern double g_discount;
extern double g_taxrate;

namespace sdds {

   class RideRequest {
      char* m_custName;
      char* m_rideDesc;
      double m_price;
      bool m_discount;
   public:
      RideRequest();
      RideRequest(const RideRequest& cpy);
      RideRequest& operator=(const RideRequest& rhs);
      ~RideRequest();
      void read(std::istream& is);
      void display() const;
   };

}

#endif
