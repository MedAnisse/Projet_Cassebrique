#include "surface.h"
#include "math.h"
#include <stdlib.h>
#include <iostream>



surface::surface():d_a{0,0},d_b{0,0}
{
    //ctor
}
surface::surface(const geom::point& a, const geom::point& b):d_a{a},d_b{b}{}
surface::~surface()
{
    //dtor
}
geom::point surface::a()const
{
    return d_a;
}

geom::point surface::b()const
{
    return d_b;
}

void surface::moveTo(geom::vector& v)
{
    d_a.move(v);
    d_b.move(v);
}

bool surface::collision(balle& b)
{
    if(distance(b)==0)
        {
            b.rebond();
            return true;
        }
}

double surface::distance(balle& b )
{
    double A= (d_b.y()-d_a.y())/(d_b.x()-d_a.x());
    double B= d_a.y()-A*d_a.x();
    geom::point o = b.position();
    return abs((A*o.x()-o.y()+B)/sqrt(A*A+B*B))-b.rayon();
}
std::unique_ptr<surface> surface:: copie()
{
    return std::make_unique<surface>(a(),b());
}
/*double surface::distanceHorizontal(balle& b)
{
    geom::point o=b.position();//centre de la balle
    geom::point j{o.x(),d_a.y()};// oj segment perpendiculaire sur la surface ab, x de o égal a x de j si la surface est horizontal
    return o.distance(j)-b.rayon();
}

double surface::distanceVertical(balle& b)
{
    geom::point o=b.position();//centre de la balle
    geom::point j{d_a.x(),o.y()};// oj segment perpendiculaire sur la surface ab, y de o égal a y de j si la surface est vertical
    return o.distance(j)-b.rayon();
}
*/
void surface::print(std::ostream& ost) const
{
    ost<<""<<"";
}
void surface::read(std::istream& ist)
{


}
