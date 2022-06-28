#include "GameManager.h"


void GameManager::control(Event& event, Single_Player*& single_player)
{
    if ((event.key.code == Keyboard::Down || event.key.code == Keyboard::S) && single_player->get_snake()->get_direction() != 'N')
        single_player->get_snake()->set_direction('S');
    if ((event.key.code == Keyboard::Left || event.key.code == Keyboard::A) && single_player->get_snake()->get_direction() != 'E')
        single_player->get_snake()->set_direction('W');
    if ((event.key.code == Keyboard::Right || event.key.code == Keyboard::D) && single_player->get_snake()->get_direction() != 'W')
        single_player->get_snake()->set_direction('E');
    if ((event.key.code == Keyboard::Up || event.key.code == Keyboard::W) && single_player->get_snake()->get_direction() != 'S')
        single_player->get_snake()->set_direction('N');
}
void GameManager::control(Event& event, Multiplayer*& multiplayer)
{
    if ((event.key.code == Keyboard::S) && multiplayer->get_snake1()->get_direction() != 'N')
        multiplayer->get_snake1()->set_direction('S');
    if ((event.key.code == Keyboard::A) && multiplayer->get_snake1()->get_direction() != 'E')
        multiplayer->get_snake1()->set_direction('W');
    if ((event.key.code == Keyboard::D) && multiplayer->get_snake1()->get_direction() != 'W')
        multiplayer->get_snake1()->set_direction('E');
    if ((event.key.code == Keyboard::W) && multiplayer->get_snake1()->get_direction() != 'S')
        multiplayer->get_snake1()->set_direction('N');

    if ((event.key.code == Keyboard::Down) && multiplayer->get_snake2()->get_direction() != 'N')
        multiplayer->get_snake2()->set_direction('S');
    if ((event.key.code == Keyboard::Left) && multiplayer->get_snake2()->get_direction() != 'E')
        multiplayer->get_snake2()->set_direction('W');
    if ((event.key.code == Keyboard::Right) && multiplayer->get_snake2()->get_direction() != 'W')
        multiplayer->get_snake2()->set_direction('E');
    if ((event.key.code == Keyboard::Up) && multiplayer->get_snake2()->get_direction() != 'S')
        multiplayer->get_snake2()->set_direction('N'); 
}

int GameManager::newSingle(Single_Player*& single_player)
{
    int number = (rand() % 2) + 0;
    single_player = new Single_Player();
    single_player->fruits[number]->ptr->x = (rand() % 18) + 0;
    single_player->fruits[number]->ptr->y = (rand() % 18) + 0;
    single_player->fruits[number]->ptr->s.setPosition(40 * single_player->fruits[number]->ptr->x, 40 * single_player->fruits[number]->ptr->y);
    return number;
}
int GameManager::newMulti(Multiplayer*& multiplayer)
{
    int number = (rand() % 2) + 0;
    multiplayer = new Multiplayer();
    multiplayer->fruits[number]->ptr->x = (rand() % 18) + 7;
    multiplayer->fruits[number]->ptr->y = (rand() % 18) + 0;
    multiplayer->fruits[number]->ptr->s.setPosition(40 * multiplayer->fruits[number]->ptr->x, 40 * multiplayer->fruits[number]->ptr->y);
    return number;
}


void GameManager::GameOver(Event &event, Single_Player*& single_player, Multiplayer*& multiplayer, string& choice)
{
    if ((event.key.code == Keyboard::Space))
    {
        choice = "menu";
        Log::LogToFile(single_player, multiplayer);
        if (single_player != nullptr)   
        {
            delete single_player;
            single_player = nullptr;
        }
        else if (multiplayer != nullptr)
        {
            delete multiplayer;
            multiplayer = nullptr;
        }
    }
}

int GameManager::Single(double& timer, double& delay, Single_Player*& single_player, int number, string &choice)
{
    if (timer > delay)
    {
        char c = single_player->get_snake()->get_direction();
        timer = 0;
        number = single_player->Tick(*single_player->get_snake(), c, number, single_player->fruits);
        if (number != -1)
        {
            int check = single_player->checkSnakeFruit(*single_player->get_snake(), single_player->fruits, number);
            if (check == -1)
            {
                choice = "GM";
                number = (rand() % 2) + 0;
            }
        }
        else if (number == -1)
        {
            choice = "GM";
            number = (rand() % 2) + 0;
        }
    }
    return number;
}

int GameManager::Multi(double& timer, double& delay, Multiplayer*& multiplayer, int number, string& choice)
{
    if (timer > delay)
    {
        int check = multiplayer->snakesPosition(*multiplayer->get_snake1(), *multiplayer->get_snake2());
        char c = multiplayer->get_snake1()->get_direction();
        timer = 0;
        number = multiplayer->Tick(*multiplayer->get_snake1(), c, number, multiplayer->fruits);
        if (number != -1)
        {
            int check = multiplayer->checkSnakeFruit(*multiplayer->get_snake1(), *multiplayer->get_snake2(), multiplayer->fruits, number);
            if (check == -1)
            {
                choice = "GM";
                number = (rand() % 2) + 0;
            }
        }
        if (number == -1 || check == -1)
        {
            choice = "GM";
            number = (rand() % 2) + 0;
        }
        else
        {
            c = multiplayer->get_snake2()->get_direction();
            number = multiplayer->Tick(*multiplayer->get_snake2(), c, number, multiplayer->fruits);
            if (number == -1)
            {
                choice = "GM";
                number = (rand() % 2) + 0;
            }
        }
    }
    return number;
}

int GameManager::GameManagement(double &timer, double &delay,Event& event, Single_Player*& single_player, Multiplayer*& multiplayer, int number, string& choice)
{
    if (choice == "single")
        number = this->Single(timer, delay, single_player, number, choice);
    else if (choice == "multi")
        number = this->Multi(timer, delay, multiplayer, number, choice);
    else if (choice == "GM")
        this->GameOver(event, single_player, multiplayer, choice);
    return number;
}

