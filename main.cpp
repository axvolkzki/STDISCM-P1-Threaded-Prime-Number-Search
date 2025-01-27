#include "TypeDefRepo.h"
#include "Config/GlobalConfig.h"

int main() {
    GlobalConfig::initialize();														// Initialize the instance of GlobalConfig
	String configPath = "config.txt";												// Set the path to the configuration file
	GlobalConfig::getInstance()->loadConfigFile(configPath);                        // Load the configuration file

    GlobalConfig::getInstance()->printConfig();										// Print the configuration
    return 0;
}