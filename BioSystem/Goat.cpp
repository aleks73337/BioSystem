#include "Goat.h"

int Goat::R = 10;
int Goat::age_death = 5;
int Goat::rep_age = 2;

Goat::Goat(int _pos_x, int _pos_y, int _age, int _satiety, int _gender) : Animal(_pos_x, _pos_y, _age, _satiety, _gender) {};

char Goat::retclass() { return('g'); }

void Goat::field_matrix(std::vector<Object*> obj_ptr)
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			grid[i][j] = -2;
		}
	}
	for (int i = 0; i < obj_ptr.size(); i++)
	{
		grid[obj_ptr[i]->retX()][obj_ptr[i]->retY()] = -1;
	}
};

bool Goat::lee(int ax, int ay, int bx, int by)   // ����� ���� �� ������ (ax, ay) � ������ (bx, by)
{
	const int W = 50;         // ������ �������� ����
	const int H = 50;         // ������ �������� ����
	const int WALL = -1;         // ������������ ������
	const int BLANK = -2;		 //��������� ������
	int dx[4] = { 1, 0, -1, 0 };   // ��������, ��������������� ������� ������
	int dy[4] = { 0, 1, 0, -1 };   // ������, �����, ����� � ������
	int d, x, y, k;
	bool stop;

	if (grid[ay][ax] == WALL || grid[by][bx] == WALL) return false;  // ������ (ax, ay) ��� (bx, by) - �����

																	 // ��������������� �����
	d = 0;
	grid[ay][ax] = 0;            // ��������� ������ �������� 0
	do {
		stop = true;               // ������������, ��� ��� ��������� ������ ��� ��������
		for (y = 0; y < H; ++y)
			for (x = 0; x < W; ++x)
				if (grid[y][x] == d)                         // ������ (x, y) �������� ������ d
				{
					for (k = 0; k < 4; ++k)                    // �������� �� ���� ������������ �������
					{
						int iy = y + dy[k], ix = x + dx[k];
						if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
							grid[iy][ix] == BLANK)
						{
							stop = false;              // ������� ������������ ������
							grid[iy][ix] = d + 1;      // �������������� �����
						}
					}
				}
		d++;
	} while (!stop && grid[by][bx] == BLANK);

	if (grid[by][bx] == BLANK) return false;  // ���� �� ������

											  // �������������� ����
	int len = grid[by][bx];            // ����� ����������� ���� �� (ax, ay) � (bx, by)
	x = bx;
	y = by;
	d = len;
	while (d > 0)
	{
		px[d] = x;
		py[d] = y;                   // ���������� ������ (x, y) � ����
		d--;
		for (k = 0; k < 4; ++k)
		{
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < H && ix >= 0 && ix < W &&
				grid[iy][ix] == d)
			{
				x = x + dx[k];
				y = y + dy[k];           // ��������� � ������, ������� �� 1 ����� � ������
				break;
			}
		}
	}
	px[0] = ax;
	py[0] = ay;                    // ������ px[0..len] � py[0..len] - ���������� ����� ����
	return true;
}

void Goat::move(int p_x, int p_y, std::vector<Object*> obj_ptr)
{
	field_matrix(obj_ptr);
	bool flag = lee(pos_x, pos_y, p_x, p_y); // ����� ������� lee() ������ grid �������� ���������� WALL � BLAN
	pos_x = px[1];
	pos_y = py[1];
}

std::pair<int,int> Goat::find_food()
{
	std::pair<int, int> food_coords;
	return(food_coords);
}

void Goat::eat(std::pair<int,int>food_coords)
{}

void Goat::reproduct(std::vector<Object *> *obj_ptr) 
{
	int x = rand() % XMAX;
	int y = rand() % YMAX;
	while (((pos_x - x)*(pos_x - x) + (pos_y - y)*(pos_y - y))>(R*R))
	{
		x = rand() % XMAX;
		y = rand() % YMAX;
	}
	Goat* new_goat = new Goat(x, y, 0, 100, rand()%2);
	obj_ptr->push_back(new_goat);
};

void Goat::live(std::vector<Object *> *obj_ptr)
{
	if (satiety == 0) {} //death
	else if  (satiety <= 50)
	{
		//std::pair<int,int> food_coords=find_food();
		int tg_x=49, tg_y=49;
		move(tg_x, tg_y, *obj_ptr);

		//eat(food_coords);
	}
	else
	{
		if (retAge() > rep_age) { reproduct(obj_ptr); }
	}

}
