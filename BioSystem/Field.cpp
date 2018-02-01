#include "Field.h"

void Field::print_field()
{
	char fld[XMAX + 1][YMAX + 1];
    for(int i=0;i<=XMAX;i++)
    {
		for (int j = 0; j <= YMAX; j++)
		{
			fld[i][j] = '_';
		}
    }
    for(auto obj: objects)
	{
       int X,Y;
	   if (obj == nullptr) { continue; };
       X=obj->retX();
       Y=obj->retY();
       fld[X][Y]=obj->retclass();
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
	int len = objects.size();
    for(int i=0;i<len;i++)
    {
		if (objects[i] && objects[i]->live(&objects) == false)
		{
			delete objects[i];
			objects[i] = nullptr;
		}
		len = objects.size();
    }
}