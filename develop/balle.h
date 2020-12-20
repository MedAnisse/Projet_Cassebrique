#ifndef BALLE_H
#define BALLE_H
class balle
{
public:
    balle(point &position,double rayon);
    balle(double x,double y,double rayon);
    virtual ~balle();
    balle&  position(double Dt);
private:
    point d_position;
    double d_rayon;
protected:

};

#endif
