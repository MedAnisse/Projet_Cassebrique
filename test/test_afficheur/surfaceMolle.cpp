#include "surfaceMolle.h"
#include "point.h"
#include "surface.h"
using geom::point;
namespace cassebrique
{

surfaceMolle::surfaceMolle():surface{}{}
    surfaceMolle::surfaceMolle(point& debut,point & fin):surface{debut,fin}{}
    surfaceMolle::~surfaceMolle(){}
 bool surfaceMolle::collusion(balle& balle)
 {
     return true;
 }
}


