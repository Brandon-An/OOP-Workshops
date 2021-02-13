#include "Population.h"
#include "File.h"
#include "cstring.h"
#include <iostream>

using namespace std;
namespace sdds
{

    int noOfPlaces;
    int noOfPeople;
    Postal *post;

    void sort()
    {
        int i, j;
        Postal temp;
        for (i = noOfPlaces - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (post[j].noPeople > post[j + 1].noPeople)
                {
                    temp = post[j];
                    post[j] = post[j + 1];
                    post[j + 1] = temp;
                }
            }
        }
    }

    bool load(Postal *pos)
    {
        int number = 0;
        bool r1, r2;

        char *string = new char[4];
        r1 = read(string);
//        string[4] = '\0';
        pos->postCode = string;
        
        r2 = read(number);
        pos->noPeople = number;
        noOfPeople += number;

        if (r1 && r2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool load(const char filename[])
    {
        int i, j;
        bool ok = false;

        if (openFile("PCpopulationsComplete.csv"))
        {
            j = noOfRecords();
            noOfPlaces = j;
            Postal *pos = new Postal[j];
            post = pos;
            for (i = 0; i <= j - 1; i++)
            {
                load(&(pos[i]));
            }

            if (i != noOfPlaces)
            {
                std::cout << "Error: incorrect number of records read; the data is possibly corrupted.";
                closeFile();
            }
            else
            {
                ok = true;
            }
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }

        return ok;
    }

    void display()
    {
        int i;
        sort();
        std::cout << "Postal Code: population" << endl;
        std::cout << "-------------------------" << endl;
        for (i = 0; i < noOfPlaces; i++)
        {
            std::cout << i + 1 << "- ";
            display(post[i]);
        }
        std::cout << "-------------------------" << endl;
        std::cout << "Population of Canada: " << noOfPeople << endl;
    }

    void display(Postal &pos)
    {
        std::cout << pos.postCode << ":  "; 
        std::cout << pos.noPeople << endl;
    }

    void deallocateMemory()
    {
        int i;
        for (i = 0; i < noOfPlaces; i++)
        {
            delete[] post[i].postCode;
        }
        delete[] post;
        post = nullptr;
        closeFile();
    }

} // namespace sdds
