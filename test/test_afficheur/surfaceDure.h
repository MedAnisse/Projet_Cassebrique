#ifndef SURFACEDURE_H
#define SURFACEDURE_H
#include"surface.h"
#include "point.h"
using geom::point;
namespace cassebrique
{

class surfaceDure : public surface
{
    public:
        surfaceDure();
        surfaceDure(point& debut,point & fin);
        virtual ~surfaceDure();
        virtual bool collusion(balle& balle) ;

};
}
#endif // SURFACEDURE_H
