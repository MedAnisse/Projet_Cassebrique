#ifndef SURFACETUEUSE_H
#define SURFACETUEUSE_H
namespace cassebrique
{
class surfaceTueuse
{
    public:
      virtual bool collusion(balle& balle) override;
};
}
#endif // SURFACETUEUSE_H
