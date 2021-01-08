#ifndef SURFACETUEUSE_H
#define SURFACETUEUSE_H
#include <vector>
#include "balle.h"
#include "surface.h"

class surfaceTueuse : public surface
{
    public:
        surfaceTueuse(const geom::point& a, const geom::point& b);
        virtual ~surfaceTueuse();
        virtual bool collision(balle& b) override;
        std::unique_ptr<surfaceTueuse> copie();
        virtual void print(std::ostream& ost) const override;
        virtual void read(std::istream& ist) override;
};

#endif // SURFACETUEUSE_H
