#ifndef BALL_H
#define BALL_H
#include "point.h"
#include "vector.h"
using geom::point;
using geom::vector;


namespace cassebrique
{

class ball {

     public :

         ball(point &position, geom::vector& vecteur,double vitesse, double rayon);
         virtual ~balle();
         double rayon() const;
         double vitesse() const;
         point position() const;
         void setVitesse(double vitesse);
         ball* position(double dt);


     private :
         point d_position;
         double d_vitesse;
         double d_rayon;
         geom::vector d_vectorposition;
};

}
#endif // BALL_H
