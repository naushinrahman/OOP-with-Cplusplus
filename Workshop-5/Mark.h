#ifndef SDDS_MARK_H
#define SDDS_MARK_H
namespace sdds {
   class Mark {
      int m_mark;
   public:
      void setEmpty();
      Mark();
      Mark(int);

      operator char()const;
      operator double()const;
      operator int()const;

      Mark& operator=(int i);
      Mark& operator+=(int i);
   };
   int& operator+=(int& m, const Mark& M);

}
#endif // !SDDS_MARK_H
