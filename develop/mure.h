#ifndef MURE_H
#define MURE_H
namespace cassebrique
{
class mure
{
public:
    mure(point& BasGauche,point& HautDroit);
    mure(point& BasGauche,double hauteur,double largeur);
    mure(double BasGauche_x,double BasGauche_y,double HautDroit_x,double HautDroit_y);
    mure(double BasGauche_x,double BasGauche_y,double BasGauche_x,double BasGauche_y);

private:
    unique_ptr<surface> d_surface;
    point d_BasGauche;
    point d_HautDroit;
protected:

};
}
#endif
