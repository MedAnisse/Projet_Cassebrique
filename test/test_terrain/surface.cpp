#include "surface.h"
#include"math.h"
#include"balle.h"
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
bool surface::collusion(cassebrique::balle* balle)
{
   if((distance(balle) <= 0 ))
        {
            balle->rebond();
            return true;
        }
}
double surface::distance(balle* b )
{
    double A= (d_fin.y()-d_debut.y())/(d_fin.x()-d_debut.x());
    double B= d_debut.y()-A*d_debut.x();
    geom::point o = b->position();
    double distance=abs((A*o.x()-o.y()+B)/sqrt((A*A)+(B*B))) ;//- b->rayon();

    return distance;

}
point surface::debut()const
{
    return d_debut;
}

point surface::fin()const
{
    return d_fin;
}
}
