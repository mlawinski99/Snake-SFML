#include "Game.h"


Game::Game()
{
    unique_ptr<Object> ptr(new Object("game_over.jpg", "game_over", 0, 0));
    this->game_over = move(ptr);
    unique_ptr<Object> ptr2(new Object("press_space.png", "game_over", 280, 600));
    this->pstc = move(ptr2);
    auto f1 = new Apple(this->fruits);
    auto f2 = new Banana(this->fruits);
}

int Game::Tick(Snake& s, char c, int n, vector<Fruit*>& fruits)
{
    return 0;
}

Game::~Game()
{
    for (auto i : fruits)
        delete i;
    for (auto h : game)
        delete h;
    this->fruits.clear();
    this->game.clear();
}

void Game::moveHead(Snake& s, char c)
{
    if (c == 'N')
        s.get_snake()[0]->y = s.get_snake()[0]->y--;
    if (c == 'S')
        s.get_snake()[0]->y = s.get_snake()[0]->y++;
    if (c == 'W')
        s.get_snake()[0]->x = s.get_snake()[0]->x--;
    if (c == 'E')
        s.get_snake()[0]->x = s.get_snake()[0]->x++;
}

void Game::moveBody(Snake& s)
{
    for (int i = s.get_snake().size() - 1; i > 0; i--)
    {
        s.get_snake()[i]->x = s.get_snake()[i - 1]->x;
        s.get_snake()[i]->y = s.get_snake()[i - 1]->y;
    }
}

int Game::checkPosition(Snake &s)
{
    for (int i = 4; i < s.get_snake().size() - 1; i++) // sprawdzenie czy 2 elementy weza nie znajduja sie na tym samym polu
    {
        if (s.get_snake()[0]->x == s.get_snake()[i]->x && s.get_snake()[0]->y == s.get_snake()[i]->y)
            return -1;
    }
}

int Game::eatFruit(Snake &s,vector<Fruit*>& fruits, int n)
{
    if (s.get_snake()[0]->x == fruits[n]->ptr->x && s.get_snake()[0]->y == fruits[n]->ptr->y)
        return 0;
    return 1;
}

int Game::random(vector<Fruit*>& fruits, int n)
{
    n = (rand() % 2) + 0; //losowanie owocu
    fruits[n]->ptr->x = (rand() % 18) + 0;
    fruits[n]->ptr->y = (rand() % 18) + 0;
    fruits[n]->ptr->s.setPosition(40 * fruits[n]->ptr->x, 40 * fruits[n]->ptr->y);
    return n;
}

int Game::checkSnakeSize(int& number)
{
    if (number >= 18 * 18)
        return -1;
    return 0;
}

vector <Object*> Game::get_vect()
{
    return this->game;
}

