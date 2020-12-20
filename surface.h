#ifndef SURFACE_H
#define SURFACE_H


class surface
{
    public:

        virtual ~surface();
        virtual bool collusion(balle& balle) = 0;
};

#endif // SURFACE_H
