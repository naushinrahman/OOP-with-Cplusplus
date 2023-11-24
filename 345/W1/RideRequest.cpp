/*/////////////////////////////////////////////////////////////////////////
Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NCC

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "RideRequest.h"

using namespace std;

double g_discount = 0.0;
double g_taxrate = 0.0;

namespace sdds {
   RideRequest::RideRequest() {
      m_discount = false;
      m_price = 0.0;
      m_custName = nullptr;
      m_rideDesc = nullptr;
   }
   RideRequest& RideRequest::operator=(const RideRequest& rhs) {
      if (this != &rhs) {
         m_discount = rhs.m_discount;
         m_price = rhs.m_price;
         if (rhs.m_custName != nullptr && rhs.m_rideDesc != nullptr) {
            delete[] m_custName;
            delete m_rideDesc;
            int len = strlen(rhs.m_custName);
            m_custName = new char[len + 1];
            strcpy(m_custName, rhs.m_custName);
            len = strlen(rhs.m_rideDesc);
            m_rideDesc = new char[len + 1];
            strcpy(m_rideDesc, rhs.m_rideDesc);
         }
         else {
            m_custName = nullptr;
            m_rideDesc = nullptr;
         }
      }
      return *this;
   }
   RideRequest::RideRequest(const RideRequest& cpy) {
      if (cpy.m_custName != nullptr && cpy.m_rideDesc != nullptr) {
         m_discount = cpy.m_discount;
         m_price = cpy.m_price;
         m_custName = nullptr;
         m_rideDesc = nullptr;
         delete m_custName;
         delete m_rideDesc;
         int len = strlen(cpy.m_custName);
         m_custName = new char[len + 1];
         strcpy(m_custName, cpy.m_custName);
         len = strlen(cpy.m_rideDesc);
         m_rideDesc = new char[len + 1];
         strcpy(m_rideDesc, cpy.m_rideDesc);
      }
      else {
         m_custName = nullptr;
         m_rideDesc = nullptr;
      }
   }
   void RideRequest::read(istream& is) {
      if (is) {
         double rate = 0.0;
         char tempDiscount = '\0';
         string tempName;
         string tempRide;
         getline(is, tempName, ',');
         getline(is, tempRide, ',');
         if (m_custName != nullptr) {
            delete[] m_custName;
         }
         if (m_rideDesc != nullptr) {
            delete[] m_rideDesc;
         }
         m_custName = new char[tempName.length() + 1];
         strcpy(m_custName, tempName.c_str());
         m_rideDesc = new char[tempRide.length() + 1];
         strcpy(m_rideDesc, tempRide.c_str());
         is >> rate;
         m_price = rate;
         is.ignore();
         is.get(tempDiscount);
         if (tempDiscount == 'Y') {
            m_discount = true;
         }
         else {
            m_discount = false;
         }
      }
   }
   RideRequest::~RideRequest() {
      if (m_custName != nullptr) {
         delete[] m_custName;
         m_custName = nullptr;
      }
      if (m_rideDesc != nullptr) {
         delete[] m_rideDesc;
         m_rideDesc = nullptr;
      }
   }
   void RideRequest::display() const {
      static int i = 1;
      double taxPrice = ((m_price * g_taxrate) + m_price);
      double discountPrice = (taxPrice - g_discount);
      cout << left<< setw(2); cout << i << ". ";
      if (m_custName[0] == '\0') {
         cout << "No Ride Request\n";
      }
      else {
      cout << left << setw(10); cout << m_custName << "|";
      cout << left << setw(25); cout << m_rideDesc << "|";
      cout << left << setw(12) << fixed << setprecision(2) << taxPrice << "|";
         if (m_discount) {
            cout << right << setw(13) << setprecision(2) << discountPrice << "\n";
         }
         else {
            cout << "\n";
         }
      }
      i++;
   }

}
