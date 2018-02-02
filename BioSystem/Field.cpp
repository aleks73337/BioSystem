#include "Field.h"
#include <algorithm> 

void Field::print_field()
{
	for (int i = 0; i < XMAX; i++)
	{
		for (int j = 0; j < YMAX; j++)
		{
			field[i][j] = '_';
		}
	}

	for ( int i = 0; i < objects.size() ; ++i )
	{
		if (objects[i])
		{
			field[objects[i]->retX()][objects[i]->retY()] = objects[i]->retclass();
		}
	}

	for (int i = 0; i < XMAX; i++)
	{
		for (int j = 0; j < YMAX; j++)
		{
			std::cout<<field[i][j];
		}
		std::cout << std::endl;
	}

};

void Field::add_object(Object* obj_p) 
{
	objects.push_back(obj_p);
};
void Field::live_()
{
	size_t len = objects.size();
    for(int i=0;i<len;i++)
    {
		if (objects[i] && objects[i]->live(&objects) == false)
		{
			delete objects[i];
			objects[i] = nullptr;
		}
		len = objects.size();
    }

	bool flag;
	do
	{
		flag = false;
		for (std::vector<Object*>::const_iterator it = objects.begin() + 1;
			it != objects.end();++it)
		{
			if (!(*it))
			{
				objects.erase(it);
				flag = true;
				break;
			}
		}
		
	} while (flag);
}