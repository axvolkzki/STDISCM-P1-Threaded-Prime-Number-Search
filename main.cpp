#include "TypeDefRepo.h"
#include "Config/GlobalConfig.h"
#include "Menu/MainMenu.h"

int main() {
    GlobalConfig::initialize();														// Initialize the instance of GlobalConfig
	MainMenu::initialize();															// Initialize the instance of MainMenu

    String configPath = "config.txt";												// Set the path to the configuration file
	GlobalConfig::getInstance()->loadConfigFile(configPath);                        // Load the configuration file
    
    bool running = true;
    while (running) {
        MainMenu::getInstance()->start();										// Start the application
    
        running = MainMenu::getInstance()->isRunning();								// Check if the application is running
    }

    MainMenu::destroy();																// Destroy the instance of MainMenu
    GlobalConfig::destroy();															// Destroy the instance of GlobalConfig

    return 0;
}