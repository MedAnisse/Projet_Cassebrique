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
point rectangle::BasGauche() const
{
    return d_BasGauche;
}
point rectangle::HautDroit() const
{
    return d_HautDroit;
}

}

