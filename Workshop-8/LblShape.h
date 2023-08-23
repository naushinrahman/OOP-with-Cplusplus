#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include <iostream>
#include "Shape.h"

namespace sdds {
   class LblShape : public Shape {
      char* m_label;
   protected:
      const char* label()const;
   public:
      LblShape();
      LblShape(const char* label);
      ~LblShape();
      void getSpecs(std::istream& is);
      LblShape(const LblShape& lblShape) = delete;
      LblShape& operator=(const LblShape& lblShape) = delete;
   };
}


#endif
