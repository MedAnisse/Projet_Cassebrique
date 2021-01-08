#ifndef SURFACEMOLLE_H
#define SURFACEMOLLE_H
#include <vector>
#include <memory>
#include "balle.h"
#include "surface.h"

class surfaceMolle : public surface
{
    public:
        surfaceMolle(const geom::point& a,const geom::point& b);
        virtual ~surfaceMolle();
        virtual bool collision(balle& b) override;
        std::unique_ptr<surfaceMolle> copie();
        virtual void print(std::ostream& ost) const override;
        virtual void read(std::istream& ist) override;
};
#endif // SURFACEMOLLE_H
