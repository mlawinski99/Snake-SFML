#include "Snake.h"
Snake::Snake(int x, int y, int w, int h)
{
	font.loadFromFile("arial.ttf");
	this->t.setFont(font);
	this->t.setString("0");
	this->t.setCharacterSize(80);
	this->counter = 0;
	t.setStyle(sf::Text::Bold);
	t.setFillColor(sf::Color::White);
	this->t.setPosition(w, h);
	this->direction = 'S';
	auto head = new Object("kwadrat.png", "score", x, y);
	this->snake.push_front(head);
	auto tail = new Object("kwadrat.png", "tail", x, y-1);
	this->snake.push_back(tail);
}

Snake::~Snake()
{
	for (auto i : snake)
		delete i;
	this->snake.clear();
}

void Snake::addBody(char c)
{
	auto body = new Object("kwadrat.png", "tail", this->snake[snake.size()-1]->x, this->snake[snake.size() - 1]->y);
	this->snake.push_back(body);
	this->counter++;
	this->t.setString(to_string(counter));
}
char Snake::get_direction()
{
	return this->direction;
}

void Snake::set_direction(char c)
{
	this->direction = c;
}

deque <Object*> Snake::get_snake()
{
	return this->snake;
}

Text Snake::get_Text()
{
	return this->t;
}
string Snake::get_counter()
{
	return to_string(this->counter);
}
void Snake::set_Text(int x, int y)
{
	this->t.setPosition(x, y);
}