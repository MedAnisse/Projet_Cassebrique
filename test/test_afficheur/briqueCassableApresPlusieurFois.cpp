#include "briqueCassableApresPlusieurFois.h"
#include "brique.h"
#include <iostream>
#include "point.h"
#include<memory>
using geom::point;
using std::unique_ptr;
using std::move;
namespace cassebrique
{
   briqueCassableApresPlusieurFois::briqueCassableApresPlusieurFois(int a,point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK):
    brique{BasGauche,HautDroit,move(surfaceK)}
    {d_nombreDeFois=a;}
    briqueCassableApresPlusieurFois::briqueCassableApresPlusieurFois(int a,point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK):
        brique{BasGauche,hauteur,largeur,move(surfaceK)},d_nombreDeFois{a}{}
    briqueCassableApresPlusieurFois::briqueCassableApresPlusieurFois(int a):
        brique{},d_nombreDeFois{a}{}
    bool briqueCassableApresPlusieurFois::existe_collusion(balle& balle)
    {
        return true;
    }
    briqueCassableApresPlusieurFois::~briqueCassableApresPlusieurFois(){}
}
