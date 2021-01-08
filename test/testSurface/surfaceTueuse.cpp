#include "surfaceTueuse.h"
#include <iostream>

surfaceTueuse::surfaceTueuse(const geom::point& a,const geom::point& b ):surface{a,b}
{

}

surfaceTueuse::~surfaceTueuse()
{
    //dtor
}
bool surfaceTueuse::collision(balle& b)
{
    if(surface::distance(b)==0)
        {
            b.~balle();
            return true;
        }
}

std::unique_ptr<surfaceTueuse> surfaceTueuse:: copie()
{
    return std::make_unique<surfaceTueuse>(surface::a(),surface::b());
}

void surfaceTueuse::print(std::ostream& ost) const
{
    ost<<"surface Tueuse"<<"";
}
void surfaceTueuse::read(std::istream& ist)
{

}

