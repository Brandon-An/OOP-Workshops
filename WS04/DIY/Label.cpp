// Name: Brandon An Student Number: 152900197 Email: ban4@myseneca.ca Date: Feb 10 2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
//#include <cstring>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "Label.h"
#include "LabelMaker.h"
using namespace std;
namespace sdds
{
    Label::Label()
    {
        char string[9] = "+-+|+-+|";
        strCpy(m_frame, string);
        m_content = nullptr;
    }

    Label::Label(const char *frameArg)
    {
        strCpy(m_frame, frameArg);
        m_content = nullptr;
    }

    Label::Label(const char *frameArg, const char *content)
    {
        strCpy(m_frame, frameArg);

        m_content = new char[71];
        strCpy(m_content, content);
    }

    Label::~Label()
    {
        delete[] m_content;
    }

    void Label::readLabel()
    {
        char text[71];
        char one;
        std::cout << "> ";
        scanf("%[^\n]%c", text, &one);
        delete[] m_content;
        m_content = new char[71];
        strCpy(m_content, text);

        char string[9] = "+-+|+-+|";
        strCpy(m_frame, string);
    }

    std::ostream &Label::printLabel() const
    {
        if (m_content == nullptr)
        {
            return cout;
        }

        //print top row
        int i;
        std::cout << m_frame[0];
        int length = strLen(m_content);
        for (i = 0; i < length + 2; i++)
        {
            std::cout << m_frame[1];
        }
        std::cout << m_frame[2] << std::endl;

        //print second row
        std::cout << m_frame[7];
        for (i = 0; i < length + 2; i++)
        {
            std::cout << " ";
        }
        std::cout << m_frame[3] << std::endl;

        //print content row (3rd)
        std::cout << m_frame[7];
        std::cout << " " << m_content << " ";
        std::cout << m_frame[3] << std::endl;

        //print fourth row
        std::cout << m_frame[7];
        for (i = 0; i < length + 2; i++)
        {
            std::cout << " ";
        }
        std::cout << m_frame[3] << std::endl;

        //print last row
        std::cout << m_frame[6];
        for (i = 0; i < length + 2; i++)
        {
            std::cout << m_frame[5];
        }
        std::cout << m_frame[4];

        return cout;
    }

} // namespace sdds