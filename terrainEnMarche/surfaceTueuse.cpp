#include "surfaceTueuse.h"
#include "point.h"
#include "surface.h"
using geom::point;
namespace cassebrique
{

surfaceTueuse::surfaceTueuse():surface{}{}
    surfaceTueuse::surfaceTueuse(point& debut,point & fin):surface{debut,fin}{}
    surfaceTueuse::~surfaceTueuse(){}
 bool surfaceTueuse::collision(balle& balle)
 {
     return true;
 }
}

