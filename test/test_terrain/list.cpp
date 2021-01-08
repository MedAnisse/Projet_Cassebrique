#include "list.h"
#include"rectangle.h"
#include<vector>
#include"point.h"
list::list():tete{}
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
     if(index==0)
     {
         element* tmp=tete;
         tete=tete->next;
         delete tmp;
     }
     else
{
    element* tmp=tete;
    element * t;
    int i=1;
    while(!tmp){
            t=tmp;
            tmp=tmp->next;
        if(i==index)
    {
        break;
    }
            i++;
    }

         t=tmp->next;
        delete tmp;
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
std::vector<cassebrique::rectangle*> list::tovector() const
{
    std::vector<cassebrique::rectangle*>tmpRectangles{};
    element* tmp =tete;
    while(tmp!=nullptr)
    {
        point a=tmp->info->BasGauche();
         point b=tmp->info->HautDroit();
        cassebrique::rectangle* t =new cassebrique::rectangle( a,b);
        tmpRectangles.push_back(t);
        tmp=tmp->next;

    }
    return tmpRectangles;
}
