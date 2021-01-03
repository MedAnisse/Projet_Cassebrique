#include "rectangle.h"
#include<iostream>
#include<ostream>
#include<istream>
using geom::point;
namespace cassebrique
{
rectangle::rectangle(const point& BasGauche,const point& HautDroit):d_HautDroit{HautDroit},d_BasGauche{BasGauche}{}
rectangle::rectangle(point& BasGauche,double hauteur,double largeur):d_BasGauche{BasGauche}
{
    d_HautDroit=point(d_BasGauche.x()+largeur , d_BasGauche.y()+hauteur);
}
 rectangle::~rectangle(){}
rectangle::rectangle():d_BasGauche{0.0,0.0},d_HautDroit{0.0,0.0}{}

double rectangle::Hauteur()const
{
    return d_HautDroit.y()-d_BasGauche.y();
}
double rectangle::Largeur()const
{
   return d_HautDroit.x()-d_BasGauche.x();
}
void rectangle::print(std::ostream& ost) const
{
    ost<<""<<"";
}
void rectangle::read(std::istream& ist)
{

}
std::ostream& operator<<(std::ostream& ost, const rectangle& r)
{
  r.print(ost);
  return ost;
}

std::istream& operator>>(std::istream& ist, rectangle& r)
{
  r.read(ist);
  return ist;
}
point rectangle::BasGauche() const
{
    return d_BasGauche;
}
point rectangle::HautDroit() const
{
    return d_HautDroit;
}

}

