#include "Field.h"

void Field::print_field()
{
    char fld[XMAX+1][YMAX+1];
    for(int i=0;i<=XMAX;i++)
    {
        for(int j=0;j<=YMAX;j++)
            fld[i][j]='_';
    }
    for(int i=0;i<objects.size();i++)
    {
       int X,Y;
       X=objects[i]->retX();
       Y=objects[i]->retY();
       fld[X][Y]=objects[i]->retclass();
    }
    for(int i=0;i<=XMAX;i++)
    {
        for(int j=0;j<=YMAX;j++)
            std::cout<<fld[i][j];
        std::cout<<std::endl;
    }
};
void Field::add_object(Object* obj_p) 
{
	objects.push_back(obj_p);
};
void Field::live_()
{
    for(int i=0;i<objects.size();i++)
    {
    objects[i]->live(&objects);
    }
}