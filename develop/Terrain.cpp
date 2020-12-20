#include "Terrain.h"
#include<vector>
#include<iostream>
#include<memory>
using std::vector;
Terrain::Terrain( double hauteur, double largeur)
d_largeur{largeur},d_hauteur{hauteur}
{
    //au permier lieu on fait une matrice de n*m brique n=10 , m=5
    //le remier mure est le mure de haut , la hauteur de chaque mure est 10
    d_mure.push_back(make_unique<mure>(0.0,-10.0,d_largeur,0.0,make_unique<surfaceNormal>()));
    d_mure.push_back(make_unique<mure>(0.0,-d_hauteur+10.0,10.0,-10.0,make_unique<surfaceNormal>()));
    d_mure.push_back(make_unique<mure>(d_largeur-10,-d_hauteur+10.0,d_largeur,-10.0,make_unique<surfaceNormal>()));
    d_mure.push_back(make_unique<mure>(0.0,-d_hauteur,d_largeur,-d_hauteur,make_unique<surfaceTueuse>()));
    double largeur=(d_largeur-20)/10 ;
    double hauteur=(d_hauteur-20)/10 ;
    point position{11.0,-11.0};
    for(int i=0,i<10,i++)
    {
            for(int j=0,j<5,j++)
            {
                d_brique.push_back(make_unique<brique>(position,hauteur,largeur));

                position.moveTo(position.x()+largeur+1,hauteur);
            }
            position.moveTo(11.0,position.y()-1);
    }
    //raquette(point , hauteur,largeur,surface)
    d_raquette=make_unique<Raquette>(point(d_largeur/2,-d_hauteur),10,50,make_unique<surfaceNormal>());
    //balle(point(x,y),vecteurposition(dx,dy),vitesse)
    d_balle{point(d_hauteur/2,d_largeur/2),vectorposition(0,-1),1.5}
}

~Terrain::Terrain()
{}
vector<mure*> Terrain::Tmure() const
{
    return nullptr;
}
vector<brique*> Terrain::Tbrique() const
{
    return nullptr;
}
Raquette* Terrain::TRaquette() const
{
    return nullptr;
}
balle* Terrain::Tballe() const
{
    return nullptr;
}
void Terrain::run(double dt)
{
    return nullptr;
}
