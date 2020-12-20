#ifndef VECTORPOSITION_H
#define VECTORPOSITION_H
class vectorposition
{
public:
    vectorposition();
    vectorposition(double x,double y);
    vectorposition(point & a,point & b);
    void change(double x, double y);
    double x()         const;
    double y()         const;
    double length()    const;
private:
    double d_x,d_y;


};

#endif
