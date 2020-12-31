#include "surfaceNormal.h"
#include "point.h"
#include "surface.h"
using geom::point;
namespace cassebrique
{
    surfaceNormal::surfaceNormal():surface{}{}
    surfaceNormal::surfaceNormal(point& debut,point & fin):surface{debut,fin}{}
    surfaceNormal::~surfaceNormal(){}
 bool surfaceNormal::collusion(balle& balle)
 {
     return true;
 }
}

