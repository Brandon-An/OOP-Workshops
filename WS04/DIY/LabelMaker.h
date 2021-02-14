// Name: Brandon An Student Number: 152900197 Email: ban4@myseneca.ca Date: Feb 10 2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"
namespace sdds
{
    class LabelMaker
    {
        Label *totalLabel;
        int numLabels;
    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
} //namespace sdds
#endif
