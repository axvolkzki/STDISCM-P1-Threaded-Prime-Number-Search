#include "MainMenu.h"  



MainMenu* MainMenu::sharedInstance = nullptr;

MainMenu::MainMenu() {
}

/************ Public Functions ************/

MainMenu* MainMenu::getInstance() {
    if (MainMenu::sharedInstance == nullptr) {
        MainMenu::sharedInstance = new MainMenu();
    }

    return MainMenu::sharedInstance;
}

void MainMenu::initialize()
{
    if (sharedInstance == nullptr) {
        sharedInstance = new MainMenu();
    }
}

void MainMenu::destroy()
{
    if (sharedInstance != nullptr) {
        delete sharedInstance;
        sharedInstance = nullptr;
    }
}

void MainMenu::startApp()
{
    this->showMenu();
    this->processInput();
}

bool MainMenu::isRunning() const
{
    return this->running;
}


/************ Private Functions ************/
void MainMenu::showMenu() const
{
    cout << "Welcome to Prime Finder!" << endl;
    cout << "Choose a variation for the configuration:" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Exit" << endl;
}

void MainMenu::exitApp()
{
    this->running = false;
}

