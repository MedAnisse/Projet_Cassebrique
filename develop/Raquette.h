#ifndef RAQUETTE_H
#define RAQUETTE_H
namespace cassebrique
{
class Raquette
{
public:
    Raquette(point& position,double hauteur,double largeur,unique_ptr<surface> surface);
    virtual ~Raquette();
private:
    unique_ptr<surface> d_surface;
    point position
protected:

};
}
#endif // RAQUETTE_H
