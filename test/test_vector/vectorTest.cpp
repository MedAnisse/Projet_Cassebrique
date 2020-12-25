#include "doctest.h"
#include "vector.h"
#include "point.h"
#include <iostream>

using namespace std;


TEST_CASE("Tests de vectors") {

 SUBCASE("verifions si un vector par defautt a des coordonnees nulles"){

    geom::vector v{};
   REQUIRE_EQ(v.x(), 0.0);
   REQUIRE_EQ(v.y(), 0.0);

 }

}

TEST_CASE("Tests de vectors") {

 SUBCASE("verifions si un vector a les bonnes coordonnees"){
     double x{11.2},y{-3.4};

    geom::vector v{x,y};
    REQUIRE_EQ(v.x(),x);
    REQUIRE_EQ(v.y(),y);
 }

}
TEST_CASE("Tests de vectors") {

   SUBCASE("Afficher  si un vector a les bonnes coordonnees"){

      double x{11.2},y{-3.4};

      geom::vector v{x,y};

      REQUIRE_EQ(v.x(), x);

      REQUIRE_EQ(v.y(), y);

        cout<<endl<<"----------------------------------- "<<endl;
           SUBCASE("") {
                cout<<"Coordonnee du vector x: " << x << endl;
           SUBCASE("") { cout<<"Coordonnee du vector y: " << y << endl; }
           }

      }
}
