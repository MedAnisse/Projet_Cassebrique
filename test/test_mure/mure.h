#ifndef MURE_H
#define MURE_H
#include<memory>
#include<istream>
#include<ostream>
#include"point.h"
#include"surface.h"
#include"surfaceNormal.h"
using std::unique_ptr;
using std::make_unique;
using geom::point;
class balle;
namespace cassebrique
{
class mure
{
public:

    mure();
    mure(const point& BasGauche,const point& HautDroit,unique_ptr<surface>  surfaceK=make_unique<surfaceNormal>() );
    mure(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK=make_unique<surfaceNormal>());
    virtual ~mure();
    surface* surfaceType()const;
    double Hauteur()const;
    double Largeur()const;
    void print(std::ostream& ost) const;
    void read(std::istream& ist);
    point BasGauche() const;
    point HautDroit() const;
    bool OnCollusion(balle& balle)const ;
private:
    unique_ptr<surface> d_surface;
    point d_BasGauche;
    point d_HautDroit;
protected:

};
std::ostream& operator<<(std::ostream& , const mure& );
std::istream& operator>>(std::istream& , mure& );

}
#endif
