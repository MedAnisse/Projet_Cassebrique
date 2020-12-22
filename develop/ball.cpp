#include "ball.h"


ball::ball(point &position,double vitesse, double rayon) :
          d_position{position},d_vitesse{vitesse},d_rayon{rayon}
{}
ball:: ball(double x, double y, double rayon):
         point{x,y},d_rayon{rayon}
{}
double ball:: rayon() const
 {
     return d_rayon;
 }
double ball :: vitesse() const
{
    return d_vitesse;
     }
ball& ball:: position(double Dt)
 {
       //
 }



