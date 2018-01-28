#include "Animal.h"
#include <map>
int Animal::grid[50][50] = { 0 };
Animal::Animal(int _pos_x, int _pos_y, int _age, int _satiety, int _gender) : Object(_pos_x, _pos_y, _age), satiety(_satiety), gender(_gender) {};

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
		grid[obj_ptr[i]->retX()][obj_ptr[i]->retY()] = -1;
	}
};

std::pair<int,std::pair<int,int>> Animal::lee(int ax, int ay, int bx, int by)   // поиск пути из €чейки (ax, ay) в €чейку (bx, by)
{

	const int W = XMAX;         // ширина рабочего пол€
	const int H = YMAX;         // высота рабочего пол€
	const int WALL = -1;         // непроходима€ €чейка
	const int BLANK = -2;         // свободна€ непомеченна€ €чейка
	int px[W], py[W];      // координаты €чеек, вход€щих в путь
	int len;                       // длина пути
	int dx[4] = { 1, 0, -1, 0 };   // смещени€, соответствующие сосед€м €чейки
	int dy[4] = { 0, 1, 0, -1 };   // справа, снизу, слева и сверху
	int d, x, y, k;
	bool stop;
	std::pair<int, std::pair<int,int>> step;

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL)
	{
		step.first = -1;
		return step;
	}
	grid[bx][by] = -2;
	// распространение волны
	d = 0;
	grid[ay][ax] = 0;

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

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL) //путь не найден
	{
		step.first = -1;
		return step;
	}

	//восстановление пути
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