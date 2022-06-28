#include "Single_Player.h"
Single_Player::Single_Player() :Game()
{
    Object* background = new Object("game_background.jpg", "game_background", 0,0);
    this->game.push_back(background);
    Object* wasd = new Object("wasd.png", "wasd", 740, 550);
    this->game.push_back(wasd);
    Object* arrows = new Object("arrows.png", "wasd", 1000, 551);
    this->game.push_back(arrows);
	this->snake = new Snake(0, 2, 1000, 200);
    Object* background_game = new Object("background_game.jpg", "background_game", 0, 0);
    this->game.push_back(background_game);
    background_game->s.setScale(0.9, 0.9);
    Object* score = new Object("score.png", "score", 920, 150);
    this->game.push_back(score);
    this->score = score;
    background_game->s.setScale(0.9, 0.9);
}
Single_Player::~Single_Player()
{
	delete this->snake;
	this->snake = nullptr;
    this->score = nullptr;
}
Snake* Single_Player::get_snake()
{
    return this->snake;
}

int Single_Player::checkSnakeFruit(Snake& s, vector<Fruit*>& fruits, int n)
{
   int size = s.get_snake().size();
   int temp;
   auto f = std::async(launch::async, [&] { temp=checkSnakeSize(size); });
    if(temp == -1)
        return -1;
    for (int i = 0; i < s.get_snake().size(); i++)
    {    
        if (s.get_snake()[i]->x == fruits[n]->ptr->x && s.get_snake()[i]->y == fruits[n]->ptr->y)
        {
            fruits[n]->ptr->x = (rand() % 18) + 0;
            fruits[n]->ptr->y = (rand() % 18) + 0;
            fruits[n]->ptr->s.setPosition(40 * fruits[n]->ptr->x, 40 * fruits[n]->ptr->y);
            i = 0;
        }
    }
    return 0;
}

int Single_Player::Tick(Snake& s, char c, int n, vector<Fruit*>& fruits)
{
    moveBody(s); 
    moveHead(s, c);
    if (checkPosition(s) == -1)
        return -1;
    if (s.get_snake()[0]->x > 17 || s.get_snake()[0]->y > 17 || s.get_snake()[0]->x < 0 || s.get_snake()[0]->y < 0)
        return -1;
    if (eatFruit(s, fruits, n) == 0)
    {
        s.addBody(c); //wydluzenie weza
        return random(fruits, n);
    }
    return n;
}
Object* Single_Player::get_score()
{
    return this->score;
}