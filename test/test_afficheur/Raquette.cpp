#include "Raquette.h"
#include <memory>
#include<iostream>
#include<ostream>
#include<istream>
#include"point.h"
#include"surface.h"
#include"surfaceNormal.h"
#include "vector.h"
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
    Raquette::Raquette(const point& BasGauche,const point& HautDroit):rectangle{BasGauche,HautDroit}
    {double x{BasGauche.x()},y{HautDroit.y()};
        point HautGauche{x,y};
        point HautDroit1=HautDroit;
        d_surface=make_unique<surfaceNormal>(HautGauche,HautDroit1);
    }
    Raquette::Raquette(point& BasGauche,double hauteur,double largeur):rectangle{BasGauche,hauteur,largeur}
{double x{BasGauche.x()},y{rectangle::HautDroit().y()};
    point HautGauche{x,y};
    point HautDroit1=rectangle::HautDroit();
    d_surface=make_unique<surfaceNormal>(HautGauche,HautDroit1);
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
        rectangle::d_BasGauche.move(-10,0.0);
        rectangle::d_HautDroit.move(-10,0.0);
        d_surface->move(-10,0.0);
    }
    void Raquette::move_Droit()
    {
        rectangle::d_BasGauche.move(10,0.0);
        rectangle::d_HautDroit.move(10,0.0);
        d_surface->move(10,0.0);
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
    bool Raquette::OnCollusion(balle& balle)const
{
    return d_surface->collusion(balle);
}
}
