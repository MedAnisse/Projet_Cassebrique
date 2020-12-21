#include "mure.h"
#include "doctest.h"
#include"point.h"
#include"surface.h"
#include"surfaceNormal.h"
#include"surfaceTueuse.h"
using geom::point;
using cassebrique::mure;
using cassebrique::surface;
using cassebrique::surfaceNormal;
using cassebrique::surfaceTueuse;
TEST_CASE("la creation d'objet mure s'exécute correctement")
{

    SUBCASE("le constructeur par défaut s'exécute correctement")
    {   mure m{};

         SUBCASE("L'objet mure est différent de null")
         {
             REQUIRE_EQ((&m==NULL),false );
         }
          SUBCASE("BasGauche s'exécute correctement ")
         {
             REQUIRE_EQ(m.BasGauche(),point(0.0,0.0) );
         }
         SUBCASE("HautDroit s'exécute correctement ")
         {
             REQUIRE_EQ(m.HautDroit(),point(0.0,0.0) );
         }
          SUBCASE("surface est différente de null ")
         {
             REQUIRE_EQ((m.surfaceType()==NULL),false );

         SUBCASE("Surface Type s'initialise par défaut correctement")
         {
             REQUIRE_EQ((dynamic_cast<surfaceNormal*> (m.surfaceType())==NULL),false );
         }
    }
    }
    point a{1.0,2.0};
    point b{0.0,0.0};
    double hauteur{2.0},largeur{1.0};
    SUBCASE("le constructeur a deux point s'exécute correctement")
    {mure m{b,a};

        SUBCASE("L'objet mure est différent de null")
         {
             REQUIRE_EQ((&m==NULL),false );
         }
          SUBCASE("BasGauche s'exécute correctement ")
         {
             REQUIRE_EQ(m.BasGauche(),b );
         }
         SUBCASE("HautDroit s'exécute correctement ")
         {
             REQUIRE_EQ(m.HautDroit(),a );
         }
          SUBCASE("surface est différente de null ")
         {
             REQUIRE_EQ((m.surfaceType()==NULL),false );

         SUBCASE("Surface Type s'initialise par défaut correctement")
         {
             REQUIRE_EQ((dynamic_cast<surfaceNormal*> (m.surfaceType())==NULL),false );
         }
    }

}
 SUBCASE("le constructeur de point,une hauteur et largeur s'exécute correctement")
    {mure m{b,hauteur,largeur,make_unique<surfaceTueuse>()};
        SUBCASE("L'objet mure est différent de null")
         {
             REQUIRE_EQ((&m==NULL),false );
         }
          SUBCASE("BasGauche s'exécute correctement ")
         {
             REQUIRE_EQ(m.Hauteur(),hauteur );
         }
         SUBCASE("HautDroit s'exécute correctement ")
         {
             REQUIRE_EQ(m.Largeur(),largeur );
         }
          SUBCASE("surface est différente de null ")
         {
             REQUIRE_EQ((m.surfaceType()==NULL),false );

         SUBCASE("Surface Type s'initialise par défaut correctement")
         {
             REQUIRE_EQ((dynamic_cast<surfaceTueuse*> (m.surfaceType())==NULL),false );
         }
    }

}
}
TEST_CASE("On collusion s'exécute correctement")
{
    //tester la colusion avec balle apres la creation de balle
    REQUIRE_EQ(true,true );
}


