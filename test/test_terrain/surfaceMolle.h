#ifndef SURFACEMOLLE_H
#define SURFACEMOLLE_H
#include"surface.h"
#include "point.h"
using geom::point;
namespace cassebrique
{
class surfaceMolle : public surface
{
    public:
        surfaceMolle();
        surfaceMolle(point& debut,point & fin);
        virtual ~surfaceMolle();
      virtual bool collusion(balle* balle);
};
}
#endif // SURFACEMOLLE_H
