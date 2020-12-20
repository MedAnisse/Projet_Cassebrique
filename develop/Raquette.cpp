#include "Raquette.h"
namespace cassebrique
{
     Raquette::Raquette(point& position,double hauteur,double largeur,unique_ptr<surface> surfaceK)
     d_position{position},d_hauteur{hauteur},d_largeur{largeur}
     {
         d_surface=move(surfaceK);
     }
    Raquette::~Raquette()
     {

     }
    surface* Raquette::surfaceType()const
     {
        return d_surface.get();
     }
    double Raquette::Hauteur()const
     {
         return d_hauteur;
     }
    double Raquette::Largeur()const
     {
        return d_largeur;
     }
     void bougerGauche(int n)
     {
    // changer la position de raquette vers la gauche avec n pas
     }
    void bougerDroit(int n)
    {
    // changer la position de raquette vers la droit avec n pas
    }
}
