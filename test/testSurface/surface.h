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
        //geom::point pointDIntersection(balle& b);
        double distance(balle& b);
        virtual bool collision(balle& b);
        std::unique_ptr<surface> copie();
        void moveTo(geom::point& a,geom::point& b);
        void move(geom::vector & v);
        void move(double dx,double dy);
        virtual void print(std::ostream& ost) const;
        virtual void read(std::istream& ist);
    private:
        geom:: point d_a;
        geom::point d_b;
        geom::point pointDIntersection(balle& b)
        {
            geom::point o=b.centre();
            geom::point j{d_a.x(),o.y()};
            geom::point k{o.x(),d_a.y()};
            if (d_a.x()==d_b.x()&& o.intersection(o,j,d_a,d_b)){
                    return j;}
            else{
                    if(d_a.y()==d_b.y()&& o.intersection(o,k,d_a,d_b))
                    return k;
            }
}
};

#endif // SURFACE_H
