#ifndef SURFACENORMAL_H
#define SURFACENORMAL_H
#include "surface.h"
class balle;
namespace cassebrique
{
class surfaceNormal : public surface
{
    public:
        virtual ~surfaceNormal();
       virtual bool collusion(balle& balle) override;
};
}
#endif // SURFACENORMAL_H
