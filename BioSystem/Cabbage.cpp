#include "Cabbage.h"


Cabbage::Cabbage(int _pos_x, int _pos_y, int _age) : Object(_pos_x, _pos_y, _age) {};

void Cabbage::live(std::vector<Object*> *obj_ptr)
{
    if(age==cabrep_age)
    {
        reproduct(obj_ptr);
    }
}

void Cabbage::reproduct(std::vector<Object*> *obj_ptr)
{
    srand ( time(NULL) );
    numb_of_seed=1;
    for(int i=0;i<numb_of_seed;i++)
    {
        int x=rand()%XMAX;
        int y=rand()%YMAX;
        while( ((pos_x-x)*(pos_x-x)+(pos_y-y)*(pos_y-y))>(R*R) )
        {
            x=rand()%XMAX;
            y=rand()%YMAX;
        }
        Cabbage* new_cab = new Cabbage(x,y,0);
        obj_ptr->push_back(new_cab);
    }
}
char Cabbage::retclass()
{
    return 'c';
};
int Cabbage::retX()
{
    return pos_x;
}
int Cabbage::retY()
{
    return pos_y;
}
