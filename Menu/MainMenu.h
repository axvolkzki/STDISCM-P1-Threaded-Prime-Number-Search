#pragma once
#include <iostream>

#include "../TypeDefRepo.h"
#include "MainMenu.h"
#include "../Config/GlobalConfig.h"
#include "../Prime/PrimeManager.h"
#include "../Prime/ASearch.h"
#include "../Prime/SearchRange.h"
#include "../Prime/SearchLinear.h"

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
    int variant = 0;


    void showMenu() const;

    int validateInput();
    bool isValidInput(String& input) const;
    
    void processInput() const;

    void exitApp();
};