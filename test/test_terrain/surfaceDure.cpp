#include "surfaceDure.h"
#include "point.h"
#include"balle.h"
#include "surface.h"
using geom::point;
namespace cassebrique
{

surfaceDure::surfaceDure():surface{}{}
    surfaceDure::surfaceDure(point& debut,point & fin):surface{debut,fin}{}
    surfaceDure::~surfaceDure(){}
 bool surfaceDure::collusion(balle* balle)
 {
     if(surface::distance(balle)<=0)
        {
            balle->rebond(10);
            return true;
        }
 }
}
