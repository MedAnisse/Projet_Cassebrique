#include "surfaceDure.h"
#include <iostream>

surfaceDure::surfaceDure(const geom::point& a,const geom::point& b):surface{a,b}
{
}

surfaceDure::~surfaceDure()
{
}

std::unique_ptr<surfaceDure> surfaceDure:: copie()
{
    return std::make_unique<surfaceDure>(a(),b());
}

bool surfaceDure::collision(balle& b)
{
    if(surface::distance(b))
        {
            b.augmenteVitesse();
            b.changerDirection();
            return true;
        }
}

void surfaceDure::print(std::ostream& ost) const
{
    ost<<""<<"";
}
void surfaceDure::read(std::istream& ist)
{

}

