#ifndef RAQUETTE_H
#define RAQUETTE_H
#include "rectangle.h"
#include "surface.h"
#include<memory>
using geom::point;
using std::unique_ptr;
using std::make_unique;
namespace cassebrique
{
class Raquette: public rectangle
{
public:
    Raquette();
    Raquette(const point& BasGauche,const point& HautDroit);
    Raquette(point& BasGauche,double hauteur,double largeur);
    virtual ~Raquette();
    surface* surfaceType()const;
    void move_Gauche();
    void move_Droit();
    void move_Gauche(int n);
    void move_Droit(int n);
    bool OnCollusion(balle* balle)const ;
    point debut()const;
    point fin()const;
    double distance(balle* balle);
private:
    unique_ptr<surface> d_surface;
};
}
#endif // RAQUETTE_H
