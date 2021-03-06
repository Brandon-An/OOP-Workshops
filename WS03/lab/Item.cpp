#include <iostream>
#include <iomanip>
#include "cstring.h"
using namespace std;
#include "Item.h"
namespace sdds
{

    void Item::setName(const char *name)
    {
        strnCpy(m_itemName, name, 20);
    }

    void Item::setEmpty()
    {
        m_itemName[0] = '\0';
        m_price = 0.0;
        m_taxed = false;
    }

    void Item::set(const char *name, double price, bool taxed)
    {
        setEmpty();
        setName(name);
        m_price = price;
        m_taxed = taxed;
        if ((price < 0.0) || (m_itemName[0] == '\0'))
        {
            setEmpty();
        }
    }

    double Item::price() const
    {
        return m_price;
    }

    double Item::tax() const
    {
        const double rate = 0.13;
        if (m_taxed == false)
        {
            return 0.0;
        }
        else
        {
            return m_price * rate;
        }
    }

    bool Item::isValid() const
    {
        if (m_itemName[0] != '\0' && m_price != 0.0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Item::display() const
    {
        if (m_itemName[0] != '\0' && m_price != 0.0)
        {
            std::cout << "| ";

            std::cout.width(20);
            //std::cout.fill('.');
            std::cout << std::left << std::setw(20) << std::fixed << m_itemName << " | ";

            std::cout.width(7);
            std::cout << fixed;
            std::cout.precision(2);
            std::cout << std::right << m_price << " | ";

            if (m_taxed == true)
            {
                std::cout << "Yes";
            }
            else
            {
                std::cout << "No ";
            }

            std::cout << " |" << endl;
        }
        else
        {
            std::cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

    

} // namespace sdds