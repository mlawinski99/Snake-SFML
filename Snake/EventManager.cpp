#include "EventManager.h"
void EventManager::WindowClose(Event& event, RenderWindow &w)
{
    if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        w.close();
}
EventManager::EventManager()
{
    this->choice = "menu";
}
int EventManager::pollEvent(Event &event,RenderWindow& w,Single_Player*& single_player, Multiplayer*& multiplayer,int& number, GameManager*& gameManager, MenuManager*& menuManager)
{
    WindowClose(event, w);
    if (single_player != nullptr)
        gameManager->control(event, single_player);
    else if (multiplayer != nullptr)
        gameManager->control(event, multiplayer);
    else if (this->choice == "menu")
    {
        if (menuManager->menuChoice(event, this->choice) == -1)
            return -1;
        menuManager->moveArrow(event);
    }
    else if (this->choice == "single")
        number = gameManager->newSingle(single_player);
    else if (this->choice == "multi")
        number = gameManager->newMulti(multiplayer);
    return number;
}
int EventManager::EventManagement(sf::RenderWindow& w, Clock cloak, double timer, double delay, Single_Player*& single_player, Multiplayer*& multiplayer)
{
    MenuManager* menuManager = new MenuManager();
    DrawableManager* drawManager = new DrawableManager();
    GameManager* gameManager = new GameManager();
    int number=0;
    while (w.isOpen())
    {
        double time = cloak.getElapsedTime().asSeconds();
        cloak.restart();
        timer += time;
        Event event;
        while (w.pollEvent(event))
            if (pollEvent(event, w, single_player, multiplayer, number, gameManager, menuManager) == -1)
            {
                delete menuManager, gameManager, drawManager;
                menuManager, gameManager, drawManager = nullptr;
                return -1;
            }
        number = gameManager->GameManagement(timer, delay, event, single_player, multiplayer, number, choice);
        w.clear(Color::White);
        drawManager->drawMenu(this->choice,menuManager, w,single_player,multiplayer,number);
        w.display();
    }
    delete menuManager, gameManager, drawManager;
    menuManager, gameManager, drawManager = nullptr;
    return 0;
}