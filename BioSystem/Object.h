#pragma once

class Object
{
protected:
	int pos_x;
	int pos_y;
	int age;
	virtual void reproduct();
public:
	Object(int _pos_x, int _pos_y, int _age);
};