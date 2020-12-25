#include "doctest.h"
#include "point.h"
#include <iostream>
using namespace std;

TEST_CASE("Tests des points") {

 SUBCASE("verifions si un point a les bonnes coordonnees"){

   double x{7.9},y{-11.2};
   point p{x,y};
   REQUIRE_EQ(p.x(), x);
   REQUIRE_EQ(p.y(), y);
 }

}

TEST_CASE("Tests des points") {

 SUBCASE("verifions si un point par defautt a des coordonnees nulles"){

   point p{};
   REQUIRE_EQ(p.x(), 0.0);
   REQUIRE_EQ(p.y(), 0.0);

 }

}

TEST_CASE("Tests des points") {

   SUBCASE("Afficher  si le point a les bonnes coordonnees"){

      double x{7.9},y{-11.2};

      point p{x,y};

      REQUIRE_EQ(p.x(), x);

      REQUIRE_EQ(p.y(), y);

        cout<<endl<<"l'abscisse x  et l'abscisse y: "<<endl;
           SUBCASE("") {
                cout << x << endl;
           SUBCASE("") { cout << y << endl; }

      }
   }

}
