#include "ball.h"


ball::ball(point &position,vector &direction,double vitesse, double rayon) :
          d_position{position},d_direction{direction},d_vitesse{vitesse},d_rayon{rayon}
{}
ball:: ball(double x, double y,double x,double y double rayon):
         point{x,y},vector{x,y},d_rayon{rayon}
{}
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
 vector ball:: direction() const
 {
     return d_direction;
 }
ball* ball:: position(double dt)
 {
          
       double x= d_x+vitesse*cos(angle*3.14/180)*dt;
       double y=d_y+0.5*pow(dt,2.0)+ vitesse*sin(angle*3.14/180)*dt;
       d_position.moveTo(x, y);

 }



