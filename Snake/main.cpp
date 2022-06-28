// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Object.h"
#include "Single_Player.h"
#include "Multiplayer.h"
#include "Menu.h"
#include <Windows.h>
#include "EventManager.h"

using namespace sf;
using namespace std;

int main()
{
    srand(time(0));
    Single_Player* single_player = nullptr;
    Multiplayer* multiplayer = nullptr;
    EventManager* event = new EventManager();
    Clock cloak;
    double timer = 0;
    double delay = 0.1;
    RenderWindow w(VideoMode(1280, 720), "Snake");
    event->EventManagement(w, cloak, timer, delay, single_player, multiplayer);
    delete event;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
