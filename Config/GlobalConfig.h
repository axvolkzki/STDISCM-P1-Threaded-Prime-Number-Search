#pragma once

#include "../TypedefRepo.h"
#include "../Helper/Colors.h"

class GlobalConfig
{
public:
    static GlobalConfig* getInstance();

    static void initialize();
    static void destroy();
					
    bool loadConfigFile(String& filename);				// Loads the config file
    void printErrorConfigFile();						// Prints an error message if the config file is not loaded

    int getNumberOfThreads() const;
    int getTargetNumber() const;
    String getTimestamp() const;

private:
	GlobalConfig();
	static GlobalConfig* sharedInstance;

    struct ConfigData
    {
        int numberOfThreads;
        int targetNumber;
    };

    ConfigData configData;								// Config variable
    Colors color;										// Color variable
    
    bool validateThreadCount(int threadCount);			// Validates the thread count
    bool validateTargetNumber(int targetNumber);			// Validates the target number
    
    bool parseConfigFile(String& line);					// Parses the config file
};