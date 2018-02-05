#include "Goat.h"
#include <map>
#include <vector>
const int Goat::R = 20;
const int Goat::age_death = 60;
const int Goat::rep_age = 10;
const int Goat::hunger = 2;

Goat::Goat(const int &_pos_x, const int &_pos_y, const int &_age,
		   const int &_satiety, const int &_gender)
	: Animal(_pos_x, _pos_y, _age, _satiety, _gender){};

const int Goat::get_age_death() { return age_death; };
const int Goat::get_rep_age() { return rep_age; };
const int Goat::get_R() { return R; };
const int Goat::get_hunger() { return hunger; };
void Goat::reproduct(std::vector<Object *> *obj_ptr) {

	srand(1);
	const int dx[4] = {1, 0, -1, 0}; // смещения, соответствующие соседям ячейки
	const int dy[4] = {0, 1, 0, -1};
	for (int j = 0; j < 4; ++j) {
		for (int k = 0; k < 4; ++k) {
			int x = pos_x + dx[j];
			int y = pos_y + dy[k];
			if (x > 0 && x < XMAX && y > 0 && y < YMAX && grid[x][y] == -2) {
				obj_ptr->push_back(new Goat(x, y, 0, 50, 0));
				return;
			}
		}
	}
};
