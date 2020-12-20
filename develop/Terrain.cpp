#include "Terrain.h"
#include<vector>
#include<iostream>
#include<memory>

using std::vector;
namespace cassebrique
{
unique_ptr<surface> Terrain::randomSurface()
{
int randNum = rand()%(3+ 1) ;
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
void Terrain::initializer_Murs(double hauteur)
{
    d_mure.push_back(make_unique<mure>(0.0,-hauteur,d_largeur,0.0,make_unique<surfaceNormal>()));
    d_mure.push_back(make_unique<mure>(0.0,-d_hauteur+hauteur,hauteur,-hauteur,make_unique<surfaceNormal>()));
    d_mure.push_back(make_unique<mure>(d_largeur-hauteur,-d_hauteur+hauteur,d_largeur,-hauteur,make_unique<surfaceNormal>()));
    d_mure.push_back(make_unique<mure>(0.0,-d_hauteur,d_largeur,-d_hauteur,make_unique<surfaceTueuse>()));
}
void Terrain::initializer_Briques(int nbColone,int nbLigne,double hauteur)
{
    //au permier lieu on fait une matrice de n*m brique n=10 , m=5
    //le remier mure est le mure de haut , la hauteur de chaque mure est 10
    //hauteur de mure

    double largeur=(d_largeur-2*hauteur)/n ;
    double hauteur1=(d_hauteur-2*hauteur)/2/m ;
    //hauteur1 c'est la hauteur de chaque brique
    point position{hauteur+1,-hauteur-1};
    for(int i=0,i<10,i++)
    {
            for(int j=0,j<5,j++)
            {
                surface surfaceRandom=move(randomSurface());
                d_brique.push_back(make_unique<brique>(position,hauteur1,largeur,surfaceRandom));

                position.moveTo(position.x()+largeur+1,hauteur1);
            }
            position.moveTo(hauteur+1,position.y()-1);
    }
}
void Terrain::initializer_Raquette(point &position,double hauteur,double largeur)
{
//raquette(point , hauteur,largeur,surface)
    d_raquette=make_unique<Raquette>(point(d_largeur/2,-d_hauteur),10,50,make_unique<surfaceNormal>());
}
void Terrain::initializer_Balle()
{
d_balle{};
}
void Terrain::initializer_Balle(vectorposition & vect,double vitesse)
{
 //balle(point(x,y),vecteurposition(dx,dy),vitesse)
    d_balle{point(d_hauteur/2,d_largeur/2),vect,vitesse}
    //point(d_hauteur/2,d_largeur/2) = centre de terain
}
Terrain::Terrain( double hauteur, double largeur)
d_largeur{largeur},d_hauteur{hauteur},d_mure{} ,d_brique{} ,d_raquette{}, d_balle{}
{}

~Terrain::Terrain()
{}
vector<mure*> Terrain::Tmure() const
{
    return d_mure[0].get();
}
vector<brique*> Terrain::Tbrique() const
{
    return d_brique[0].get();
}
Raquette* Terrain::TRaquette() const
{
    return d_raquette.get();
}
balle* Terrain::Tballe() const
{
    return d_balle.getI();
}
void Terrain::run(double dt)
{

}
}
