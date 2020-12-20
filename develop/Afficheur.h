#ifndef AFFICHEUR_H
#define AFFICHEUR_H


class Afficheur
{
    public:

        virtual Affiche_Mure(mure & m) =0 ;
        virtual Affiche_Brique(brique & b) =0 ;
        virtual Affiche_Balle(balle & b) =0 ;
        virtual Affiche_Raquette(Raquette & r) =0 ;
        virtual Affiche_Terrain(Terrain & r) =0 ;

    protected:

    private:
};

#endif // AFFICHEUR_H
