#ifndef SURFACETUEUSE_H
#define SURFACETUEUSE_H
#include"surface.h"
#include "point.h"
using geom::point;
class balle;
namespace cassebrique
{
class surfaceTueuse : public surface
{
    public:
        surfaceTueuse();
       surfaceTueuse (point& debut,point & fin);
    virtual ~surfaceTueuse();
      virtual bool collusion(balle& balle);
};
}
#endif // SURFACETUEUSE_H
