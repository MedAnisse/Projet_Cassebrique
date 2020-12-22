#include "doctest.h"
#include"point.h"
#include "rectangle.h"
using geom::point;
using cassebrique::rectangle;
TEST_CASE("la creation d'objet rectangle s'exécute correctement")
{

    SUBCASE("le constructeur par défaut s'exécute correctement")
    {   rectangle m{};

         SUBCASE("L'objet rectangle est différent de null")
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
    }
    point a{1.0,2.0};
    point b{0.0,0.0};
    double hauteur{2.0},largeur{1.0};
    SUBCASE("le constructeur a deux point s'exécute correctement")
    {rectangle m{b,a};

        SUBCASE("L'objet rectangle est différent de null")
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


}
 SUBCASE("le constructeur de point,une hauteur et largeur s'exécute correctement")
    {rectangle m{b,hauteur,largeur};
        SUBCASE("L'objet rectangle est différent de null")
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


}
}


