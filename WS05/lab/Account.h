// Name: Brandon An Student Number: 152900197 Email: ban4@myseneca.ca Date: Feb 18 2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>
namespace sdds
{
   class Account
   {
      int m_number;
      double m_balance;
      void setEmpty();

   public:
      Account();
      Account(int number, double balance);
      std::ostream& display() const;

      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator~() const;
      Account& operator=(int number);
      Account& operator=(Account B);
      Account& operator+=(double deposit);
      Account& operator-=(double withdrawal);
      Account& operator<<(Account B);
      Account& operator>>(Account B);
      friend double operator+(const Account& A, const Account& B);
      friend double operator+=(double sum, const Account& A);
   };
   
} // namespace sdds



#endif // SDDS_ACCOUNT_H_