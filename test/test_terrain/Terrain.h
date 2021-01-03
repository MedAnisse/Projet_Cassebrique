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
#include"list.h"
#include"balle.h"
#include"afficheurWinBgi.h"
using std::vector;
using std::unique_ptr;


namespace cassebrique
{
class Terrain
{
    public:
        Terrain();
        Terrain(double hauteurTerrain, double largeurTerrain);
        Terrain(double hauteurTerrain, double largeurTerrain,int nombreColone,int nombreLigne,double hauteurMure,double hauteurRaquette,double largeurRaquette);
        virtual ~Terrain();
        unique_ptr<surface> randomSurface();
        brique*  randomBrique(point &position,double largeur,double hauteurBrique,int nombreFois=5);
        Terrain* terrain();
        vector<mure*> mures() const ;
        list briques()const;
        vector<rectangle*> rectangle() const ;
        Raquette* Raquette() const ;
        balle* balle() const ;
        double hauteur() const;
        double largeur()const;
        void initializer_Murs(double hauteurMure);
        void initializer_Briques(int nombreColone,int nombreLigne,double hauteurMure);
        void initializer_Raquette(double hauteurRaquette,double largeurRaquette,double hauteurMure);
        void initializer_Balle(double vitesse = 30.0);
        void afficheRectangle(afficheur* affiche);
        void afficheRaquette(afficheur* affiche);
        void afficheBalle(afficheur* affiche);
        void RaquetteMoveGauche();
        void RaquetteMoveDroit();
        void run(double dt,afficheur* affiche);
        void existColusion(cassebrique::balle* b);


    private:
        vector<unique_ptr<cassebrique::mure>>  d_mures;
        list  d_briques;
        unique_ptr<cassebrique::balle> d_balle;
        unique_ptr<cassebrique::Raquette> d_raquette;
        double d_largeur;
        double d_hauteur;

};
}
#endif // TERRAIN_H
