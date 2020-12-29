#ifndef TERRAIN_H
#define TERRAIN_H
#include <vector>
#include <iostream>
#include "rectangle.h"
#include <memory>
#include"mure.h"
#include"Raquette.h"
#include"brique.h"
#include "balle.h"
#include "surface.h"
#include"afficheurWinBgi.h"
using std::vector;
using std::unique_ptr;


namespace cassebrique
{
class Terrain
{
    public:
        unique_ptr<surface> randomSurface();
        unique_ptr<brique>  randomBrique(point &position,double largeur,double hauteurBrique);
        Terrain(double hauteurTerrain, double largeurTerrain,int nombreColone,int nombreLigne,double hauteurMure,double hauteurRaquette,double largeurRaquette);
        virtual ~Terrain();
        vector<mure*> mure() const ;
        vector<brique*> brique() const ;
        Raquette* Raquette() const ;
        balle* balle() const ;
        vector<rectangle*> rectangle() const ;
        void run(double dt,afficheur* d);
        void initializer_Murs(double hauteurMure);
        void initializer_Briques(int nombreColone,int nombreLigne,double hauteurMure);
        void initializer_Raquette(double hauteurRaquette,double largeurRaquette);
        void initializer_Balle();
        void initializer_Balle(geom::vector & vect,double vitesse);
        double hauteur() const;
        double largeur()const;
        Terrain* terrain();
        void afficheRectangle(afficheur* d);
        void afficheRaquette(afficheur* d);
        void afficheBriques(afficheur* d);
        void afficheBalle(afficheur* d);
        void RaquetteMoveGauche();
        void RaquetteMoveDroit();



    protected:

    private:
        vector<unique_ptr<cassebrique::rectangle>> d_rectangle;
        unique_ptr<cassebrique::balle> d_balle;
        unique_ptr<cassebrique::Raquette> d_raquette;
        double d_largeur;
        double d_hauteur;

};
}
#endif // TERRAIN_H
