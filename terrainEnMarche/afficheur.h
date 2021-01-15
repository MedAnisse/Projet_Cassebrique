#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include "rectangle.h"
#include "Raquette.h"
#include "balle.h"
#include "brique.h"
#include<vector>
namespace cassebrique
{

    class afficheur
{
    public:
        virtual void afficherTerrain(double largeur,double hauteur) const =0 ;
        virtual void afficherRectangle(cassebrique::rectangle* terain) const =0 ;
        virtual void afficherRaquette(cassebrique::Raquette* raquette)const =0;
        virtual void afficherBrique(cassebrique::brique* brique)const =0;
        virtual void afficherBalle(cassebrique::balle* balle)const =0;
        virtual void effacerContenu()const =0;
        virtual char caractereEntree()const =0;
        virtual void fermerFenetre()const =0;

};

}


#endif // AFFICHEUR_H
