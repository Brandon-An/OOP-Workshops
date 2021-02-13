#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H
#include "CalorieList.h"
namespace sdds {
    class Food { //first 3 valriables new, all else copied
        char m_foodName[31];
        double m_calorieNumber;
        int m_timeConsumed;  
        void setName(const char* name); //same
    public:
	Food();
        void setEmpty(); //same
        void set(const char* name, double m_calorieNumber, int m_timeConsumed);
        void display()const;
        bool isValid()const; //same except 
        double calories()const; //semantic switch, price to cal
        double time()const; //int instead of bool, 4 states instead of 2
    };
}

#endif
