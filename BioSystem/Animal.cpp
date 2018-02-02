#include "Animal.h"
#include <map>
int Animal::grid[50][50] = { 0 };
Animal::Animal(const int& _pos_x, const int& _pos_y, const int& _age, const int& _satiety, const int& _gender) : Object(_pos_x, _pos_y, _age), satiety(_satiety), gender(_gender) {};

void Animal::fill_grid(std::vector<Object*> obj_ptr)
{
	for (int i = 0; i < XMAX; i++)
	{
		for (int j = 0; j < YMAX; j++)
		{
			grid[i][j] = -2;
		}
	}
	for (int i = 0; i < obj_ptr.size(); i++)
	{
		if (obj_ptr[i])
		grid[obj_ptr[i]->retX()][obj_ptr[i]->retY()] = -1;
	}
};

std::pair<int,std::pair<int,int>> Animal::lee(int ax, int ay, int bx, int by)   // ����� ���� �� ������ (ax, ay) � ������ (bx, by)
{

	const int W = XMAX;         // ������ �������� ����
	const int H = YMAX;         // ������ �������� ����
	const int WALL = -1;         // ������������ ������
	const int BLANK = -2;         // ��������� ������������ ������
	int px[W], py[W];      // ���������� �����, �������� � ����
	int len;                       // ����� ����
	int dx[4] = { 1, 0, -1, 0 };   // ��������, ��������������� ������� ������
	int dy[4] = { 0, 1, 0, -1 };   // ������, �����, ����� � ������
	int d, x, y, k;
	bool stop;
	std::pair<int, std::pair<int,int>> step;
	grid[bx][by] = -2;
	d = 0;
	grid[ay][ax] = 0;
	if (grid[ay][ax] == WALL || grid[by][bx] == WALL)
	{
		step.first = -1;
		return step;
	}

	do {
		stop = true;
		for (y = 0; y < H; ++y)
			for (x = 0; x < W; ++x)
				if (grid[y][x] == d)
				{
					for (k = 0; k < 4; ++k)
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
							grid[iy][ix] == BLANK)
						{
							stop = false;
							grid[iy][ix] = d + 1;
						}
					}
				}
		++d;
	} while (!stop && grid[by][bx] == BLANK);

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL) //���� �� ������
	{
		step.first = -1;
		return step;
	}

	//�������������� ����
	len = grid[by][bx];
	x = bx;
	y = by;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y;
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
				grid[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k];
				break;
			}
		}
	}
	px[0] = ax;
	py[0] = ay;

	step.first = len-1;
	step.second.first = px[1];
	step.second.second = py[1];
	return step;
}

void Animal::move(int p_x, int p_y, std::vector<Object*> obj_ptr)
{
	fill_grid(obj_ptr);
	std::pair<int, std::pair<int, int>> step = lee(pos_x, pos_y, p_x, p_y);
	pos_x = step.second.first;
	pos_y = step.second.second;
};

void Animal::eat(std::pair<int, int>food_coords, std::vector<Object*>& obj_ptr)
{
	for (auto& obj : obj_ptr)
	{
		if (obj && obj->retX() == food_coords.first && obj->retY() == food_coords.second)
		{
			if (retclass() == 'w' && obj->retclass() == 'g')
			{
				satiety += 50;
				delete obj;
				obj = nullptr;
			}
			if (retclass() == 'g' && obj->retclass() == 'c')
			{
				satiety += 20;
				delete obj;
				obj = nullptr;
			}
		}
	}
}

bool Animal::live(std::vector<Object *> *obj_ptr)
{
	satiety -= get_hunger();
	age++;
	fill_grid(*obj_ptr);
	if (satiety <= 0 || age==get_age_death())
	{
		return false;
	}
	else if (satiety <= 50)
	{
		std::pair<int, int> food_coords = find_food(*obj_ptr);
		if (food_coords.first == 0 && food_coords.second == 0) { return true; }
		move(food_coords.first, food_coords.second, *obj_ptr);
		if (pos_x == food_coords.first && pos_y == food_coords.second)
			eat(food_coords, *obj_ptr);
		return true;
	}
	else if (retAge() == get_rep_age())
	{
		reproduct(obj_ptr);
		return true;
	}
}

std::pair<int, int> Animal::find_food(std::vector<Object *> obj_ptr)
{
	std::vector <std::pair<int, int>> targets; //���������� �����
	std::vector <std::pair< int, std::pair< int, int >>> targ_coords; // ������ ���� �� �����, ���������� ���������� ���� � ����
	for (int i = 0; i < obj_ptr.size(); i++)
	{
		if ( obj_ptr[i] && ( (retclass()=='w' && obj_ptr[i]->retclass() == 'g') || (retclass()=='g' && obj_ptr[i]->retclass()=='c') ) )
		{
			std::pair<int, int> buf;
			buf.first = obj_ptr[i]->retX();
			buf.second = obj_ptr[i]->retY();
			targets.push_back(buf);
		}
	}
	for (int i = 0; i < targets.size(); i++)
	{
		fill_grid(obj_ptr);
		targ_coords.push_back(lee(pos_x, pos_y, targets[i].first, targets[i].second));
	}
	std::pair<int, int> food_coords;
	int min_length = 1000;
	for (int i = 0; i < targ_coords.size(); i++)
	{
		if (targ_coords[i].first >= 0 && targ_coords[i].first <= get_R() && targ_coords[i].first< min_length)
		{
			min_length = targ_coords[i].first;
			food_coords.first = targets[i].first;
			food_coords.second = targets[i].second;
		}
	}
	return(food_coords);
};