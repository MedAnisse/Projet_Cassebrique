#ifndef RECTANGLE_H
#define RECTANGLE_H
#include<memory>
#include<istream>
#include<ostream>
#include"point.h"
using geom::point;
namespace cassebrique
{
class rectangle
{
public:

    rectangle();
    rectangle(const point& BasGauche,const point& HautDroit);
    rectangle(point& BasGauche,double hauteur,double largeur);
    virtual ~rectangle();
    double Hauteur()const;
    double Largeur()const;
    void print(std::ostream& ost) const;
    void read(std::istream& ist);
    point BasGauche() const;
    point HautDroit() const;

protected:
    point d_BasGauche;
    point d_HautDroit;
};
std::ostream& operator<<(std::ostream& , const rectangle& );
std::istream& operator>>(std::istream& , rectangle& );

}
#endif // RECTANGLE_H
