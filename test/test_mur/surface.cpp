#include "surface.h"
#include<memory>
namespace cassebrique
{
surface::~surface()
{
    //dtor
}
surface::surface():d_debut{},d_fin{}{}
surface::surface(point& debut,point & fin):d_debut{debut},d_fin{fin}{}
void surface::moveTo(point& a ,point&b)
{
    d_debut=a;
    d_fin=b;
}
void surface::move(geom::vector & v)
{
    d_debut.move(v);
    d_fin.move(v);
}
void surface::move(double dx,double dy)
{
    d_debut.move(dx,dy);
    d_fin.move(dx,dy);
}
std::unique_ptr<surface> surface::copy()
{
    return std::make_unique<surface>();
}
bool surface::collusion(balle& balle)
{
    return true;
}
}
