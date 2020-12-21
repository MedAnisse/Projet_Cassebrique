#include "Raquette.h"
#include <memory>
#include<iostream>
#include<ostream>
#include<istream>
#include"point.h"
#include"surface.h"
#include"surfaceNormal.h"
#include "rectangle.h"
using std::unique_ptr;
using std::make_unique;
using geom::point;
class balle;
namespace cassebrique
{
    Raquette::Raquette():rectangle{}
    {
    d_surface=make_unique<surfaceNormal>();
    }
    Raquette::Raquette(const point& BasGauche,const point& HautDroit,unique_ptr<surface>surfaceK):rectangle{BasGauche,HautDroit}
{
    d_surface=move(surfaceK);
}
    Raquette::Raquette(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK):rectangle{BasGauche,hauteur,largeur}
{
    d_surface=move(surfaceK);
}
    Raquette::~Raquette()
    {

    }
    surface* Raquette::surfaceType()const
    {
        return d_surface.get();
    }
    void Raquette::move_Gauche()
    {
        rectangle::d_BasGauche.move(0.0,-1.0);
        rectangle::d_HautDroit.move(0.0,-1.0);
    }
    void Raquette::move_Droit()
    {
        rectangle::d_BasGauche.move(0.0,1.0);
        rectangle::d_HautDroit.move(0.0,1.0);
    }
    void Raquette::move_Gauche(int n)
    {
        for(int i=0 ;i<n;i++)
        {
            move_Gauche();
        }
    }
    void Raquette::move_Droit(int n)
    {
        for(int i=0 ;i<n;i++)
        {
            move_Droit();
        }
    }
}
