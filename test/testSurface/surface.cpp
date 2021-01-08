#include "surface.h"
#include "math.h"
#include <stdlib.h>
#include <iostream>



surface::surface():d_a{0,0},d_b{0,0}
{}
surface::surface(const geom::point& a, const geom::point& b):d_a{a},d_b{b}{}

surface::~surface()
{}
geom::point surface::a()const
{
    return d_a;
}

geom::point surface::b()const
{
    return d_b;
}


double surface::distance(balle& b )
{
    geom::point p=pointDIntersection(b);
    return b.centre().distance(p)-b.rayon();

}

bool surface::collision(balle& b)
{
    if(distance(b)==0)
        {
            b.changerDirection();
            return true;
        }
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
