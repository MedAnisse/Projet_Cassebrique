#ifndef SURFACENORMAL_H
#define SURFACENORMAL_H
#include "surface.h"
#include "point.h"
using geom::point;
class balle;
namespace cassebrique
{
class surfaceNormal : public surface
{
    public:
        surfaceNormal();
        surfaceNormal(point& debut,point & fin);
        virtual ~surfaceNormal();
       virtual bool collusion(balle& balle) ;
};
}
#endif // SURFACENORMAL_H
