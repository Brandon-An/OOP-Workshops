#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read (char* string);
   bool read (int &number);
   bool read (double &salary);
   // TODO: Declare read prototypes
 

}
#endif // !SDDS_FILE_H_
