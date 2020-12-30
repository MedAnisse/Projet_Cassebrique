#ifndef BRIQUECASSABLE_H
#define BRIQUECASSABLE_H
#include "brique.h"
namespace cassebrique
{
class briqueCassable : public brique
{
public:
    briqueCassable();
    briqueCassable(point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK);
    briqueCassable(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK);
    virtual ~briqueCassable();
    virtual bool OnCollusion(balle& balle) override;
};
}
#endif
