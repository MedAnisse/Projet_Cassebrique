#ifndef SURFACE_H
#define SURFACE_H
#include "balle.h"
#include "vector.h"
#include <memory>

class surface
{
    public:
        surface();
        surface(const geom::point& a, const geom::point& b);
        virtual ~surface();
        geom::point a()const;
        geom::point b()const;
        virtual bool collision(balle& b);
        std::unique_ptr<surface> copie();
        double distance(balle& b);
        //double distanceHorizontal(balle& b);
        //double distanceVertical(balle& b);
        void moveTo(geom::vector& v);
        virtual void print(std::ostream& ost) const;
        virtual void read(std::istream& ist);
    private:
        geom::point d_a,d_b;
};

#endif // SURFACE_H
