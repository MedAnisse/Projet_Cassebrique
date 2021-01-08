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
    if (d_debut.x()==d_fin.x())
    {
        geom::point o=b->position();//centre de la balle
        if(o.y()>=d_debut.y()&&o.y()<=d_fin.y()||o.y()<=d_debut.y()&&o.y()>=d_fin.y())
        {geom::point j{d_debut.x(),o.y()};// oj segment perpendiculaire sur la surface ab, x de o égal a x de j si la surface est horizontal
        return o.distance(j)-b->rayon();
        }
    }else
    {
        if(d_debut.y()==d_fin.y())
            {
                geom::point o=b->position();//centre de la balle
                if(o.x()>=d_debut.x()&&o.x()<=d_fin.x()||o.y()<=d_debut.y()&&o.y()>=d_fin.y())
                {geom::point j{o.x(),d_debut.y()};// oj segment perpendiculaire sur la surface ab, y de o égal a y de j si la surface est vertical
                return o.distance(j)-b->rayon();}
            }
    }
return 1.0;
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
