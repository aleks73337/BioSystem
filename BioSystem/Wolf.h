#pragma once
#include "Animal.h"

class Wolf : public Animal
{
	const static int age_death;
	const static int rep_age;
	const static int R;
public:
	char retclass() override { return ('w'); };
	void eat(std::pair<int, int> food_coords, std::vector<Object*>& obj_ptr) override;
    void reproduct(std::vector<Object *> *obj_ptr) override;
    bool live(std::vector<Object *> *obj_ptr) override;
	Wolf(int _pos_x, int _pos_y, int _age, int satiety, int _gender);
	void move(int p_x, int p_y, std::vector<Object*> obj_ptr) override;
	std::pair<int, int> find_food(std::vector<Object*> obj_ptr) override;
};
