#ifndef RAQUETTE_H
#define RAQUETTE_H
namespace cassebrique
{
class Raquette
{
public:
    Raquette(point& position,double hauteur,double largeur,unique_ptr<surface> surfaceK);
    virtual ~Raquette();
    surface* surfaceType()const;
    double Hauteur()const;
    double Largeur()const;
    void bougerGauche(int n);
    void bougerDroit(int n);
private:
    unique_ptr<surface> d_surface;
    point position;
    double d_hauteur,d_largeur;
protected:

};
}
#endif // RAQUETTE_H
