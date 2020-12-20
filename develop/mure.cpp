#include "mure.h"
namespace cassebrique
{
mure::mure(point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK):d_HautDroit{HautDroit},d_BasGauche{BasGauche}
{
    d_surface=move(surfaceK);
}
mure::mure(point& BasGauche,double hauteur,double largeur):d_BasGauche{BasGauche}
{
    d_HautDroit{d_BasGauche.x()+largeur,d_BasGauche.y()-hauteur};
    d_surface=move(surfaceK);
}
mure::mure(double BasGauche_x,double BasGauche_y,double HautDroit_x,double HautDroit_y):
    d_HautDroit{{BasGauche_x,BasGauche_y}},d_BasGauche{{HautDroit_x,HautDroit_y}}
    {
    d_surface=move(surfaceK);
    }

 mure::~mure()
{

}
mure::mure()
{

}
surface* mure::surfaceType()const
{
    return d_surface.get();
}
double mure::Hauteur()const
{
    return d_HautDroit.y()-d_BasGauche.y();
}
double mure::Largeur()const
{
    d_HautDroit.x()-d_BasGauche.x();
}
}
