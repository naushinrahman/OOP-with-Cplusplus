#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance;
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      
      operator bool()const;
      operator int()const;
      operator double()const;

      bool operator~()const;
 
      Account& operator=(int i);
      Account& operator=(Account& A);
      Account& operator+=(double d);
      Account& operator-=(double d);
      Account& operator<<(Account& A);
      Account& operator>>(Account& A);
   };

   //helper functions
   double operator+(const Account& L, const Account& R);
   double operator+=(double& d, const Account& A);
}
#endif // SDDS_ACCOUNT_H_