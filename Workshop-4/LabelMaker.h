/*/////////////////////////////////////////////////////////////////////////
Workshop - #4 (P2)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_MAKER_H
#define SDDS_MAKER_H
#include <iostream>
#include "Label.h"

namespace sdds {
   class LabelMaker {
      Label* m_labels;
      int m_noOfLabels;
   public:
      LabelMaker();
      LabelMaker(int noOfLabels);
      void readLabels();
      void printLabels()const;
      void setEmpty();
      ~LabelMaker();
   };
}

#endif