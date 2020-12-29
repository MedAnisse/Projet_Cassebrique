#include "balle.h"
#include "vector.h"
namespace cassebrique
{
    balle::balle()
    {
    }
    balle::balle(point &position,geom::vector& vecteur,double vitesse,double rayon):d_position{position},d_vectorposition{vecteur},d_vitesse{vitesse},d_rayon{rayon}
    {

    }
    balle::~balle(){}
    balle*  balle::position(double Dt){return this;}
    point balle::position()const
    {
        return d_position;
    }
    double balle::rayon()const
    {
        return d_rayon;
    }
}
