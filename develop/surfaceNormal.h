#ifndef SURFACENORMAL_H
#define SURFACENORMAL_H
namespace cassebrique
{
class surfaceNormal
{
    public:
       virtual bool collusion(balle& balle) override;
};
}
#endif // SURFACENORMAL_H
