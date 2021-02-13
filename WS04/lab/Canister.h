// Name: Brandon An Student Number: 152900197 Email: ban4@myseneca.ca Date: Feb 10 2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds {
   class Canister {
      char* m_contentName;
      double m_diameter; // in centimeters 
      double m_height;   // in centimeters
      double m_contentVolume;  // in CCs
      bool m_usable;
      void setToDefault();
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;
      void setName(const char* Cstr);
   public:
      void clear();
      double volume()const;
      double capacity()const;
      Canister();
      Canister(const char* contentName);
      Canister(double height, double diameter, const char* contentName = nullptr);
      ~Canister(); //95 in imp
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister&);
      std::ostream& display()const;
   };
}

#endif // !SDDS_BOX_H
