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
    //this->processInput();

    this->exitApp();
}

bool MainMenu::isRunning() const
{
    return this->running;
}


/************ Private Functions ************/
void MainMenu::showMenu() const
{
    cout << "Welcome to Prime Finder!" << endl;
    cout << "Choose a variation for the configuration of checking and printing prime numbers:" << endl;
    cout << "[1] Search for prime numbers in a range and print them immediately" << endl;
    cout << "[2] Search for prime numbers in a range and print them at the end" << endl;
    cout << "[3] Search for prime numbers linearly and print them immediately" << endl;
    cout << "[4] Search for prime numbers linearly and print them at the end" << endl;
    cout << "[5] Exit" << endl;
    cout << endl;
}

void MainMenu::exitApp()
{
    this->running = false;
}

