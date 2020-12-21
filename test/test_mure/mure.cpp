#include "mure.h"
#include <memory>
#include<iostream>
#include<ostream>
#include<istream>
using std::unique_ptr;
using std::move;
using std::make_unique;
using geom::point;
namespace cassebrique
{
mure::mure(const point& BasGauche,const point& HautDroit,unique_ptr<surface>surfaceK):d_HautDroit{HautDroit},d_BasGauche{BasGauche}
{
    d_surface=move(surfaceK);
}
mure::mure(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK):d_BasGauche{BasGauche}
{
    d_HautDroit=point(d_BasGauche.x()+largeur , d_BasGauche.y()-hauteur);
    d_surface=move(surfaceK);
}
 mure::~mure()
{

}
mure::mure():d_BasGauche{0.0,0.0},d_HautDroit{0.0,0.0}
{
    d_surface=make_unique<surfaceNormal>();
}
surface* mure::surfaceType()const
{
    return d_surface.get();
}
double mure::Hauteur()const
{
    return -d_HautDroit.y()+d_BasGauche.y();
}
double mure::Largeur()const
{
   return d_HautDroit.x()-d_BasGauche.x();
}
void mure::print(std::ostream& ost) const
{
    ost<<""<<"";
}
void mure::read(std::istream& ist)
{

}
std::ostream& operator<<(std::ostream& ost, const mure& m)
{
  m.print(ost);
  return ost;
}

std::istream& operator>>(std::istream& ist, mure& m)
{
  m.read(ist);
  return ist;
}
point mure::BasGauche() const
{
    return d_BasGauche;
}
point mure::HautDroit() const
{
    return d_HautDroit;
}
bool mure::OnCollusion(balle& balle)const
{
    return d_surface->collusion(balle);
}
}
