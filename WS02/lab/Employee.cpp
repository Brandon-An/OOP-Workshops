#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee *emp) {
      bool ok = false;
      char name[128];
      int len;
      int i;
      double j;
      bool r1, r2, r3;

      r1 = read(i);
      emp->m_empNo = i;

      r2 = read(j);
      emp->m_salary = j;

      r3 = read(name);
      len = strLen(name);
      emp->m_name = new char[len+1];
      emp->m_name[len] = '\0';
      strCpy(emp->m_name, name);

      if (r1 && r2 && r3)
	      ok = true;

      /* if reading of employee number, salay and name are successful
              allocate memory to the size of the name + 1
              and keep its address in the name of the Employee Reference

              copy the name into the newly allocated memroy

              make sure the "ok" flag is set to true
         end if
      */
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      int j;
      
      if (openFile(DATAFILE)) {
         j = noOfRecords();
	 noOfEmployees = j;
         Employee *emp = new Employee[j];
	 employees = emp;
         for (i = 0; i <= j-1; i++){
            load(&(emp[i]));
           // std::cout << emp[i].m_empNo << emp[i].m_name << emp[i].m_salary << std::endl;

         }

         /* 
          Set the noOfEmployees to the number of recoreds in the file.
          dyanamically allocated an array of employees into the global
          Employee pointer; "employees" to the size of the noOfEmployees.

          In a loop load the employee records from the file into 
          the dynamic array.

          If the number of the records does not match the number of reads
             print the message
            "Error: incorrect number of records read; the data is possibly corrupted"
          Otherwise
             set the ok flag to true
          End if

          close the file
          */
	 if (i != noOfEmployees){
		 std::cout << "Error: incorrect number of records read; the data is possibly corrupted.";
      		 closeFile();
	 }
	 else{
		 ok = true;
	 }
      }
      else{
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(){
	int i;
	sort();
	   std::cout << "Employee Salary report, sorted by employee number" << endl;
	   std::cout << "no- Empno, Name, Salary" << endl;
	   std::cout << "------------------------------------------------" << endl;
	for (i = 0; i < noOfEmployees; i++){
	   std::cout << i+1 << "- ";
	   display(employees[i]);
	}
   }

   void display(Employee &emp){
	   std::cout << emp.m_empNo << ": ";
	   std::cout << emp.m_name << ", ";
	   std::cout.precision(6);
	   std::cout << emp.m_salary << endl;
	   return;
   }

		
   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory (){
	   int i;
	   for (i = 0; i < noOfEmployees; i++){
		   delete [] employees[i].m_name;
	   }
	delete [] employees;
	employees = nullptr;
	return;
   }



}
