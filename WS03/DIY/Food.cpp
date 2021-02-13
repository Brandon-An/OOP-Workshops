#include <iostream>
#include <iomanip>
using namespace std;
#include "cstring.h"
#include "CalorieList.h"
#include "Food.h"
namespace sdds
{

    Food::Food(){
        setEmpty();
    }

    void Food::setName(const char *name)
    {
        strnCpy(m_foodName, name, 30);
    }

    void Food::setEmpty()
    {
        m_foodName[0] = '\0';
        m_calorieNumber = 0.0;
        m_timeConsumed = 0;
    }

    void Food::set(const char *name, double calories, int time)
    {
        setEmpty();
        setName(name);
        m_calorieNumber = calories;
        m_timeConsumed = time;
        if ((calories < 0.0) || (m_foodName[0] == '\0') || m_timeConsumed < 1 || m_timeConsumed > 4)
        {
            setEmpty();
        }
    }

    double Food::calories() const
    {
        return m_calorieNumber;
    }

    bool Food::isValid() const
    {
        if (m_foodName[0] != '\0' && m_calorieNumber != 0.0 && m_timeConsumed > 0 && m_timeConsumed < 5)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Food::display() const
    {
        if (m_foodName[0] != '\0' && m_calorieNumber != 0.0)
        {
            std::cout << "| ";

            std::cout.fill('.');
            std::cout << std::left << std::setw(30) << std::fixed << m_foodName << " | ";

            std::cout.fill(' ');
            std::cout.width(4);
            std::cout << fixed;
            std::cout.precision(0);
            std::cout << std::right << m_calorieNumber << " | ";

            switch (m_timeConsumed)
            {
            case 1:
                std::cout << std::left << std::setw(10) << "Breakfast" << " |" << endl;
                break;
            case 2:
                std::cout << std::left << std::setw(10) << "Lunch" << " |" << endl;
                break;
            case 3:
                std::cout << std::left << std::setw(10) << "Dinner" << " |" << endl;
                break;
            case 4:
                std::cout << std::left << std::setw(10) << "Snack" << " |" << endl;
                break;
            }

        }
        else
        {
            std::cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }

} // namespace sdds
