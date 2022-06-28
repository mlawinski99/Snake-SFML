#include "Fruit.h"
Fruit::Fruit(vector <Fruit*> &vect, string name, string filename)
{
	unique_ptr<Object> fruit(new Object(filename, name, 0, 0));
	this->ptr = move(fruit);
	vect.push_back(this);
}
