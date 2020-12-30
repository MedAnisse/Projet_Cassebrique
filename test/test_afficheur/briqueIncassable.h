#ifndef BRIQUEINCASSABLE_H
#define BRIQUEINCASSABLE_H
#include "brique.h"
namespace cassebrique
{
class briqueIncassable : public brique
{
public:
    briqueIncassable(point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK);
    briqueIncassable(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK);
    briqueIncassable();
    virtual ~briqueIncassable();
    virtual bool OnCollusion(balle& balle)  override;
    private:
    vector<unique_ptr<surface>> d_surface;
};
}
#endif
