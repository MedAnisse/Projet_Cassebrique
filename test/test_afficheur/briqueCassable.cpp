#include "briqueCassable.h"
#include "brique.h"
namespace cassebrique
{
    briqueCassable::briqueCassable():
        brique{}
        {}
    briqueCassable::briqueCassable(point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK):
        brique{BasGauche,HautDroit,move(surfaceK)}{}
    briqueCassable::briqueCassable(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK):
        brique{BasGauche,hauteur,largeur,move(surfaceK)}{}
     briqueCassable::~briqueCassable()
     {

     }

    bool briqueCassable::OnCollusion(balle& balle)
    {
        return true;
    }
}
