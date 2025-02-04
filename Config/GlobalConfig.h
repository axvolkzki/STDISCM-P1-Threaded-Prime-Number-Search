#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "../TypedefRepo.h"

class GlobalConfig
{
public:
    static GlobalConfig* getInstance();

    static void initialize();
    static void destroy();

    void loadConfigFile(String& filename);				// Loads the config file
	void printConfig() const;							// Prints the config

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
	bool parseConfigFile(String& line);					// Parses the config file
};