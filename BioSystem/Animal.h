#pragma once
#include "Object.h"

class Animal : public Object {

  protected:
	int satiety; // сытость
	const int gender;
	std::pair<int, std::pair<int, int>> lee(int &ax, int &ay, int &bx, int &by);
	virtual const int get_age_death() = 0;
	virtual const int get_rep_age() = 0;
	virtual const int get_R() = 0;
	virtual const int get_hunger() = 0;

  public:
	virtual void move(int &p_x, int &p_y, std::vector<Object *> &obj_ptr);
	virtual std::pair<int, int> find_food(std::vector<Object *> &obj_ptr);
	virtual void eat(std::pair<int, int> &food_coords,
					 std::vector<Object *> &obj_ptr);
	virtual void reproduct(std::vector<Object *> *obj_ptr) = 0;
	virtual bool live(std::vector<Object *> *obj_ptr);
	virtual ~Animal(){};
	Animal(const int &_pos_x, const int &_pos_y, const int &_age,
		   const int &_satiety, const int &_gender);
};
