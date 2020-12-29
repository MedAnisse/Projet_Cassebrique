#include "briqueIncassable.h"
namespace cassebrique
{
    briqueIncassable::briqueIncassable(point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK):
        brique{BasGauche,HautDroit,move(surfaceK)}{}
    briqueIncassable::briqueIncassable(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK):
        brique{BasGauche,hauteur,largeur,move(surfaceK)}{}
    briqueIncassable::briqueIncassable():brique{}{}

     briqueIncassable::~briqueIncassable(){}
    bool briqueIncassable::existe_collusion(balle& balle)
    {
        return true;
    }
}
