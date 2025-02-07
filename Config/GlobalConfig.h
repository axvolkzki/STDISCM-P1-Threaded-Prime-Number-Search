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

    unsigned int getNumberOfThreads() const;
    unsigned long int getTargetNumber() const;
    String getTimestamp() const;

private:
	GlobalConfig();
	static GlobalConfig* sharedInstance;

    struct ConfigData
    {
        unsigned int numberOfThreads;                   // aim to be less than the target number for PC performance reasons; from 1 to 2^32-1
        unsigned long int targetNumber;                 // to support large numbers from 0 to 2^64-1
    };

    ConfigData configData;								// Config variable
    Colors color;										// Color variable
    
    bool validateThreadCount(unsigned int threadCount);			// Validates the thread count
    bool validateTargetNumber(unsigned long int targetNumber);			// Validates the target number
};