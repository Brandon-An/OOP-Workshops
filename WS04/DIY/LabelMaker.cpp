// Name: Brandon An Student Number: 152900197 Email: ban4@myseneca.ca Date: Feb 10 2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
//#include <cstring>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "LabelMaker.h"
#include "Label.h"
using namespace std;
namespace sdds
{
   LabelMaker::LabelMaker(int noOfLabels)
   {
       totalLabel = new Label[noOfLabels];
       numLabels = noOfLabels;
   }
   
   void LabelMaker::readLabels()
    {
        int i;
        std::cout << "Enter " << numLabels << " labels:" << std::endl;
        for (i = 0; i < numLabels; i++)
        {
            std::cout << "Enter label number " << i + 1 << std::endl;
            totalLabel[i].readLabel();
        }
    }

    void LabelMaker::printLabels()
    {
        for (int i = 0; i < numLabels; i++)
        {
            totalLabel[i].printLabel();
            std::cout << std::endl;
        }
    }

    LabelMaker::~LabelMaker()
    {
         delete [] totalLabel;
         totalLabel = nullptr;
    }

} // namespace sdds
