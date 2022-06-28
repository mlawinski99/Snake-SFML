#include "Menu.h"
Menu::Menu(Object*& a)
{

     Object* background = new Object("jungle2.jpg", "background", 0, 0);
     this->vect.push_back(background);
     Object* snake = new Object("snake.png", "snake", 0, 200);
     this->vect.push_back(snake);
     Object* snake_napis = new Object("snake_napis.png", "snake_napis", 550, 0);
     this->vect.push_back(snake_napis);
     Object* snake_sp = new Object("snake_sp.png", "snake_sp", 600, 720 / 3);
     this->vect.push_back(snake_sp);
     Object* snake_mp = new Object("snake_mp.png", "snake_mp", 600, 720 / 2);
     this->vect.push_back(snake_mp);
     Object* snake_e = new Object("snake_exit.png", "snake_e", 600, 720 / 1.1);
     this->vect.push_back(snake_e);
     Object* arrow = new Object("arrow.png", "arrow", 550, 720 / 3);
     this->vect.push_back(arrow);
     
     a = arrow;
     snake->s.setScale(0.7, 0.7);
     arrow->s.setScale(0.1, 0.1);
}

vector <Object*> Menu::get_vect()
{
    return this->vect;
}

Menu::~Menu()
{
    for (auto i : vect)
        delete i;
    this->vect.clear();
}