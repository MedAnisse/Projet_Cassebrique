#ifndef BALL_H
#define BALL_H
#include "point.h"

namespace cassebrique
{


class ball {

     public :

         ball(point &position,double vitesse, double rayon);
         ball(double x,double y, double rayon);
         virtual ~ball();
         double rayon() const;
         double vitesse() const;
         point position() const;
         balle& position(double Dt);
         void affiche(std::ostream& ost) const;

     private :
        double d_vitesse,d_rayon;
        point d_position;
};
}
#endif // BALL_H
