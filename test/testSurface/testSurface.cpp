#include "doctest.h"
#include"point.h"
#include "surface.h"
#include "surfaceDure.h"
#include "surfaceMolle.h"
#include "surfaceTueuse.h"
#include "balle.h"

TEST_CASE("La creation de l'objet surface s'execute correctement")
{
    SUBCASE("Les conctructeurs par défaut s'execute correctement")
    {
        surface s{};
        surfaceDure d{};
        surfaceMolle m{};
        surfaceTueuse t{};
        SUBCASE("L'objet surface normal est différent de null")
        {
            REQUIRE_EQ((&s==NULL),false );
        }
        SUBCASE("L'objet surface molle est différent de null ")
        {
            REQUIRE_EQ((&m==NULL),false );
        }
        SUBCASE("L'objet surface dure est différent de null")
        {
            REQUIRE_EQ((&d==NULL),false );
        }
        SUBCASE("L'objet surface tueuse est différent de null ")
        {
            REQUIRE_EQ((&t==NULL),false );
        }
    }
    SUBCASE("creation d'un objet à partir de deux points est correcte")
    {
        geom::point a{5,2};
        geom::point b{3,2};
        SUBCASE("la création de l'objet surface avec deux points")
        {
            surface s{a,b};
            REQUIRE_EQ(s.a(), a);
            REQUIRE_EQ(s.b(), b);
        }
        SUBCASE("la création de l'objet surface avec deux points")
        {
            surfaceMolle m{a,b};
            REQUIRE_EQ(m.a(), a);
            REQUIRE_EQ(m.b(), b);
        }
        SUBCASE("la création de l'objet surface avec deux points")
        {
            surfaceTueuse t{a,b};
            REQUIRE_EQ(t.a(), a);
            REQUIRE_EQ(t.b(), b);
        }
        SUBCASE("la création de l'objet surface avec deux points")
        {
            surfaceDure d{a,b};
            REQUIRE_EQ(d.a(), a);
            REQUIRE_EQ(d.b(), b);
        }

    }
}
TEST_CASE("le calcul de la distance est correcte")
{
    balle balle{4,3,1};
    geom::point a{5,2};
    geom::point b{5,4};
    surface s{a,b};
    REQUIRE_EQ(s.distance(balle),0);
}
TEST_CASE("le test de collision est correcte")
{
    balle balle{4,3,1};
    geom::point a{5,2};
    geom::point b{5,4};
    surface s{a,b};
    surfaceMolle m{a,b};
    surfaceTueuse t{a,b};
    surfaceDure d{a,b};
    REQUIRE_EQ(s.collision(balle),true);
    REQUIRE_EQ(m.collision(balle),true);
    REQUIRE_EQ(t.collision(balle),true);
    REQUIRE_EQ(d.collision(balle),true);
}

TEST_CASE("Changement de position de position des deux points est correcte")
{
  geom::point a{5,2};
  geom::point b{3,2};
  surface s{a,b};
  geom::point z{12,5};
  geom::point j{10,5};
  s.moveTo(z,j);
  REQUIRE_EQ(s.a(),z);
  REQUIRE_EQ(s.b(),j);
}

TEST_CASE("La copie des surfaces est correcte")
{
  geom::point a{5,2};
  geom::point b{3,2};
  surface s{a,b};
  s.copie();
  REQUIRE_EQ(s.a(),a);
  REQUIRE_EQ(s.b(),b);
}




