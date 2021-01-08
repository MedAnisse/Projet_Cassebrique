#include "balle.h"
#include"cmath"
#include "vector.h"

namespace cassebrique
{
    balle::balle()
    {
    }
    balle::balle(point &position,double ongle,double vitesse,double rayon):
    d_position{position},
    d_vitesse{vitesse},
    d_ongle{std::fmod((ongle * M_PI),(2*M_PI))},
    d_rayon{rayon}
    {
    }
    balle::~balle(){}
    balle*  balle::position(double Dt)
    {
    	double vitesseX{d_vitesse*cos(d_ongle)};
    	double vitesseY{d_vitesse*sin(d_ongle)};
    	double nouvellePositionX{vitesseX*Dt};
    	double nouvellePositionY{vitesseY*Dt};
    	d_position.move(nouvellePositionX,nouvellePositionY);
    	return this;
    }
    point balle::position()const
    {
        return d_position;
    }
    double balle::rayon()const
    {
        return d_rayon;
    }
    void balle::rebond()
    {
        if(d_ongle > M_PI && d_ongle < 3*M_PI*0.5)
       		{d_ongle+=M_PI*0.5;}
       else
       	{
       		if(d_ongle > M_PI)
       			{d_ongle-=M_PI*0.5;}
       		else
       		{
       			if(d_ongle > M_PI*0.5)
       				{d_ongle+=M_PI*0.5;}
       			else
       				{d_ongle-=M_PI*0.5;}
       		}
       	}
        if(	d_ongle>2*M_PI){d_ongle-=2*M_PI;}

    }
    void balle::rebond(double nouvelleVitesseAjouter)
    {
       d_vitesse+=nouvelleVitesseAjouter;
       rebond();
    }
    double balle::ongle()const
    {
        return d_ongle;
    }
}
