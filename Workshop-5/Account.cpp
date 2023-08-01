#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const {
      if (*this) {
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if (~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool()const {
      return (m_number > 9999 && m_number < 100000 && m_balance >= 0 ? true : false);
   }

   Account::operator int()const {
      return m_number;
   }

   Account::operator double()const {
      return m_balance;
   }

   bool Account::operator~()const {
      return (m_number == 0 ? true : false);
   }

   Account& Account::operator=(int i) {
      if (m_number == 0) {
         m_number = i;
      }
      else if (i <= 9999 || i >= 100000) {
         setEmpty();
      }
      return *this;
   }

   Account& Account::operator=(Account& A) {
      if (this->m_number == 0 && A) {
         m_number = A.m_number; 
         m_balance = A.m_balance;
         A.m_number = 0;
         A.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator+=(double d) {
      if (*this && d >= 0) {
         m_balance += d;
      }
      return *this;
   }

   Account& Account::operator-=(double d) {
      if (*this && d >= 0 && ((this->m_balance - d)>=0)) {
         m_balance -= d;
      }
      return *this;
   }

   Account& Account::operator<<(Account& A) {
      if (*this && A && this->m_balance != A.m_balance) {
         m_balance += A.m_balance;
         A.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& A) {
      if (*this && A && this->m_balance != A.m_balance) {
         A.m_balance += m_balance;
         this->m_balance = 0;
      }
      return *this;
   }

   double operator+(const Account& L, const Account& R) {
      double sum = 0.0;
      if (L && R) {
         sum = (double)L + (double)R;
      }
      return sum;
   }

   double operator+=(double& d, const Account& A) {
      if (A) {
         d += (double)A;
      }
      return d;
   }
}