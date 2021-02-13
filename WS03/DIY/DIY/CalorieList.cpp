#include <iostream>
#include <iomanip>
using namespace std;
#include "cstring.h"
#include "CalorieList.h"
#include "Food.h"
namespace sdds{

    CalorieList::CalorieList(){
	setEmpty();
    }	

    void CalorieList::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
	m_noOfItems = 0;
	m_itemsAdded = 0;
    }

    bool CalorieList::isValid() const
    {
        int i;
        if (m_items != nullptr)
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

    double CalorieList::totalCal() const
    {
        int i = 0;
        double totalCalories = 0;
        for (i = 0; i < m_itemsAdded; i++)
        {
            totalCalories += m_items[i].calories();
        }
        return totalCalories;
    }

    void CalorieList::Title() const
    {
        std::cout << "+----------------------------------------------------+" << endl;

        if (m_itemsAdded == m_noOfItems && isValid())
        {
            std::cout << "|  Daily Calorie Consumption                         |" << std::endl;
        }
        else
        {
            std::cout << "| Invalid Calorie Consumption list                   |" << endl;
        }

        std::cout << "+--------------------------------+------+------------+" << endl;
        std::cout << "| Food name                      | Cals | When       |" << endl;
        std::cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer() const
    {
        std::cout << "+--------------------------------+------+------------+" << endl;

        if (m_itemsAdded == m_noOfItems && isValid())
        {
            std::cout << "|    Total Calories for today: ";
            std::cout.width(8);
            std::setprecision(3);
            std::cout << std::right << totalCal() << " |" << "            |" << endl;
        }
        else
        {
            std::cout << "|    Invalid Calorie Consumption list                |" << endl;
        }

        std::cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::init(int size)
    {
	setEmpty();
	int quantity = size;
        if (quantity > 0)
        {
            m_noOfItems = quantity;
            m_itemsAdded = 0;
            m_items = new Food[m_noOfItems];
        }
        else
        {
            m_noOfItems = 0;
        }
    }

    bool CalorieList::add(const char *item_name, int calories, int when)
    {
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, calories, when);
            m_itemsAdded++;
            return true;
        }
        return false;
    }

    void CalorieList::display() const
    {
        int i = 0;
        Title();
        for (i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    void CalorieList::deallocate()
    {
	delete [] m_items;
        m_items = nullptr;
    }

}
