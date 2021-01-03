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


bool surface::collision(balle& b)
{
    if(distance(b)==0)
        {
            b.changeDirection();
            return true;
        }
}

double surface::distance(balle& b )
{
    double A= (d_b.y()-d_a.y())/(d_b.x()-d_a.x());
    double B= d_a.y()-A*d_a.x();
    geom::point o = b.position();
    return abs((A*o.x()-o.y()+B)/sqrt(A*A+1))-b.rayon();
}
std::unique_ptr<surface> surface:: copie()
{
    return std::make_unique<surface>(a(),b());
}

void surface::moveTo(geom::point& a ,geom::point&b)
{
    d_a=a;
    d_b=b;
}
void surface::move(geom::vector & v)
{
    d_a.move(v);
    d_b.move(v);
}
void surface::move(double dx,double dy)
{
    d_a.move(dx,dy);
    d_b.move(dx,dy);
}

void surface::print(std::ostream& ost) const
{
    ost<<""<<"";
}
void surface::read(std::istream& ist)
{


}
