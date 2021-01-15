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
#include"mur.h"
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
      Terrain(hauteurTerrain,largeurTerrain,5,5,20 ,20,40);
    }
  Terrain::Terrain(double hauteurTerrain, double largeurTerrain,int nombreColone,int nombreLigne,double hauteurmur,double hauteurRaquette,double largeurRaquette):
    d_largeur{largeurTerrain},
    d_hauteur{hauteurTerrain},
    d_murs{},
    d_briques{},
    d_raquette{}
    {
      initializer_Murs(hauteurmur);
      initializer_Raquette(hauteurRaquette,largeurRaquette,hauteurmur);
      initializer_Briques(nombreColone,nombreLigne,hauteurmur);
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
  int randNum =0;//= rand()%(2+ 1) ;

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
    point sa{hauteur,hauteur};
    point sb{d_largeur-hauteur,hauteur};
    unique_ptr<surface> t=make_unique<surface>(sa,sb);
    d_murs.push_back(make_unique<cassebrique::mur>(a,b,t));
    a=point(0.0,d_hauteur-hauteur);
    b=point(hauteur,hauteur);
    sa=point(hauteur,d_hauteur-hauteur);
    t=make_unique<surface>(sa,b);
    d_murs.push_back(make_unique<cassebrique::mur>(a,b,t));
    a=point(d_largeur-hauteur,d_hauteur-hauteur);
    b=point(d_largeur,hauteur);
    sb=point(d_largeur-hauteur,hauteur);
     t=make_unique<surface>(a,sb);
    d_murs.push_back(make_unique<cassebrique::mur>(a,b,t));
    a=point(0.0,d_hauteur);
    b=point(d_largeur,d_hauteur-hauteur );
    sa=point(0.0,d_hauteur-hauteur );
     t=make_unique<surfaceTueuse>(sa,b);
    d_murs.push_back(make_unique<cassebrique::mur>(a,b,t));
}
void Terrain::initializer_Briques(int nombreColone,int nombreLigne,double hauteurmur)
{
    double largeurBrique=(d_largeur-(2*hauteurmur))/nombreColone ;
    largeurBrique-=1.1;
    double hauteurBrique=(d_hauteur-2*hauteurmur)/(2*nombreLigne) ;

    //cout<<"largeurbrique= "<<largeurBrique<<"  hauteurBrique  ="<<hauteurBrique;
    point position{hauteurmur+1,hauteurmur+1};
    double x{hauteurmur+1},y{hauteurmur+1};
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
        x=hauteurmur+1;
        y+=hauteurBrique+1;
      position.moveTo(x,y);
      //cout<<"2 position= "<<position<<endl;
    }
}
void Terrain::initializer_Raquette(double hauteurRaquette,double largeurRaquette,double hauteurmur)
{
  double positionRaquetteX=d_largeur/2;
  double positionRaquetteY=d_hauteur-hauteurRaquette-hauteurmur;
  point positionRaquette{positionRaquetteX,positionRaquetteY};
  d_raquette=make_unique<cassebrique::Raquette>(positionRaquette,hauteurRaquette,largeurRaquette);
}
void Terrain::initializer_Balle(double vitesse)
{
 double positionBalleY=d_hauteur/2+20;
 double positionBalleX=d_largeur/2;
 point positionBalle{positionBalleX,positionBalleY};
 double rayonBalle=9;
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
vector<cassebrique::mur*> Terrain::murs() const
{
  vector<cassebrique::mur*> tmpmurs;
  for(auto& i : d_murs)
    {
      cassebrique::mur* tmpmur = dynamic_cast<cassebrique::mur*>(i.get());
      if(tmpmur!=nullptr)
        {
          tmpmurs.push_back(tmpmur);
        }
    }

  return tmpmurs;
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
 /* for(auto& i : d_murs)
   {
    tmpRectangles.push_back(i.get());
   }*/
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
    double debutTerain=d_raquette->BasGauche().x();
    debutTerain-=20;
    if(debutTerain>=d_murs[0]->Hauteur())
  {d_raquette->move_Gauche();}
}
void Terrain::RaquetteMoveDroit()
{
    double finTerain=d_raquette->BasGauche().x();
    finTerain+=d_raquette->Largeur()+10;
    if(finTerain<=d_largeur)
  {d_raquette->move_Droit();}
}
void Terrain::affichemurs(afficheur* affiche)
{
    vector<mur*> tmpmurs=murs();
    for(auto& e:tmpmurs)
    {
        affiche->afficherRectangle(e);
    }
}
void Terrain::run(double dt,afficheur* affiche)
{
   affiche->afficherTerrain(d_largeur,d_hauteur);
  double temp=dt;
  afficheRectangle(affiche);
  afficheRaquette(affiche);
  while(1)
    {
      d_balle->position(temp);
      affiche->effacerContenu();
      afficheBalle(affiche);
      afficheRectangle(affiche);
      int t=existColusion(d_balle.get());
     if(t==2)
     {
         affiche->fermerFenetre();
         cout<<"vous avez ratez la partie"<<endl;
         break;
     }
      affichemurs(affiche);
      afficheRaquette(affiche);
      char i='g';
      //afficheBalle(affiche);
      i=affiche->caractereEntree();
      if(i=='d' )
        {
          affiche->effacerContenu();
          RaquetteMoveDroit();
          afficheRectangle(affiche);
                affichemurs(affiche);
          afficheRaquette(affiche);
        }
      if(i=='a' )
        {
          affiche->effacerContenu();
          RaquetteMoveGauche();
          afficheRectangle(affiche);
          affichemurs(affiche);
          afficheRaquette(affiche);
        }
      temp+=dt;
     }
}
int Terrain::existColusion(cassebrique::balle* b)
{
  int k=0;
  if(d_raquette->OnCollision(b))
  {k = 1;}
  for(int i=0,taillTab=d_murs.size() ;i<taillTab;i++)
    {bool t=d_murs[i]->OnCollision(b);

          if(t)
         {k=1;
             surfaceTueuse * tmptest=dynamic_cast<surfaceTueuse*>(d_murs[i]->surfaceType());
             if(tmptest!=nullptr)
             {
                 k=2;
             }
         }
    }
  vector<cassebrique::rectangle*> f= d_briques.tovector();
    for(int i=0,len=f.size();i<i;i++)
      {
        cassebrique::brique* p= dynamic_cast<cassebrique::brique*>(f[i]);
        if(p!=nullptr)
        {
            if( p->OnCollision(b))
          {k=1;}
        }
        cassebrique::briqueCassable* tmp2= dynamic_cast<cassebrique::briqueCassable*>(f[i]);
        if(tmp2!=nullptr)
          {
            d_briques.erase(i);
          }
      }

  return k;
}
}
