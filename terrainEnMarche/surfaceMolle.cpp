#include "surfaceMolle.h"
#include "point.h"
#include"balle.h"
#include "surface.h"
using geom::point;
namespace cassebrique
{

surfaceMolle::surfaceMolle():surface{}{}
    surfaceMolle::surfaceMolle(point& debut,point & fin):surface{debut,fin}{}
    surfaceMolle::~surfaceMolle(){}
 bool surfaceMolle::collision(balle* balle)
 {
     if(surface::distance(balle)==0)
        {
            balle->rebond(-1);
            return true;
        }
 }
}


