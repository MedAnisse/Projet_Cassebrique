#ifndef LIST_H
#define LIST_H
#include "rectangle.h"
#include <vector>
class element
{
public:
    element(cassebrique::rectangle* briques){ info=briques;next=nullptr;}
    cassebrique::rectangle* info;
    element* next;

};

class list
{
    public:
        list();
        virtual ~list();
        void push_back(cassebrique::rectangle* brique);
        void erase(int index);
        void clear();
        std::vector<cassebrique::rectangle*> tovector()const;
        element* tete;
};

#endif // LIST_H
