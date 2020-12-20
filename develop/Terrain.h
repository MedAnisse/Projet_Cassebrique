#ifndef TERRAIN_H
#define TERRAIN_H
#include<vector>
#include<iostream>
using std::vector;
namespace cassebrique
{
class Terrain
{
    public:
        Terrain( double hauteur, double largeur);
        virtual ~Terrain();
        mure* Tmure() const ;
        brique* Tbrique() const ;
        Raquette* TRaquette() const ;
        balle Tballe() const ;
        void run(double dt);
    protected:

    private:
        vector<unique_ptr<mure>> d_mure;
        vector<unique_ptr<brique>> d_brique;
        unique_ptr<Raquette> d_raquette;
        balle d_balle;
        double d_largeur,d_hauteur;

};
}
#endif // TERRAIN_H
