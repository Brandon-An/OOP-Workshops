#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define DATAFILE "PCpopulationsComplete.csv"

namespace sdds {
    struct Postal {
        char* postCode;
        int noPeople;
    };
    
    bool load(Postal* pos);
    bool load(const char filename[]);
    void sort();
    void display();
    void display(Postal& pos);
    void deallocateMemory();

}
#endif // SDDS_POPULATION_H_
