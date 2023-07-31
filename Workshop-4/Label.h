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
