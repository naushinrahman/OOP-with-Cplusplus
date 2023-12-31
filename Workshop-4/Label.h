/*/////////////////////////////////////////////////////////////////////////
Workshop - #4 (P2)
Full Name : Naushin Rahman
Student ID# : 144079225
Email : nrahman30@myseneca.ca
Section : NEE

Authenticity Declaration :
have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>

namespace sdds {
   class Label {
      char m_frame[9];
      char* m_content;
      void setToDefault();
   public:
      Label();
      Label(const char* frameArg);
      Label(const char* frameArg, const char* content);
      ~Label();
      std::ostream& printLabel()const;
      void readLabel();
   };
}
#endif // SDDS_LABEL_H
