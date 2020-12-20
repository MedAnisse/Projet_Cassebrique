#ifndef BRIQUE_H
#define BRIQUE_H
class brique
{
public:
    brique(point& BasGauche,point& HautDroit);
    brique(point& BasGauche,double hauteur,double largeur);
    brique(double BasGauche_x,double BasGauche_y,double HautDroit_x,double HautDroit_y);
    brique(double BasGauche_x,double BasGauche_y,double BasGauche_x,double BasGauche_y);
    virtual ~brique();
    virtual bool existe_collusion(balle& balle) = 0;
private:
    point d_BasGauche;
    point d_HautDroit;
    vector<unique_ptr<surface>> d_vector_surface;
protected:

};

#endif
