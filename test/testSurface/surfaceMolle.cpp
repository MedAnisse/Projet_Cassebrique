#include "surfaceMolle.h"
#include <iostream>

surfaceMolle::surfaceMolle(const geom::point& a,const geom::point& b): surface{a,b}
{}

surfaceMolle::~surfaceMolle()
{}
bool surfaceMolle::collision(balle& b)
{
    if(surface::distance(b)==0)
        {
            b.diminueVitesse();
            b.changerDirection();
            return true;
        }
}
std::unique_ptr<surfaceMolle> surfaceMolle:: copie()
{
    return std::make_unique<surfaceMolle>(surface::a(),surface::b());
}


void surfaceMolle::print(std::ostream& ost) const
{
    ost<<""<<"";
}
void surfaceMolle::read(std::istream& ist)
{

}

