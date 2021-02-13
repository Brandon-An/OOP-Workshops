#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"
namespace sdds {
    class CalorieList {
        char m_title[37]; //all private copied from Bill.h
        Food* m_items;
        int m_noOfItems;
        int m_itemsAdded;
        double totalCal()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public: //mandatory and new
	CalorieList();
        void init(int size); 
        bool add(const char* item_name, int calories, int when);
        void display()const;
        void deallocate();
    };
}

#endif
