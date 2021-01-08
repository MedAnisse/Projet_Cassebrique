#ifndef BALLE_H
#define BALLE_H
#include "vector.h"
#include "point.h"
using geom::point;
using geom::vector;
namespace cassebrique
{
    class balle
{
public:
    balle();
    balle(point &position,geom::vector& vecteur,double vitesse,double rayon);
    virtual ~balle();
    balle*  position(double Dt);
    point position()const;
    double rayon()const;
    //metode changer vitesse

private:
    point d_position;
    double d_vitesse;
    double d_rayon;
    geom::vector d_vectorposition;
protected:

};

}

#endif
