#include "Wolf.h"

Wolf::Wolf(const int &_pos_x, const int &_pos_y, const int &_age,
		   const int &satiety, const int &_gender)
	: Animal(_pos_x, _pos_y, _age, satiety, _gender){};
const int Wolf::age_death = 60;
const int Wolf::R = 30;
const int Wolf::rep_age = 20;
const int Wolf::hunger = 3;
const int Wolf::get_age_death() { return age_death; };
const int Wolf::get_rep_age() { return rep_age; };
const int Wolf::get_R() { return R; };
const int Wolf::get_hunger() { return hunger; };

void Wolf::reproduct(std::vector<Object *> *obj_ptr) {
	srand(1);
	const int dx[4] = {1, 0, -1, 0}; // смещения, соответствующие соседям ячейки
	const int dy[4] = {0, 1, 0, -1};
	for (int j = 0; j < 4; ++j) {
		for (int k = 0; k < 4; ++k) {
			int x = pos_x + dx[j];
			int y = pos_y + dy[k];
			if (x > 0 && x < XMAX && y > 0 && y < YMAX && grid[x][y] == -2) {
				obj_ptr->push_back(new Wolf(x, y, 0, 100, 0));
				return;
			}
		}
	}
}
