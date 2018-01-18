#pragma once

class Object
{
protected:
	int pos_x;
	int pos_y;
	int age;
public:
	virtual void reproduct();
	Object(int _pos_x, int _pos_y, int _age);
};