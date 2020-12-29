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
#include "balle.h"
#include"briqueCassable.h"
#include"briqueCassableApresPlusieurFois.h"
#include"briqueIncassable.h"
#include"afficheur.h"
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
unique_ptr<brique>  Terrain::randomBrique(point &position,double largeur,double hauteurBrique)
{
    int randNum = rand()%(2+ 1) ;

    switch(randNum)
    {
       case 0:
           return make_unique<briqueCassable>(position,hauteurBrique,largeur,randomSurface());
        break;
        case 1:
           return make_unique<briqueIncassable>(position,hauteurBrique,largeur,randomSurface());
        break;
        case 2:
            int n=5;
          return  make_unique<briqueCassableApresPlusieurFois>(n,position,hauteurBrique,largeur,randomSurface());
        break;
    }
    return nullptr;
}
void Terrain::initializer_Murs(double hauteur)
{
    point a{0.0,hauteur};
    point b{d_largeur,0.0};
    unique_ptr<surface> t=make_unique<surfaceNormal>(a,b);
    d_rectangle.push_back(make_unique<cassebrique::mure>(a,b,t));
    a=point(0.0,d_hauteur-hauteur);
    b=point(hauteur,hauteur);
    t=make_unique<surfaceNormal>(a,b);
    d_rectangle.push_back(make_unique<cassebrique::mure>(a,b,t));    a=point(d_largeur-hauteur,+d_hauteur-hauteur);
    a=point(d_largeur-hauteur,d_hauteur-hauteur);
    b=point(d_largeur,+hauteur);
     t=make_unique<surfaceNormal>(a,b);
    d_rectangle.push_back(make_unique<cassebrique::mure>(a,b,t));
    a=point(0.0,+d_hauteur);
    b=point(d_largeur,d_hauteur-hauteur );
     t=make_unique<surfaceTueuse>(a,b);
    d_rectangle.push_back(make_unique<cassebrique::mure>(a,b,t));
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
            d_rectangle.push_back(randomBrique(position,largeurBrique,hauteurBrique));
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
void Terrain::initializer_Raquette(double hauteurRaquette,double largeurRaquette)
{
  double k=d_largeur/2;
  double v=d_hauteur-hauteurRaquette;
  point p{k,v};
  //raquette(point , hauteur,largeur,surface)
  d_raquette=make_unique<cassebrique::Raquette>(p,hauteurRaquette,largeurRaquette);
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
    d_rectangle{},
    d_raquette{}
{
  initializer_Murs(hauteurMure);
  std::cout<<"je";
  initializer_Raquette(hauteurRaquette,largeurRaquette);
  cout<<"tu";
  initializer_Briques(nombreColone,nombreLigne,hauteurMure);
  cout<<"il";
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
vector<mure*> Terrain::mure() const
{vector<cassebrique::mure*> t;
for(auto& i : d_rectangle)
    {
        cassebrique::mure* k = dynamic_cast<cassebrique::mure*>(i.get());
        if(k!=nullptr)
        {
            t.push_back(k);
        }
    }

    return t;
}
vector<brique*> Terrain::brique() const
{
    vector<cassebrique::brique*> t;
for(auto& i : d_rectangle)
    {
        cassebrique::brique* k = dynamic_cast<cassebrique::brique*>(i.get());
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
  vector<cassebrique::rectangle*> t;
  for(auto& i : d_rectangle)
    t.push_back(i.get());
  return t;
}
void Terrain::run(double dt,afficheur* affiche)
{double temp=dt;

     while(1)
     {
         //d_balle->position(temp);

        afficheRectangle(affiche);
        afficheRaquette(affiche);
         //afficheBalle(affiche);
          char i=affiche->caractereEntree();
          cout<<i<<std::endl;
         if(i=='d' )
         {
            RaquetteMoveDroit();
         }
          if(i=='a' )
         {
            RaquetteMoveGauche();
         }
         affiche->effacerContenu();
         temp+=dt;
     }

}
void Terrain::afficheRectangle(afficheur*  d)
{
    for(auto& i : d_rectangle)
       {
            d->afficherRectangle(i.get());
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
}
