#pragma once
#include "Animal.h"

class Wolf : public Animal {
	const static int age_death;
	const static int rep_age;
	const static int R;
	const static int hunger;
	virtual const int get_age_death();
	virtual const int get_rep_age();
	virtual const int get_R();
	virtual const int get_hunger();

  public:
	char retclass() override { return ('w'); };
	void reproduct(std::vector<Object *> *obj_ptr) override;
	Wolf(const int &_pos_x, const int &_pos_y, const int &_age,
		 const int &satiety, const int &_gender);
};
