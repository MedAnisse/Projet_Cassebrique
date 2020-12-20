#ifndef BRIQUEINCASSABLE_H
#define BRIQUEINCASSABLE_H
namespace cassebrique
{
class briqueIncassable : public balle
{
public:
    briqueIncassable();
    virtual ~briqueIncassable();
    virtual bool existe_collusion(balle& balle)  override;


};
}
#endif
