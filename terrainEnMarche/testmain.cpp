/*#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"*/
#include <iostream>
#include"Terrain.h"
#include"Raquette.h"
#include"memory"
#include"rectangle.h"
#include "graphics.h"
#include "afficheurWinBgi.h"
using std::cout;
using cassebrique::Terrain;
int main()
    {
    Terrain t{700,890,5,5,10,10,100};


    cassebrique::afficheurWinBgi* affiche =new cassebrique::afficheurWinBgi();
    t.run(0.01,affiche);

}

