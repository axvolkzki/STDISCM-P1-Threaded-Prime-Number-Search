#include "TypeDefRepo.h"
#include "Config/GlobalConfig.h"
#include "Menu/MainMenu.h"
#include "Helper/Colors.h"

int main() {
    Colors colors;
    bool running = true;
    

    GlobalConfig::initialize();														// Initialize the instance of GlobalConfig
	MainMenu::initialize();															// Initialize the instance of MainMenu

    String configPath = "config.txt";												// Set the path to the configuration file

    if (!GlobalConfig::getInstance()->loadConfigFile(configPath)) {					// Load the configuration file
        GlobalConfig::getInstance()->printErrorConfigFile();						// Print an error message if the configuration file is not loaded
        running = false;
        return 1;
    }

    while (running) {
        MainMenu::getInstance()->start();										// Start the application
        running = MainMenu::getInstance()->isRunning();							// Check if the application is running
    }
    

    MainMenu::destroy();															// Destroy the instance of MainMenu
    GlobalConfig::destroy();														// Destroy the instance of GlobalConfig

    return 0;
}