#include "doctest.h"
#include "Terrain.h"
#include"graphics.h"
#include<vector>
#include"vector.h"
#include<iostream>
#include<memory>
#include "surfaceDure.h"
#include "surfaceMolle.h"
#include "surface.h"
#include "surfaceTueuse.h"
#include "brique.h"
#include"mur.h"
#include "Raquette.h"
#include"list.h"
#include "balle.h"
#include"briqueCassable.h"
#include"briqueCassableApresPlusieurFois.h"
#include"briqueIncassable.h"
#include"afficheur.h"
#include"balle.h"
#include<string>
using std::string;
using geom::point;
using cassebrique::rectangle;
using cassebrique::Terrain;
using cassebrique::surface;
using cassebrique:: surfaceTueuse;
using cassebrique::mur;
using cassebrique::brique;
using cassebrique::Raquette;

using std::vector;
   double hauteurTerrain=700;
    double largeurTerrain=900;
    int nombreColone=5;
    int nombreLigne=5;
    double hauteurmur=10;
    double hauteurRaquette=20;
    double largeurRaquette=30;
    Terrain TerrainTest{hauteurTerrain,largeurTerrain,nombreColone,nombreLigne,hauteurmur,hauteurRaquette,largeurRaquette};
TEST_CASE("La creation d'objet Terrain s'exécute correctement")
{
        SUBCASE("La creation de vecteur Murs s execute correctement")
        {
            vector<mur*> tmpmurs=TerrainTest.murs();
            SUBCASE("La taille vecteur Murs est correcte")
                {
                    REQUIRE_EQ(tmpmurs.size(),4 );
                }
            SUBCASE("Le type de la surface de dernier elelment de vecteur Murs est correcte")
                {
                    surface* tmpmurSurface= tmpmurs.back()->surfaceType();
                    surfaceTueuse* tmpSurface= dynamic_cast<surfaceTueuse*> (tmpmurSurface);
                    REQUIRE_EQ((tmpSurface==NULL),false );
                }
        }
        SUBCASE("La taille vecteur Briques est correcte")
                {
                    int tailleVecteurBriques=nombreColone*nombreLigne;
                    FAST_REQUIRE_EQ(TerrainTest.briques().tovector().size(),tailleVecteurBriques );
                }
         SUBCASE("La creation de Raquette s'exécute correctement")
        {
            Raquette* tmpRaquette=TerrainTest.Raquette();
            SUBCASE("L'objet Raquette est différent de null")
            {
                FAST_REQUIRE_EQ((tmpRaquette==NULL),false );
            }
            SUBCASE("La hauteur de Raquette est correcte")
            {
                FAST_REQUIRE_EQ(tmpRaquette->Hauteur(),hauteurRaquette );
            }
            SUBCASE("La largeur de Raquette est correcte")
            {
                FAST_REQUIRE_EQ(tmpRaquette->Largeur(),largeurRaquette );
            }
        }
        SUBCASE("La creation de Balle s'exécute correctement")
        {
            cassebrique::balle* tmpBalle=TerrainTest.balle();
            FAST_REQUIRE_EQ((tmpBalle==NULL),false );
        }
}

void testRaquetteMove(Terrain& TerrainTest,string direction)
{
point ancienBasGaucheRaquette=TerrainTest.Raquette()->BasGauche();
point ancienHautDroitRaquette=TerrainTest.Raquette()->HautDroit();
point testBasGaucheRaquette{0.0,0.0};
point testHautDroitRaquette{0.0,0.0};
if(direction.compare("Gauche")==0)
{
    TerrainTest.RaquetteMoveGauche();

    ancienBasGaucheRaquette.move(-10.0,0.0);
    testBasGaucheRaquette=ancienBasGaucheRaquette;
    ancienHautDroitRaquette.move(-10.0,0.0);
    testHautDroitRaquette=ancienHautDroitRaquette;
}
else if(direction.compare("Droit")==0)
{
    TerrainTest.RaquetteMoveDroit();
    ancienBasGaucheRaquette.move(+10.0,0.0);
    testBasGaucheRaquette=ancienBasGaucheRaquette;
    ancienHautDroitRaquette.move(+10.0,0.0);
    testHautDroitRaquette=ancienHautDroitRaquette;

}
point nouveauBasGaucheRaquette=TerrainTest.Raquette()->BasGauche();
point nouveauHautDroitRaquette=TerrainTest.Raquette()->HautDroit();
FAST_REQUIRE_EQ(nouveauBasGaucheRaquette,testBasGaucheRaquette );
FAST_REQUIRE_EQ(nouveauHautDroitRaquette,testHautDroitRaquette );
}
TEST_CASE("Le déplacement Raquette s'exécute correctement")
{
    Raquette* tmpRaquette=TerrainTest.Raquette();
    point ancienBasGaucheRaquette=tmpRaquette->BasGauche();
    point ancienHautDroitRaquette=tmpRaquette->HautDroit();
     SUBCASE("Le déplacement Raquette vers la gauche s'exécute correctement")
        {
            testRaquetteMove(TerrainTest,"Gauche");
        }
      SUBCASE("Le déplacement Raquette vers la droite s'exécute correctement")
        {
            testRaquetteMove(TerrainTest,"Droit");
        }
}
TEST_CASE("Existe collision s'exécute correctement")
{
    point position{779.373,684.373};
    double ongle=0.25;
    double vitesse=2.5;
    double rayon =9;
    cassebrique::balle* tmpBalle = new cassebrique::balle (position,ongle,vitesse,rayon);
    FAST_REQUIRE_EQ(TerrainTest.existColusion(tmpBalle),true);
}

