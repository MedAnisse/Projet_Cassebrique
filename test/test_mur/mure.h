#ifndef MURE_H
#define MURE_H
#include<memory>
#include<istream>
#include<ostream>
#include"point.h"
#include"surface.h"
#include"surfaceNormal.h"
#include "rectangle.h"
using std::unique_ptr;
using std::make_unique;
using geom::point;
class balle;
namespace cassebrique
{
class mure : public rectangle
{
public:
     mure();
    mure (point& BasGauche,point& HautDroit,unique_ptr<surface>&  surfaceK);
    mure(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>& surfaceK);
    virtual ~mure();
    surface* surfaceType()const;
    bool OnCollusion(balle& balle)const ;
private:
    unique_ptr<surface> d_surface;
protected:

};

}
#endif
