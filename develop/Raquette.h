#ifndef RAQUETTE_H
#define RAQUETTE_H
#include "rectangle.h"
#include "surface.h"
#include"surfaceNormal.h"
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
    Raquette(const point& BasGauche,const point& HautDroit,unique_ptr<surface>  surfaceK=make_unique<surfaceNormal>());
    Raquette(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK=make_unique<surfaceNormal>());
    virtual ~Raquette();
    surface* surfaceType()const;
    void move_Gauche();
    void move_Droit();
    void move_Gauche(int n);
    void move_Droit(int n);
private:
    unique_ptr<surface> d_surface;
};
}
#endif // RAQUETTE_H
