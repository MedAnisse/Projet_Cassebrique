#ifndef BALLE_H
#define BALLE_H
#include "point.h"
#include "vector.h"

class balle
{
    public:
        balle(const geom::point &position, const geom::vector &direction,double vitesse, double rayon);
        balle(double x , double y , double a  ,double b , double rayon);
        balle(double x, double y, double rayon);
        virtual ~balle();
        geom::point centre();
        double vitesse() const;
        double augmenteVitesse();
        double diminueVitesse();
        geom::vector changerDirection();
        double rayon() const;
    private:
        geom::vector d_direction;
        geom::point d_centre;
        double d_vitesse,d_rayon;
};

#endif // BALLE_H
