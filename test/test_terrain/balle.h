#ifndef BALLE_H
#define BALLE_H
#include "point.h"
using geom::point;
using geom::vector;
namespace cassebrique
{
    class balle
{
public:
    balle();
    balle(point &position,double ongle,double vitesse,double rayon);
    virtual ~balle();
    balle*  position(double Dt);
    point position()const;
    double rayon()const;
    void rebond();
    void rebond(double nouvelleVitesseAjouter);
    double ongle()const;

    //metode changer vitesse

private:
    point d_position;
    double d_vitesse;
    double d_rayon;
   double d_ongle;// d_ongle[0,2]
protected:

};

}

#endif
