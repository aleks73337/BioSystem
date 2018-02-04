#include "Field.h"
std::vector<sf::RectangleShape> Field::print_field()
{
	std::vector<sf::RectangleShape> disp_object;
	for (auto& obj : objects)
	{
		sf::RectangleShape rectangle(sf::Vector2f(10, 10));
		rectangle.setPosition(obj->retX() * 10, obj->retY() * 10);
		if (obj->retclass() == 'c')
			rectangle.setFillColor(sf::Color::Green);
		if (obj->retclass() == 'g')
			rectangle.setFillColor(sf::Color::White);
		if (obj->retclass() == 'w')
			rectangle.setFillColor(sf::Color::Red);
		disp_object.push_back(rectangle);
	}
	return(disp_object);

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
		for (std::vector<Object*>::const_iterator it = objects.begin();
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