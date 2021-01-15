#include <memory>
#include<iostream>
#include "brique.h"
#include"rectangle.h"
#include"surface.h"
#include"balle.h"
using std::unique_ptr;
using std::move;
namespace cassebrique
{
    void  brique::initializerLesSurfaces(unique_ptr<surface>surfaceK)
     {
         unique_ptr<surface>t,k;
         t=surfaceK->copy();
         point BasDroit{d_HautDroit.x(),d_BasGauche.y()};
         point HautGauche{d_BasGauche.x(),d_HautDroit.y()};
         surfaceK->moveTo(d_HautDroit,HautGauche);
         d_surface.push_back(move(surfaceK));
         t->moveTo(d_BasGauche,HautGauche);
         k=t->copy();
         d_surface.push_back(move(t));
          k->moveTo(HautGauche,d_HautDroit);
         t=k->copy();
         d_surface.push_back(move(k));
         t->moveTo(d_HautDroit,BasDroit);
         d_surface.push_back(move(t));
     }
    brique::~brique()
    {

    }
    brique::brique():rectangle{},d_surface {}{}
    brique::brique(point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK):
        rectangle{BasGauche,HautDroit}
        {
            initializerLesSurfaces(move(surfaceK));
        }
    brique::brique(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK):
     rectangle{BasGauche,hauteur,largeur}
        {
            initializerLesSurfaces(move(surfaceK));
        }
        bool brique::OnCollision(balle* balle)
        {
            bool k;
            for(auto&e : d_surface)
            {
               k= e->collision(balle);
            }
            return k;
        }
}
