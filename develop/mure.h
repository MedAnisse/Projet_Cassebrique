#ifndef MURE_H
#define MURE_H
namespace cassebrique
{
class mure
{
public:
    mure(point& BasGauche,point& HautDroit,unique_ptr<surface>surfaceK);
    mure(point& BasGauche,double hauteur,double largeur,unique_ptr<surface>surfaceK);
    mure(double BasGauche_x,double BasGauche_y,double HautDroit_x,double HautDroit_y,unique_ptr<surface>surfaceK);
    virtual ~mure();
    mure();
    surface* surfaceType()const;
    double Hauteur()const;
    double Largeur()const;

private:
    unique_ptr<surface> d_surface;
    point d_BasGauche;
    point d_HautDroit;
protected:

};
}
#endif
