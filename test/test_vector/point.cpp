#include<iostream>
#include<cmath>
#include"point.h"

point::point(double x,double y) : d_x{x}, d_y{y}
{}

//correct
/*
point::point() : d_x{0.0}, d_y{0.0}
{}
*/

//variante préférable ici pour des raisons de clarté
point::point() : point{0.0,0.0}
{}

point point::cartesian(double x,double y)
{
  return point{x,y};
}

point point::polar(double rho,double theta)
{
  return {rho*cos(theta),rho*sin(theta)};
}

double point::x() const
{
  return d_x;
}

double point::y() const
{
  return d_y;
}

double point::distance(const point& p) const
{
  double dx = p.x() - x();
  double dy = p.d_y - d_y;  //préférable ici
  return std::sqrt(dx*dx + dy*dy);
}


void point::moveTo(double x,double y)
{
  d_x = x; d_y = y;
}

void point::move(double dx,double dy)
{
  d_x += dx; d_y += dy;
}


void point::print(std::ostream& ost) const
{
  ost<<'('<<d_x<<','<<d_y<<')';
}

void point::read(std::istream& ist)
{
  char c; double x,y;
  ist>>c>>x>>c>>y>>c;
  if (ist.good())
  { d_x = x; d_y = y; }
}


std::ostream& operator<<(std::ostream& ost, const point& p)
{
  p.print(ost); return ost;
}

std::istream& operator>>(std::istream& ist, point& p)
{
  p.read(ist); return ist;
}
