#ifndef SURFACETUEUSE_H
#define SURFACETUEUSE_H
#include"surface.h"
class balle;
namespace cassebrique
{
class surfaceTueuse : public surface
{
    public:
    virtual ~surfaceTueuse();
      virtual bool collusion(balle& balle) override;
};
}
#endif // SURFACETUEUSE_H
