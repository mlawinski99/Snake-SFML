#include "Multiplayer.h"
Multiplayer::Multiplayer() :Game()
{
    this->player1 = new Snake(10,2,140 ,220);
    this->player2 = new Snake(20,2, 1150, 220);
    Object* background = new Object("game_background.jpg", "game_background", 0,0);
    this->game.push_back(background);
    Object* wasd = new Object("wasd.png", "wasd", 15, 547);
    this->game.push_back(wasd);
    Object* arrows = new Object("arrows.png", "arrows", 1015, 550);
    this->game.push_back(arrows);
    Object* background_game = new Object("background_game.jpg", "background_game", 280, 0);
    this->game.push_back(background_game);
    background_game->s.setScale(0.9, 0.9);
    Object* score1 = new Object("score.png", "score1", 40, 150);
    Object* score2= new Object("score.png", "score2", 1040, 150);
    this->game.push_back(score1);
    this->game.push_back(score2);
    this->score1 = score1;
    this->score2 = score2;

    background_game->s.setScale(0.9, 0.9);
}
Multiplayer::~Multiplayer()
{
    delete this->player1;
    delete this->player2;
    this->player1 = nullptr;
    this->player2 = nullptr;
    this->score1 = nullptr;
    this->score2 = nullptr;
}
Snake* Multiplayer::get_snake1()
{
    return this->player1;
}
Snake* Multiplayer::get_snake2()
{
    return this->player2;
}
int Multiplayer::Tick(Snake& s, char c, int n, vector<Fruit*>& fruits)
{
    moveBody(s);
    moveHead(s, c);
    if (checkPosition(s) == -1)
        return -1;
    if (s.get_snake()[0]->x > 24 || s.get_snake()[0]->y > 18 || s.get_snake()[0]->x < 7 || s.get_snake()[0]->y < 0)
        return -1;
    if (eatFruit(s, fruits, n) == 0)
    {
        s.addBody(c); //wydluzenie weza
        n = (rand() % 2) + 0; //losowanie owocu
        fruits[n]->ptr->x = (rand() % 18) + 7;
        fruits[n]->ptr->y = (rand() % 18) + 0;
        fruits[n]->ptr->s.setPosition(40 * fruits[n]->ptr->x, 40 * fruits[n]->ptr->y);
    }
    return n;
}

int Multiplayer::snakesPosition(Snake& s1, Snake& s2)
{
    for (int i = 0; i < s1.get_snake().size(); i++)
    {
        for (int j = 0; j < s2.get_snake().size(); j++)
        {
            if (s1.get_snake()[i]->x == s2.get_snake()[j]->x && s1.get_snake()[i]->y == s2.get_snake()[j]->y)
                return -1;
        }
    }
    return 0;
}

int Multiplayer::checkSnakeFruit(Snake& s1,Snake &s2, vector<Fruit*>& fruits, int n)
{
   
    int size = s1.get_snake().size()+s2.get_snake().size();
    int temp;
    auto f = std::async(launch::async, [&] { temp = checkSnakeSize(size); });
    if (temp == -1)
        return -1;
    for (int i = 0; i < s1.get_snake().size(); i++)
    {
        for(int j=0;j<s2.get_snake().size();j++)
        if ((s1.get_snake()[i]->x == fruits[n]->ptr->x && s1.get_snake()[i]->y == fruits[n]->ptr->y) || (s2.get_snake()[j]->x == fruits[n]->ptr->x && s2.get_snake()[j]->y == fruits[n]->ptr->y))
        {
            fruits[n]->ptr->x = (rand() % 18) + 7;
            fruits[n]->ptr->y = (rand() % 18) + 0;
            fruits[n]->ptr->s.setPosition(40 * fruits[n]->ptr->x, 40 * fruits[n]->ptr->y);
            i = 0;
        }
    }
    return 0;
}
Object* Multiplayer::get_score1()
{
    return this->score1;
}Object* Multiplayer::get_score2()
{
    return this->score2;
}