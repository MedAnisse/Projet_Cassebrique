#ifndef MUR_H
#define MUR_H
#include<memory>
#include<istream>
#include<ostream>
#include"point.h"
#include"surface.h"
#include"surface.h"
#include "rectangle.h"
using std::unique_ptr;
using std::make_unique;
using geom::point;
class balle;
namespace cassebrique
{
class mur : public rectangle
{
public:
     mur();
    mur (point& BasGauche,point& HautDroit,unique_ptr<surface>&  surfaceK);
    mur(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>& surfaceK);
    virtual ~mur();
    surface* surfaceType()const;
    bool OnCollision(balle& balle)const ;
private:
    unique_ptr<surface> d_surface;
protected:

};

}
#endif
