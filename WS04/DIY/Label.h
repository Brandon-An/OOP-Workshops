// Name: Brandon An Student Number: 152900197 Email: ban4@myseneca.ca Date: Feb 10 2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
namespace sdds
{
    class Label
    {
        char *m_content;
        char m_frame[9];

    public:
        Label();
        Label(const char *frameArg);
        Label(const char *frameArg, const char *content);
        ~Label();
        void readLabel();
        std::ostream& printLabel() const;
    };
} // namespace sdds
#endif