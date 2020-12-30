#include "rectangle.h"
#include  "Raquette.h"
#include   "balle.h"
#include"brique.h"
#include "graphics.h"
#include<iostream>
#include<vector>
#include "afficheurWinBgi.h"
namespace cassebrique
{
    afficheurWinBgi::afficheurWinBgi()
{
    //ctor
}

afficheurWinBgi::~afficheurWinBgi()
{
    //dtor
}
void afficheurWinBgi::afficherRectangle(cassebrique::rectangle* terain)const
{
        ::setcolor(60);
      int left =(int)terain->BasGauche().x();
      if(left<0){left=-left;}
      int top=(int)terain->BasGauche().y();
       if(top<0){top=-top;}
      int reight=(int)terain->HautDroit().x();
      if(reight<0){reight=-reight;}
      int bootom=(int)terain->HautDroit().y();
      if(bootom<0){bootom=-bootom;}
    ::bar(left,top,reight,bootom);
}
void afficheurWinBgi::afficherRaquette(cassebrique::Raquette* raquette)const
{
    afficherRectangle(raquette);
}
void afficheurWinBgi::afficherBrique(cassebrique::brique* brique)const
{
    ::setcolor(200);
    afficherRectangle(brique);
}
void afficheurWinBgi::afficherBalle(cassebrique::balle* balle)const
{int x{(int)balle->position().x()},y{(int)balle->position().y()},radius{(int)balle->rayon()};
    ::circle(x,y,radius);
}
void afficheurWinBgi::effacerContenu()const
{
    ::clearviewport();
}
char afficheurWinBgi::caractereEntree()const
{
    int i =0;
    //changement au niveau du handle_input(false) au lieu de handle_input(true)
    // pour que nous attend pas utilisateur qui entre une valeur
    i=::getch();
    std::cout<<i<<" ";
    if(i==100){std::cout<<std::endl;return 'd';}
    if(i==97){std::cout<<std::endl;return 'a';}
    return 'g';
}
}
