#include "ball.h"
#include "vector.h"

namespace cassebrique
{
ball::ball(point &position,geom::vector& vecteur,double vitesse, double rayon) :
          d_position{position},d_vectorposition{vecteur},d_vitesse{vitesse},d_rayon{rayon}
{}

balle::~balle(){}

double ball:: rayon() const
 {
     return d_rayon;
 }

double ball :: vitesse() const
{
    return d_vitesse;
}

 void ball:: setVitesse(double vitesse)
 {
     d_vitesse=vitesse;
 }

ball* ball:: position(double dt)
 {
          
       double x= d_x+vitesse*cos(angle*3.14/180)*dt;
       double y=d_y+0.5*pow(dt,2.0)+ vitesse*sin(angle*3.14/180)*dt;
       d_position.moveTo(x, y);

 }
}



