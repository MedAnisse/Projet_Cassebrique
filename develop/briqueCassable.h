#ifndef BRIQUECASSABLE_H
#define BRIQUECASSABLE_H
class briqueCassable :public balle
{
public:
    briqueCassable();
    virtual ~briqueCassable();
    virtual bool existe_collusion(balle& balle)  override;
};

#endif
