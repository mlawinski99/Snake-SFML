#include "DrawableManager.h"

void DrawableManager::drawMenu(Menu *menu, RenderWindow& w)
{
    drawVect(menu->get_vect(), w);
}
void DrawableManager::drawMenu(string& choice, Menu* menu, RenderWindow& w, Single_Player* single, Multiplayer* multi, int number)
{
    if (choice == "menu")
        this->drawMenu(menu, w);
    else if (choice == "single")
        this->drawSingle(single, w, number);
    else if (choice == "multi")
        this->drawMulti(multi, w, number);
    else
        this->drawGM(single, multi, w);
}
void DrawableManager::drawSingle(Single_Player *single_player, RenderWindow& w, int number)
{
    drawVect(single_player->get_vect(), w);
    for (int i = 0; i < single_player->get_snake()->get_snake().size(); i++)
    {
        single_player->get_snake()->get_snake()[i]->s.setPosition(single_player->get_snake()->get_snake()[i]->x * 40, single_player->get_snake()->get_snake()[i]->y * 40);
        w.draw(single_player->get_snake()->get_snake()[i]->s);
        w.draw(single_player->fruits[number]->ptr->s);
        w.draw(single_player->get_snake()->get_Text());
    }
}

void DrawableManager::drawMulti(Multiplayer* multiplayer, RenderWindow& w, int number)
{
    drawVect(multiplayer->get_vect(), w);
    for (int i = 0; i < multiplayer->get_snake1()->get_snake().size(); i++)
    {
        multiplayer->get_snake1()->get_snake()[i]->s.setPosition(multiplayer->get_snake1()->get_snake()[i]->x * 40, multiplayer->get_snake1()->get_snake()[i]->y * 40);
        w.draw(multiplayer->get_snake1()->get_snake()[i]->s);
        w.draw(multiplayer->fruits[number]->ptr->s);
        w.draw(multiplayer->get_snake1()->get_Text());
    }
    for (int j = 0; j < multiplayer->get_snake2()->get_snake().size(); j++)
    {
        multiplayer->get_snake2()->get_snake()[j]->s.setPosition(multiplayer->get_snake2()->get_snake()[j]->x * 40, multiplayer->get_snake2()->get_snake()[j]->y * 40);
        w.draw(multiplayer->get_snake2()->get_snake()[j]->s);
        w.draw(multiplayer->fruits[number]->ptr->s);
        w.draw(multiplayer->get_snake2()->get_Text());
    }
}

void DrawableManager::drawGM(Single_Player *single_player, Multiplayer *multiplayer, RenderWindow &w)
{
    if (single_player != nullptr)
    {
        w.draw(single_player->game_over->s);
        w.draw(single_player->pstc->s);
        single_player->get_score()->s.setPosition(520, 400);
        w.draw(single_player->get_score()->s);
        single_player->get_snake()->set_Text(600, 450);
        w.draw(single_player->get_snake()->get_Text());
    }
    else if (multiplayer != nullptr)
    {
        w.draw(multiplayer->game_over->s);
        w.draw(multiplayer->pstc->s);
        multiplayer->get_score1()->s.setPosition(220, 400);
        multiplayer->get_score2()->s.setPosition(820, 400);
        w.draw(multiplayer->get_score1()->s);
        w.draw(multiplayer->get_score2()->s);
        multiplayer->get_snake1()->set_Text(300, 450);
        multiplayer->get_snake2()->set_Text(900, 450);
        w.draw(multiplayer->get_snake1()->get_Text());
        w.draw(multiplayer->get_snake2()->get_Text());
    }
}
void DrawableManager::drawVect(vector<Object*> vect, RenderWindow& w)
{
    for (auto i : vect)
    {
        w.draw(*&i->s);
    }
}
