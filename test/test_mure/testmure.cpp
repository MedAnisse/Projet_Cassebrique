#include "mure.h"
#include "doctest.h"
#include"point.h"
#include"surface.h"
#include"surfaceNormal.h"
#include"surfaceTueuse.h"
#include "rectangle.h"
#include"balle.h"
#include<memory>
#include<iostream>
using geom::point;
using cassebrique::mure;
using cassebrique::surface;
using cassebrique::surfaceNormal;
using cassebrique::surfaceTueuse;
using cassebrique::rectangle;
void SurfaceNormalSinitialiseCorrectement(mure & m)
{
     REQUIRE_EQ((dynamic_cast<surfaceNormal*> (m.surfaceType())==NULL),false );
}
void LespointsDeMurSinitialiseCorrectement(mure& m , point& BasGauche, point& HautDroit)
{
    REQUIRE_EQ(m.BasGauche(),BasGauche );
    REQUIRE_EQ(m.HautDroit(),HautDroit );
}
TEST_CASE("la creation d'objet mure s'exécute correctement")
{

    SUBCASE("Surface Type s'initialise par défaut correctement")
    {   mure m{};
           SurfaceNormalSinitialiseCorrectement(m);
    }
        point BasGauche {0.0,0.0};
        double hauteur{2.0},largeur{1.0};
    SUBCASE("le constructeur a deux point s'exécute correctement")
    {
        point HautDroit {1.0,2.0};
        std::unique_ptr<cassebrique::surface> tsurfaceNormal =std::make_unique<cassebrique::surfaceNormal>();
        mure m{BasGauche,HautDroit,tsurfaceNormal};
         SUBCASE("Surface Type s'initialise correctement")
         {
            SurfaceNormalSinitialiseCorrectement(m);
         }
          SUBCASE("Les points de mur  s'initialise correctement  ")
         {
             LespointsDeMurSinitialiseCorrectement(m,BasGauche,HautDroit);
         }
    }


 SUBCASE("le constructeur de point,une hauteur et largeur s'exécute correctement")
    {
        std::unique_ptr<surface>tsurfaceNormal= std::make_unique<surfaceTueuse>();
        mure m{BasGauche,hauteur,largeur,tsurfaceNormal};
         SUBCASE("Surface Type s'initialise par défaut correctement")
         {
             REQUIRE_EQ((dynamic_cast<surfaceTueuse*> (m.surfaceType())==NULL),false );
         }
          SUBCASE("Les points de mur  s'initialise correctement  ")
         {
             double HautDroit_x=BasGauche.x()+largeur;
             double HautDroit_y=BasGauche.y()+hauteur;
             point HautDroit{HautDroit_x,HautDroit_y};
             LespointsDeMurSinitialiseCorrectement(m,BasGauche,HautDroit);
         }
    }

}

TEST_CASE("On collusion s'exécute correctement")
{
    point positionBalle{0.0,0.0};
    geom::vector vectorPostionBalle{1.0,1.0};
    double vitesseBalle{2.0},rayonBalle{2.0};
    cassebrique::balle b{positionBalle,vectorPostionBalle,vitesseBalle,rayonBalle};
    mure m{};
    REQUIRE_EQ(m.OnCollusion(b),true );
}


