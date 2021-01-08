
#include "balle.h"

balle::balle(const geom::point& centre,const geom::vector& direction,double vitesse, double rayon): d_centre{centre},d_direction{direction},d_vitesse{vitesse},d_rayon{rayon}
{

}
balle:: balle(double x, double y,double a,double b, double rayon): d_centre{x,y},d_direction{a,b},d_rayon{rayon}
{

}
balle:: balle(double x, double y, double rayon): d_centre{x,y},d_rayon{rayon}
{

}
balle::~balle(){}

double balle::vitesse()const
{
    return d_vitesse;
}
double balle::rayon()const
{
    return d_rayon;
}
geom::point balle::centre()
{
    return d_centre;
}
double balle::augmenteVitesse()
{
    return 0.0;
}

double balle::diminueVitesse()
{
    return 0.0;
}
geom::vector balle::changerDirection()
{
    // change la direction
    return d_direction;
}

