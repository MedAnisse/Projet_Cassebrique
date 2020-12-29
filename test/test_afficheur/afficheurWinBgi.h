#ifndef AFFICHEURWINBGI_H
#define AFFICHEURWINBGI_H
#include "afficheur.h"
#include"rectangle.h"
namespace cassebrique
{
    class afficheurWinBgi : public afficheur
{
    public:
        afficheurWinBgi();
        ~afficheurWinBgi();
       virtual void afficherRectangle(cassebrique::rectangle* terain)const  override;
       virtual void afficherRaquette(cassebrique::Raquette* raquette)const override;
        virtual void afficherBrique(cassebrique::brique* brique)const override;
        virtual void afficherBalle(cassebrique::balle* balle)const override;
        virtual void effacerContenu()const override;
        virtual char caractereEntree()const override;

};
}

#endif // AFFICHEURWINBGI_H
