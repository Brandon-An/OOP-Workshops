#include <iostream>
#include <iomanip>
#include "cstring.h"
using namespace std;
#include "Bill.h"
#include "Item.h"
namespace sdds
{

    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid() const
    {
        int i;
        if (m_title[0] != '\0' && m_items != nullptr)
        {
            for (i = 0; i < m_itemsAdded; i++)
            {
                bool yesno;
                yesno = m_items[i].isValid();
                if (yesno == false)
                    return yesno;
            }
        }
        return true;
    }

    double Bill::totalTax() const
    {
        int i = 0;
        double totalTaxes = 0;
        for (i = 0; i < m_itemsAdded; i++)
        {
            totalTaxes += m_items[i].tax();
        }
        return totalTaxes;
    }

    double Bill::totalPrice() const
    {
        int i = 0;
        double totalPrice = 0;
        for (i = 0; i < m_itemsAdded; i++)
        {
            totalPrice += m_items[i].price();
        }
        return totalPrice;
    }

    void Bill::Title() const
    {
        std::cout << "+--------------------------------------+" << endl;

        if (m_title[0] != '\0' && isValid())
        {
            std::cout << "| ";
            std::cout.width(36);
            std::cout << std::left << m_title; 
            std::cout << " |" << std::endl;
        }
        else
        {
            std::cout << "| Invalid Bill                         |" << endl;
        }

        std::cout << "+----------------------+---------+-----+" << endl;
        std::cout << "| Item Name            | Price   + Tax |" << endl;
        std::cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        std::cout << "+----------------------+---------+-----+" << endl;

        if (m_title[0] != '\0' && isValid())
        {
            std::cout << "|                Total Tax: ";
            std::cout.width(10);
            std::setprecision(3);
            std::cout << std::right << totalTax() << " |" << endl;

            std::cout << "|              Total Price: ";
            std::cout.width(10);
            std::setprecision(3);
            std::cout << std::right << totalPrice() << " |" << endl;

            std::cout << "|          Total After Tax: ";
            std::cout.width(10);
            std::setprecision(3);
            std::cout << std::right << totalTax() + totalPrice() << " |" << endl;
        }
        else
        {
            std::cout << "| Invalid Bill                         |" << endl;
        }

        std::cout << "+--------------------------------------+" << endl;
    }

    void Bill::init(const char *title, int noOfItems)
    {
        if (title[0] != '\0' && noOfItems > 0)
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strCpy(m_title, title);
            m_items = new Item[m_noOfItems];
        }
        else
        {
            m_title[0] = '\0';
            m_noOfItems = 0;
        }
    }

    bool Bill::add(const char *item_name, double price, bool taxed)
    {
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        return false;
    }

    void Bill::display() const
    {
        int i = 0;
        Title();
        for (i = 0; i < m_itemsAdded; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate()
    {
        int i;
        for (i = 0; i < m_noOfItems; i++)
        {
            m_items[i].setEmpty();
        }
        m_items = nullptr;
    }

} // namespace sdds