#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {
   struct Population {
      char m_postalCode[4];
      int m_population;
   };

   void sort();
   bool load();
   bool load(const char filename[]);
   void display(const Population& population);
   void display();
   void deallocateMemory();
}
