#ifndef BRIQUECASSABLEAPRESPLUSIEURFOIS_H
#define BRIQUECASSABLEAPRESPLUSIEURFOIS_H
#include "brique.h"
#include <iostream>
#include "point.h"
#include<memory>
using geom::point;
using std::unique_ptr;
using std::move;
namespace cassebrique
{
class briqueCassableApresPlusieurFois : public brique
{
public:
    briqueCassableApresPlusieurFois(int a,point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK);
    briqueCassableApresPlusieurFois(int a,point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK);
    briqueCassableApresPlusieurFois(int a);
    virtual ~briqueCassableApresPlusieurFois();
    virtual bool OnCollusion(balle& balle)  override;
    private:
    int d_nombreDeFois;



};
}
#endif
