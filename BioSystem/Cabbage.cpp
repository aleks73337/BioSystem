#include "Cabbage.h"
const int Cabbage::R = 5;
const int Cabbage::age_death = 10;
const int Cabbage::rep_age = 8;

Cabbage::Cabbage(int _pos_x, int _pos_y, int _age) : Object(_pos_x, _pos_y, _age) {};
int Cabbage::retAge() { return(age); };

bool Cabbage::live(std::vector<Object*> *obj_ptr)
{
	if (age == age_death)
	{
		age = -1;
		return false;
	}
    if(age==rep_age)
    {
        reproduct(obj_ptr);
		return true;
    }
	age++;
	return true;
}

void Cabbage::reproduct(std::vector<Object*> *obj_ptr)
{
    srand ( time(NULL) );
    numb_of_seed=rand()%5;
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
