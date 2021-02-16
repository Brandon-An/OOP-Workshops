// Name: Brandon An Student Number: 152900197 Email: ban4@myseneca.ca Date: Feb 18 2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds
{
   void Account::setEmpty() // Invalid Account
   {
      m_number = -1;
      m_balance = 0.0;
   }

   Account::Account() // New Account
   { 
      m_number = 0;
      m_balance = 0.0;
   }

   Account::Account(int number, double balance) //Valid Account
   {
      setEmpty();
      if (number >= 10000 && number <= 99999 && balance > 0)
      {
         m_number = number;
         m_balance = balance;
      }
   }
      
   Account::operator bool() const 
   { 
      return m_number != -1; 
   }

   Account::operator int() const
   {
      return m_number;
   }

   Account::operator double() const
   {
      return m_balance;
   }

   bool Account::operator~() const
   {
      if (m_number == 0)
      {
         return true;
      }
      return false;
   }

   Account& Account::operator=(int number)
   {
      if (~*this)
      {
         if (number <= 10000 || number >= 99999)
         {
            setEmpty();
            return *this;
         }
         m_number = number;
         return *this;
      }
      return *this;
   }

   Account& Account::operator=(Account B)
   {
      if (m_number == 0 && B.m_number >= 0)
      {
         m_number = B.m_number;
         m_balance = B.m_balance;
         B.m_number = 0;
         return *this;
      }
      return *this;
   }

   Account& Account::operator+=(double deposit)
   {
      if (m_number >= 0 && deposit >= 0)
      {
         m_balance += deposit;
         return *this;
      }
      return *this;
   }

   Account& Account::operator-=(double withdrawal)
   {
      if (m_number >= 0 && withdrawal >= 0 && m_balance >= withdrawal)
      {
         m_balance -= withdrawal;
         return *this;
      }
      return *this;
   }

   Account& Account::operator<<(Account B)
   {
      m_balance += B.m_balance;
      B.m_balance = 0;
      return *this;
   }

   Account& Account::operator>>(Account B)
   {
      B.m_balance += m_balance;
      m_balance = 0;
      return *this;
   }

   double operator+(const Account& A, const Account& B)
   {
      if (A.m_balance < 0 || B.m_balance < 0)
      {
         return 0;
      }
      else
      {
         double sum;
         sum = A.m_balance + B.m_balance;
         return sum;
      }

   } 

   double operator+=(double sum, const Account& A)
   {
      sum += A.m_balance;
      return sum; 
   }

   std::ostream& Account::display() const
   {
      if (*this)
      {
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
      else if (~*this)
      {
         cout << "  NEW  |         0.00 ";
      }
      else
      {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

} // namespace sdds