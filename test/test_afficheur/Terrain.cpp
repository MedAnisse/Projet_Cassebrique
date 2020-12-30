#include "Terrain.h"
#include"graphics.h"
#include<vector>
#include"vector.h"
#include<iostream>
#include<memory>
#include "surfaceDure.h"
#include "surfaceNormal.h"
#include "surfaceMolle.h"
#include "surface.h"
#include "surfaceTueuse.h"
#include "brique.h"
#include"mure.h"
#include "Raquette.h"
#include"list.h"
#include "balle.h"
#include"briqueCassable.h"
#include"briqueCassableApresPlusieurFois.h"
#include"briqueIncassable.h"
#include"afficheur.h"
#include"balle.h"
using std::vector;
using std::make_unique;
using std::cout;
using std::endl;
namespace cassebrique
{
 unique_ptr<surface>  Terrain::randomSurface()
{
    int randNum = rand()%(2+ 1) ;
    switch(randNum)
    {
       case 0:
           return make_unique<surfaceDure>();
        break;
        case 1:
           return make_unique<surfaceNormal>();
        break;
        case 2:
          return  make_unique<surfaceMolle>();
        break;
    }
}
brique*  Terrain::randomBrique(point &position,double largeur,double hauteurBrique)
{
    int randNum = rand()%(2+ 1) ;

    switch(randNum)
    {
       case 0:
           return new briqueCassable (position,hauteurBrique,largeur,randomSurface());
        break;
        case 1:
           return new briqueIncassable (position,hauteurBrique,largeur,randomSurface());
        break;
        case 2:
            int n=5;
          return  new briqueCassableApresPlusieurFois (n,position,hauteurBrique,largeur,randomSurface());
        break;
    }
    return nullptr;
}
void Terrain::initializer_Murs(double hauteur)
{
    point a{0.0,hauteur};
    point b{d_largeur,0.0};
    unique_ptr<surface> t=make_unique<surfaceNormal>(a,b);
    d_mures.push_back(make_unique<cassebrique::mure>(a,b,t));
    a=point(0.0,d_hauteur-hauteur);
    b=point(hauteur,hauteur);
    t=make_unique<surfaceNormal>(a,b);
    d_mures.push_back(make_unique<cassebrique::mure>(a,b,t));    a=point(d_largeur-hauteur,+d_hauteur-hauteur);
    a=point(d_largeur-hauteur,d_hauteur-hauteur);
    b=point(d_largeur,+hauteur);
     t=make_unique<surfaceNormal>(a,b);
    d_mures.push_back(make_unique<cassebrique::mure>(a,b,t));
    a=point(0.0,+d_hauteur);
    b=point(d_largeur,d_hauteur-hauteur );
     t=make_unique<surfaceTueuse>(a,b);
    d_mures.push_back(make_unique<cassebrique::mure>(a,b,t));
}
void Terrain::initializer_Briques(int nombreColone,int nombreLigne,double hauteurMure)
{


    double largeurBrique=(d_largeur-(2*hauteurMure))/nombreColone ;
    largeurBrique-=1.1;
    double hauteurBrique=(d_hauteur-2*hauteurMure)/(2*nombreLigne) ;

    cout<<"largeurbrique= "<<largeurBrique<<"  hauteurBrique  ="<<hauteurBrique;
    point position{hauteurMure+1,hauteurMure+1};
double x{hauteurMure+1},y{hauteurMure+1};
    //vector<unique_ptr<surface>>t;
    for(int i=0;i<nombreLigne;i++)
    {
      for(int j=0;j<nombreColone;j++)
        {
            cout<<" 1 position= "<<position<<endl;
            d_briques.push_back(randomBrique(position,largeurBrique,hauteurBrique));
            x+=largeurBrique+1;
            y=position.y();
            position.moveTo(x,y);

        }
        x=hauteurMure+1;
        y+=hauteurBrique+1;
      position.moveTo(x,y);
      cout<<"2 position= "<<position<<endl;
    }
}
void Terrain::initializer_Raquette(double hauteurRaquette,double largeurRaquette,double hauteurMure)
{
  double positionRaquette_x=d_largeur/2;
  double positionRaquette_y=d_hauteur-hauteurRaquette-hauteurMure;
  point positionRaquette{positionRaquette_x,positionRaquette_y};
  //raquette(point , hauteur,largeur,surface)
  d_raquette=make_unique<cassebrique::Raquette>(positionRaquette,hauteurRaquette,largeurRaquette);
}
void Terrain::initializer_Balle()
{
    d_balle=make_unique<cassebrique::balle>();
}
void Terrain::initializer_Balle(geom::vector & vect,double vitesse)
{
 //balle(point(x,y),vecteurposition(dx,dy),vitesse)
 double k=d_hauteur/2;
 double v=d_largeur/2;
 point t{k,v};
 double r=5;
    d_balle=make_unique<cassebrique::balle>(t,vect,vitesse,r);
    //point(d_hauteur/2,d_largeur/2) = centre de terain
}
Terrain::Terrain(double hauteurTerrain, double largeurTerrain,int nombreColone,int nombreLigne,double hauteurMure,double hauteurRaquette,double largeurRaquette):
    d_largeur{largeurTerrain},
    d_hauteur{hauteurTerrain},
    d_mures{},
    d_briques{},
    d_raquette{}
{
  initializer_Murs(hauteurMure);

  initializer_Raquette(hauteurRaquette,largeurRaquette,hauteurMure);

  initializer_Briques(nombreColone,nombreLigne,hauteurMure);

}
double Terrain::hauteur() const
{
  return d_hauteur;
}
double Terrain::largeur()const
{
  return d_largeur;
}
Terrain::~Terrain()
{}
vector<cassebrique::mure*> Terrain::mure() const
{vector<cassebrique::mure*> t;
for(auto& i : d_mures)
    {
        cassebrique::mure* k = dynamic_cast<cassebrique::mure*>(i.get());
        if(k!=nullptr)
        {
            t.push_back(k);
        }
    }

    return t;
}

Raquette* Terrain::Raquette() const
{

    return d_raquette.get();
}
balle* Terrain::balle() const
{
    return d_balle.get();
}

Terrain* Terrain::terrain()
{
    return this;
}
vector<rectangle*> Terrain::rectangle() const
{
  std::vector<cassebrique::rectangle*>vecteurTmp{};
    element* tmp =d_briques.tete;
    while(tmp!=nullptr)
    {

        vecteurTmp.push_back(new cassebrique::rectangle( tmp->info->BasGauche(),tmp->info->HautDroit()));
        tmp=tmp->next;
    }

  for(auto& i : d_mures)
   {
       vecteurTmp.push_back(i.get());
   }
  return vecteurTmp;
}
void Terrain::run(double dt,afficheur* affiche)
{double temp=dt;
    afficheRectangle(affiche);
    afficheRaquette(affiche);
     while(1)
     {
         //d_balle->position(temp);

            char i='g';
         //afficheBalle(affiche);
          i=affiche->caractereEntree();
         if(i=='d' )
         {
            affiche->effacerContenu();
            RaquetteMoveDroit();
            afficheRectangle(affiche);
            afficheRaquette(affiche);
         }
          if(i=='a' )
         {
             affiche->effacerContenu();
             RaquetteMoveGauche();
             afficheRectangle(affiche);
            afficheRaquette(affiche);
         }

         temp+=dt;
     }

}
void Terrain::afficheRectangle(afficheur*  d)
{
    vector<cassebrique::rectangle*>vecteurTmp=rectangle();
    for(auto& i : vecteurTmp)
       {
            d->afficherRectangle(i);
       }
}
void Terrain::afficheRaquette(afficheur*  d)
{

    d->afficherRaquette(d_raquette.get());
}
void Terrain::afficheBriques(afficheur*  d)
{

}
void Terrain::afficheBalle(afficheur*  d)
{
    d->afficherBalle(balle());
}
void Terrain::RaquetteMoveGauche()
{
    d_raquette->move_Gauche();
}
void Terrain::RaquetteMoveDroit()
{
    d_raquette->move_Droit();
}
void Terrain::existColusion(cassebrique::balle& b)
{
    bool k;
    for(int i=0,taillTab=d_mures.size() ;i<taillTab;i++)
    {
    //  p=  d_mures[i]->OnCollusion(b);
    cassebrique::mure* p= dynamic_cast<cassebrique::mure*>(d_mures[i].get());
    if(p!=nullptr)
    {
        k= p->OnCollusion(b);
    }
    }
    list tmp =d_briques;
    int i=0;
    element* eleTmp=tmp.tete;
    while(eleTmp!=nullptr)
    {
        cassebrique::brique* p= dynamic_cast<cassebrique::brique*>(eleTmp->info);
    if(p!=nullptr)
    {
        k= p->OnCollusion(b);
    }
     cassebrique::briqueCassable* tmp2= dynamic_cast<cassebrique::briqueCassable*>(eleTmp->info);
        if(tmp2!=nullptr)
        {
            d_briques.erase(i);
        }
        ++i;
        eleTmp=eleTmp->next;
    }
   k = d_raquette->OnCollusion(b);
}
}
