#pragma once
#include <iostream>

#include "../TypeDefRepo.h"
#include "../Helper/Colors.h"
#include "../Config/GlobalConfig.h"
#include "../PrimeSearch/ASearch.h"
#include "../Print/APrint.h"

class MainMenu
{
public:
    static MainMenu* getInstance();

    static void initialize();
    static void destroy();

    void start();
    bool isRunning() const;

private:
    MainMenu();
    static MainMenu* sharedInstance;
    Colors color;
    
    bool running = true;
    int variant = 0;

    ASearch* searchMethod = nullptr;
    APrint* printer = nullptr;

    void showMenu() const;
    void displayCurrentConfig() const;

    int validateInput();
    bool isValidInput(String& input) const;

    void exit();
};