#ifndef BALL_H
#define BALL_H
#include "point.h"
#include "vector.h"
#include<iosfwd>


namespace geom
{
class point;

class ball {

     public :

         ball(point &position,vector &direction,double vitesse, double rayon);
         ball(double x,double y,double xd,double yd, double rayon);
         double rayon() const;
         double vitesse() const;
         point position() const;
         vector direction() const;
         void setVitesse(double vitesse);
         ball* position(double dt);


     private :
        double d_vitesse,d_rayon;
        point d_position;
        vector d_direction;
};

}
#endif // BALL_H
