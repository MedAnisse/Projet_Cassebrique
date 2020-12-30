#include "list.h"
#include"rectangle.h"
list::list()
{

}
list::~list()
{

}
void list::push_back(cassebrique::rectangle* brique)
{
if (tete!=nullptr)
{
    element* tmp=tete;
    while(tmp->next!=nullptr)
        {tmp=tmp->next;}
    tmp->next=new element(brique);
}
else
{
    tete=new element(brique);
}
}
void list::erase(int index)
{
     if(index=0)
     {
         element* tmp=tete;
         tete=tete->next;
         delete tmp;
     }
     else
{
    element* tmp=tete;
    element* tmp2=tete->next;
    int i=0;
    while(tmp2!=nullptr && i<index){tmp=tmp->next;++i;tmp2=tmp->next;}
    if(tmp2!=nullptr)
    {
        tmp=tmp2->next;
        delete tmp2;
    }
}
}
void list::clear()
{
while(tete!=nullptr)
{
    element* tmp=tete;
    tete=tete->next;
    delete tmp;
}
}
std::vector<cassebrique::rectangle*> list::tovector()
{
    std::vector<cassebrique::rectangle*>vecteurTmp{};
    element* tmp =tete;
    while(tmp!=nullptr)
    {

        vecteurTmp.push_back(new cassebrique::rectangle( tmp->info->BasGauche(),tmp->info->HautDroit()));
        tmp=tmp->next;
    }
}
