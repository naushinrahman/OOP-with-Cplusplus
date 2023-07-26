/*/////////////////////////////////////////////////////////////////////////
Workshop - #2 (P1)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

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
   bool load(Employee& employee) {
      bool ok = false, one = false, two = false, three = false;
      char name[128];
      int empNum = 0, actLen;
      double empSalary = 0;

      one = read(empNum);
      two = read(empSalary);
      three = read(name);

      if (one == true && two == true && three == true) {
         actLen = (strLen(name) + 1);
         employee.m_name = new char[actLen];
         strCpy(employee.m_name, name);
         employee.m_empNo = empNum;
         employee.m_salary = empSalary;
         ok = true;
      }
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
      if (openFile(DATAFILE)) {
         noOfEmployees = noOfRecords();

         employees = new Employee[noOfEmployees]; 
         
         for (; i < noOfEmployees; i++) {
            load(employees[i]);
         }
         if (i == noOfEmployees) {
            ok = true;
            closeFile();
         }
         else {
            cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
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
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& employee) {
      cout << employee.m_empNo << ": " << employee.m_name << ", " << employee.m_salary << endl;
   }

   void display() {
      cout << "Employee Salary report, sorted by employee number\n";
      cout << "no - Empno, Name, Salary\n------------------------------------------------\n";
      sort();
      for (int i = 0; i < noOfEmployees; i++) {
         cout << i+1 << "- " << employees[i].m_empNo << ": " << employees[i].m_name << ", " << employees[i].m_salary << endl;
      }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
      if (employees != NULL) {
         for (int i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
            employees[i].m_name = nullptr;
         }
         delete[] employees;
         employees = nullptr;
      }
   }
}