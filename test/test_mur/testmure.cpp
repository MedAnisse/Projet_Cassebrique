#include "mur.h"
#include "doctest.h"
#include"point.h"
#include"surface.h"
#include"surface.h"
#include"surfaceTueuse.h"
#include "rectangle.h"
#include"balle.h"
#include<memory>
#include<iostream>
using geom::point;
using cassebrique::mur;
using cassebrique::surface;
using cassebrique::surface;
using cassebrique::surfaceTueuse;
using cassebrique::rectangle;

void LespointsDeMurSinitialiseCorrectement(mur& m , point& BasGauche, point& HautDroit)
{
    REQUIRE_EQ(m.BasGauche(),BasGauche );
    REQUIRE_EQ(m.HautDroit(),HautDroit );
}
TEST_CASE("la creation d'objet mur s'exécute correctement")
{
        point BasGauche {0.0,0.0};
        double hauteur{2.0},largeur{1.0};
    SUBCASE("le constructeur a deux point s'exécute correctement")
    {
        point HautDroit {1.0,2.0};
        std::unique_ptr<cassebrique::surface> tsurface =std::make_unique<cassebrique::surface>();
        mur m{BasGauche,HautDroit,tsurface};
          SUBCASE("Les points de mur  s'initialise correctement  ")
         {
             LespointsDeMurSinitialiseCorrectement(m,BasGauche,HautDroit);
         }
    }


 SUBCASE("le constructeur de point,une hauteur et largeur s'exécute correctement")
    {
        std::unique_ptr<surface>tsurface= std::make_unique<surfaceTueuse>();
        mur m{BasGauche,hauteur,largeur,tsurface};
          SUBCASE("Les points de mur  s'initialise correctement  ")
         {
             double HautDroit_x=BasGauche.x()+largeur;
             double HautDroit_y=BasGauche.y()+hauteur;
             point HautDroit{HautDroit_x,HautDroit_y};
             LespointsDeMurSinitialiseCorrectement(m,BasGauche,HautDroit);
         }
         SUBCASE("Le type de surface de mur  s'initialise correctement  ")
         {
             surfaceTueuse* tmpsurface=dynamic_cast<surfaceTueuse*>( m.surfaceType());
             REQUIRE_EQ((tmpsurface==NULL),false);
         }
    }

}



