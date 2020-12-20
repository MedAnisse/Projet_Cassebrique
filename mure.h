#ifndef MURE_H
#define MURE_H
class mure
{
public:
    mure(point& BasGauche,point& HautDroit);
    mure(point& BasGauche,double hauteur,double largeur);
    mure(double BasGauche_x,double BasGauche_y,double HautDroit_x,double HautDroit_y);
    mure(double BasGauche_x,double BasGauche_y,double BasGauche_x,double BasGauche_y);

private:
    surface d_mure_surface;
    point d_BasGauche;
    point d_HautDroit;
protected:

};
#endif
