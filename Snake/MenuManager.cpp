#include "MenuManager.h"

MenuManager::MenuManager() : Menu(this->arrow) {};
MenuManager::~MenuManager()
{
    this->arrow = nullptr;
}
void MenuManager::moveArrow(Event &event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
        moveArrowUp(event);
    else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
        moveArrowDown(event);
}

void MenuManager::moveArrowUp(Event& event)
{
    if (this->arrow->s.getPosition() == Vector2f(550, 720 / 3))
        this->arrow->s.setPosition(550, 720 / 1.1);
    else if (this->arrow->s.getPosition() == Vector2f(550, 720 / 2))
        this->arrow->s.setPosition(550, 720 / 3);
    else if (this->arrow->s.getPosition() == Vector2f(550, 720 / 1.1))
        this->arrow->s.setPosition(550, 720 / 2);
}
void MenuManager::moveArrowDown(Event& event)
{
    if (this->arrow->s.getPosition() == Vector2f(550, 720 / 3))
        this->arrow->s.setPosition(550, 720 / 2);
    else if (this->arrow->s.getPosition() == Vector2f(550, 720 / 2))
        this->arrow->s.setPosition(550, 720 / 1.1);
    else if (this->arrow->s.getPosition() == Vector2f(550, 720 / 1.1))
        this->arrow->s.setPosition(550, 720 / 3);
}
int MenuManager::menuChoice(Event& event, string& choice)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
    {
        Vector2f position = this->arrow->s.getPosition();
        if (position == Vector2f(550, 720 / 3))
            choice = "single";
        else if (position == Vector2f(550, 720 / 2))
            choice = "multi";
        else if (position == Vector2f(550, 720 / 1.1))
              return -1;
        return 0;
    }
}