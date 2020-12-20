#ifndef BRIQUECASSABLEAPRESPLUSIEURFOIS_H
#define BRIQUECASSABLEAPRESPLUSIEURFOIS_H
class briqueCassableApresPlusieurFois : public balle
{
public:
    briqueCassableApresPlusieurFois();
    virtual ~briqueCassableApresPlusieurFois();
    virtual bool existe_collusion(balle& balle)  override;
private:
    int d_nb_fois;
protected:

};

#endif
