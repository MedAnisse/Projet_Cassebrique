#ifndef POINT_H
#define POINT_H

#include<iosfwd>

class point {
public :
  point();
  point(double x,double y);
//named constructors
  static point cartesian(double x,double y);
  static point polar(double rho,double theta);

  double x()     const;    //cartesian coordinates
  double y()     const;
  double distance(const point& p) const;
  void print(std::ostream& ) const;
  void read(std::istream& );

  void moveTo(double x,double y);
  void move(double dx,double dy);
private :
  double d_x,d_y;          //cartesian representation
};

std::ostream& operator<<(std::ostream& , const point& );
std::istream& operator>>(std::istream& , point& );


#endif
