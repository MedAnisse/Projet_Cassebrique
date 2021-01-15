#ifndef SURFACE_H
#define SURFACE_H
#include "point.h"
#include"vector.h"
#include <memory>
using geom::point;
namespace cassebrique
{class balle;
class surface
{
    public:
        surface();
        surface(point& debut,point & fin);
        void moveTo(point& debut,point & fin);
        void move(double dx,double dy);
        void move(geom::vector& v);
        virtual std::unique_ptr<surface> copy();
        virtual ~surface();
        virtual bool collision(balle* balle) ;
        double distance(balle* b );
        point debut()const;
        point fin()const;
    protected:
    point d_debut;
    point d_fin;
};
}
#endif // SURFACE_H
