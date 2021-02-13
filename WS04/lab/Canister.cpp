// Name: Brandon An Student Number: 152900197 Email: ban4@myseneca.ca Date: Feb 10 2021
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
//#include <cstring>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "Canister.h"
using namespace std;
namespace sdds
{
    double PI = 3.14159265;

    void Canister::setToDefault()
    {
        m_contentName = nullptr;
        m_diameter = 10.0;
        m_height = 13.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    bool Canister::isEmpty() const
    {
        if (m_contentVolume < 0.00001)
            return true;
        return false;
    }

    bool Canister::hasSameContent(const Canister &C) const
    {
        int isSame;
        isSame = strCmp(C.m_contentName, m_contentName);
        if (isSame == 0)
            return true;
        return false;
    }

    void Canister::setName(const char *Cstr)
    {
        if (Cstr != nullptr && m_usable == true)
        {
            int length = strLen(Cstr);
            delete[] m_contentName;
            m_contentName = new char[length + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    void Canister::clear()
    {
        delete[] m_contentName;;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    double Canister::volume() const
    {
        return m_contentVolume;
    }

    double Canister::capacity() const
    {
        double H = m_height;
        double D = m_diameter;
        double Capacity = PI * (H - 0.267) * (D / 2) * (D / 2);
        return Capacity;
    }

    Canister::Canister()
    {
        setToDefault();
    }

    Canister::Canister(const char *contentName)
    {
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double height, double diameter, const char *contentName)
    {
        setToDefault();
        m_height = height;
        m_diameter = diameter;
        setName(contentName);
        if (height < 10 || diameter < 10 || height > 40 || diameter > 30)
        {
            setToDefault();
            m_usable = false;
        }
    }

    Canister::~Canister()
    {
        delete[] m_contentName;
    }

    Canister &Canister::setContent(const char *contentName)
    {
        if (contentName == nullptr)
        {
            m_usable = false;
        }

        if (isEmpty())
        {
            setName(contentName);
        }

        if (!hasSameContent(contentName))
        {
            m_usable = false;
        }

        return *this;
    }

    Canister &Canister::pour(double quantity)
    {
        double sum = quantity + volume();
        double cap = capacity();

        if (m_usable && quantity > 0.0 && sum <= cap)
        {
            m_contentVolume += quantity;
        }
        else
        {
            m_usable = false;
        }
        return *this;
    }

    Canister &Canister::pour(Canister &source)
    {
        setContent(source.m_contentName);
        double freeSpace = capacity() - volume();
        if (source.volume() > freeSpace)
        {
            source.m_contentVolume -= capacity() - volume();
            m_contentVolume = capacity();
        }
        else
        {
            pour(source.m_contentVolume);
            source.m_contentVolume = 0.0;
        }

        return *this;
    }

    std::ostream &Canister::display() const
    {
        std::cout.width(7);
        std::cout << std::setprecision(1) << std::fixed;
        std::cout << capacity() << "cc (";

        std::cout.width(0);
        std::cout << std::setprecision(1) << std::fixed;
        std::cout << m_height;

        std::cout << "x";
        std::cout << std::setprecision(1) << std::fixed;
        std::cout << m_diameter;

        std::cout << ") Canister";

        if (!m_usable)
        {
            std::cout << " of Unusable content, discard!";
        }
        if (m_contentName != nullptr && m_usable)
        {
            std::cout << " of ";
            std::cout.width(7);
            std::cout << m_contentVolume;
            std::cout.width(0);
            std::cout << "cc   ";
            std::cout << m_contentName;
        }
        return cout;
    }

} // namespace sdds