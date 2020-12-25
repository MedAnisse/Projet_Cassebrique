#ifndef SURFACEDURE_H
#define SURFACEDURE_H
#include <vector>
#include "balle.h"
#include "surface.h"

class surfaceDure: public surface
{
    public:
        surfaceDure(const geom::point& a,const geom::point& b);
        virtual ~surfaceDure();
        virtual bool collision(balle& b) override;
        std::unique_ptr<surfaceDure> copie();
        virtual void print(std::ostream& ost) const override;
        virtual void read(std::istream& ist) override;
};

#endif // SURFACEDURE_H
