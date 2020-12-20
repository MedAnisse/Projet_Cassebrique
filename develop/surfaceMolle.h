#ifndef SURFACEMOLLE_H
#define SURFACEMOLLE_H
namespace cassebrique
{
class surfaceMolle
{
    public:
      virtual bool collusion(balle& balle) override;
};
}
#endif // SURFACEMOLLE_H
