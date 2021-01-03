#include "Terrain.h"
#include"graphics.h"
#include<vector>
#include"vector.h"
#include<iostream>
#include<memory>
#include "surfaceDure.h"
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
  Terrain::Terrain()
    {
      Terrain(700,900,5,5,10,20,40);
    }
    Terrain::Terrain(double hauteurTerrain, double largeurTerrain)
    {
      Terrain(hauteurTerrain,largeurTerrain,5,5,10,20,40);
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
      initializer_Balle();
    }
unique_ptr<surface>  Terrain::randomSurface()
{
  int randNum = rand()%(2+ 1) ;
  switch(randNum)
    {
      case 0:
        return make_unique<surfaceDure>();
          break;
      case 1:
        return make_unique<surface>();
          break;
      case 2:
        return  make_unique<surfaceMolle>();
          break;
    }
}
brique*  Terrain::randomBrique(point &position,double largeur,double hauteurBrique,int nombreFois)
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
        return  new briqueCassableApresPlusieurFois (nombreFois,position,hauteurBrique,largeur,randomSurface());
          break;
    }
    return nullptr;
}
void Terrain::initializer_Murs(double hauteur)
{
    point a{0.0,hauteur};
    point b{d_largeur,0.0};
    unique_ptr<surface> t=make_unique<surface>(a,b);
    d_mures.push_back(make_unique<cassebrique::mure>(a,b,t));
    a=point(0.0,d_hauteur-hauteur);
    b=point(hauteur,hauteur);
    t=make_unique<surface>(a,b);
    d_mures.push_back(make_unique<cassebrique::mure>(a,b,t));    a=point(d_largeur-hauteur,+d_hauteur-hauteur);
    a=point(d_largeur-hauteur,d_hauteur-hauteur);
    b=point(d_largeur,+hauteur);
     t=make_unique<surface>(a,b);
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

    //cout<<"largeurbrique= "<<largeurBrique<<"  hauteurBrique  ="<<hauteurBrique;
    point position{hauteurMure+1,hauteurMure+1};
    double x{hauteurMure+1},y{hauteurMure+1};
    for(int i=0;i<nombreLigne;i++)
    {
      for(int j=0;j<nombreColone;j++)
        {
            //cout<<" 1 position= "<<position<<endl;
            d_briques.push_back(randomBrique(position,largeurBrique,hauteurBrique));
            x+=largeurBrique+1;
            y=position.y();
            position.moveTo(x,y);

        }
        x=hauteurMure+1;
        y+=hauteurBrique+1;
      position.moveTo(x,y);
      //cout<<"2 position= "<<position<<endl;
    }
}
void Terrain::initializer_Raquette(double hauteurRaquette,double largeurRaquette,double hauteurMure)
{
  double positionRaquetteX=d_largeur/2;
  double positionRaquetteY=d_hauteur-hauteurRaquette-hauteurMure;
  point positionRaquette{positionRaquetteX,positionRaquetteY};
  d_raquette=make_unique<cassebrique::Raquette>(positionRaquette,hauteurRaquette,largeurRaquette);
}
void Terrain::initializer_Balle(double vitesse)
{
 double positionBalleY=d_hauteur/2;
 double positionBalleX=d_largeur/2;
 point positionBalle{positionBalleX,positionBalleY};
 double rayonBalle=5;
 double ongleBalle=0.25;
    d_balle=make_unique<cassebrique::balle>(positionBalle,ongleBalle,vitesse,rayonBalle);
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
vector<cassebrique::mure*> Terrain::mures() const
{
  vector<cassebrique::mure*> tmpMures;
  for(auto& i : d_mures)
    {
      cassebrique::mure* tmpMure = dynamic_cast<cassebrique::mure*>(i.get());
      if(tmpMure!=nullptr)
        {
          tmpMures.push_back(tmpMure);
        }
    }

  return tmpMures;
}
list Terrain::briques()const
{
    return d_briques;
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
  std::vector<cassebrique::rectangle*> tmpRectangles= d_briques.tovector();
  for(auto& i : d_mures)
   {
    tmpRectangles.push_back(i.get());
   }
  return tmpRectangles;
}

void Terrain::afficheRectangle(afficheur*  affiche)
{
    vector<cassebrique::rectangle*>tmpRectangle=rectangle();
    for(auto& i : tmpRectangle)
      {
        affiche->afficherRectangle(i);
      }
}
void Terrain::afficheRaquette(afficheur*  affiche)
{
  affiche->afficherRaquette(d_raquette.get());
}
void Terrain::afficheBalle(afficheur*  affiche)
{
  affiche->afficherBalle(balle());
}
void Terrain::RaquetteMoveGauche()
{
  d_raquette->move_Gauche();
}
void Terrain::RaquetteMoveDroit()
{
  d_raquette->move_Droit();
}
void Terrain::run(double dt,afficheur* affiche)
{
  double temp=dt;
  afficheRectangle(affiche);
  afficheRaquette(affiche);
  while(1)
    {
      //cout<<endl<<"distace = "<<d_raquette->distance(d_balle->position(temp))<<endl;;
      affiche->effacerContenu();
      afficheBalle(affiche);
      afficheRectangle(affiche);
      afficheRaquette(affiche);
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
void Terrain::existColusion(cassebrique::balle* b)
{
  bool k;
  for(int i=0,taillTab=d_mures.size() ;i<taillTab;i++)
    {
      cassebrique::mure* p= dynamic_cast<cassebrique::mure*>(d_mures[i].get());
      if(p!=nullptr)
        {
          k= p->OnCollusion(b);
        }
    }
  vector<cassebrique::rectangle*> f= d_briques.tovector();
    for(int i=0,len=f.size();i<i;i++)
      {
        cassebrique::brique* p= dynamic_cast<cassebrique::brique*>(f[i]);
        if(p!=nullptr)
        {
          k= p->OnCollusion(b);
        }
        cassebrique::briqueCassable* tmp2= dynamic_cast<cassebrique::briqueCassable*>(f[i]);
        if(tmp2!=nullptr)
          {
            d_briques.erase(i);
          }
      }
   /* list tmp =d_briques;
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
    }*/

  k = d_raquette->OnCollusion(b);
}
}
