#include "mur.h"
#include <memory>
#include<iostream>
#include<ostream>
#include<istream>
#include"rectangle.h"
using std::unique_ptr;
using std::move;
using std::make_unique;

using geom::point;
namespace cassebrique
{
mur::mur( point& BasGauche,point& HautDroit,unique_ptr<surface>& surfaceK):rectangle{BasGauche,HautDroit}
{
    d_surface=move(surfaceK);
}
mur::mur(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>& surfaceK):rectangle{BasGauche,hauteur,largeur}
{
    d_surface=move(surfaceK);
}
 mur::~mur()
{

}
mur::mur():rectangle{}
{
    d_surface=make_unique<surface>();
}
surface* mur::surfaceType()const
{
    return d_surface.get();
}

bool mur::OnCollision(balle& balle)const
{
    return d_surface->collusion(balle);
}
}
