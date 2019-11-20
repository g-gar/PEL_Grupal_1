#ifndef _LIBPEL_H
   #include "LIBPEL.h"
#endif

#ifndef _PEL_PG1_MODEL_H
   #define _PEL_PG1_MODEL_H 1
#endif

namespace PEL {
   namespace PG1 {
      namespace model {
         class Point {
         public:
            double x, y;
            Point() {

            }
         };

         // y = m*x + b
         class Line {
         public:
            double m, b;
            Line(const Point& p1, const Point& p2 ) {
               m = (p2.y-p1.y)/(p2.x-p1.x);
               b = p1.y - m*p1.x;
            }
         };
      }
   }
}