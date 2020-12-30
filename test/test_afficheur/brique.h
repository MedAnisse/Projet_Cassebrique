#ifndef BRIQUE_H
#define BRIQUE_H
#include "rectangle.h"
#include "surface.h"
#include <memory>
#include <vector>
using std::vector;
using std::unique_ptr;
namespace cassebrique
{
class brique: public rectangle
{
public:
    brique();
    brique(point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK);
    brique(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK);
    virtual ~brique();
    void  initializerLesSurfaces(unique_ptr<surface>surfacek);
    virtual bool OnCollusion(balle& balle) ;
protected:
       vector<unique_ptr<surface>> d_surface;

};
}
#endif
