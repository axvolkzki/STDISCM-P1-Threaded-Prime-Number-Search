#pragma once
#include <iostream>

#include "../TypeDefRepo.h"
#include "MainMenu.h"

class MainMenu
{
public:
    static MainMenu* getInstance();

    static void initialize();
    static void destroy();

    void startApp();
    bool isRunning() const;

private:
    MainMenu();
    static MainMenu* sharedInstance;

    bool running = true;

    void showMenu() const;

    bool validateInput(String& input) const;
    void processInput() const;
    
    void exitApp();
};