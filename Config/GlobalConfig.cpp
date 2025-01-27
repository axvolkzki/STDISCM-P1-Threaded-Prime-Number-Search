#include "GlobalConfig.h"
#include "../TypedefRepo.h"

#include <iostream>
#include <fstream>
#include <sstream>


GlobalConfig* GlobalConfig::sharedInstance = nullptr;

GlobalConfig::GlobalConfig() {
    this->configData.numberOfThreads = 0;
    this->configData.targetNumber = 0;
}

GlobalConfig* GlobalConfig::getInstance() {
    if (GlobalConfig::sharedInstance == nullptr) {
        GlobalConfig::sharedInstance = new GlobalConfig();
    }

    return GlobalConfig::sharedInstance;
}

void GlobalConfig::initialize()
{
	if (sharedInstance == nullptr) {
		sharedInstance = new GlobalConfig();
	}
}

void GlobalConfig::destroy()
{
    if (sharedInstance != nullptr) {
        delete sharedInstance;
        sharedInstance = nullptr;
    }
}

void GlobalConfig::loadConfigFile(String& filename) {
	bool isLoaded = false;

	try {
		ifstream file(filename);
		if (!file.is_open()) {
			throw runtime_error("Error: Could not open file " + filename);
		}
		else {
			String line;
			while (getline(file, line)) {
				if (!parseConfigFile(line)) {
					throw runtime_error("Error: Could not parse line " + line);
					file.close();
					break;
				}
			}

			file.close();
			isLoaded = true;
		}
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
		isLoaded = false;
	}
}

void GlobalConfig::printConfig() const {
    cout << "Configuration: " << endl;
    cout << "Number of threads: " << this->configData.numberOfThreads << endl;
    cout << "Target number: " << this->configData.targetNumber << endl;
}

int GlobalConfig::getNumberOfThreads() const {
    return this->configData.numberOfThreads;
}

int GlobalConfig::getTargetNumber() const {
    return this->configData.targetNumber;
}


bool GlobalConfig::parseConfigFile(String& line) {
	bool isParsed = false;

	istringstream iss(line);
	String key;

	if (!(iss >> key)) {
		isParsed = false;		// Empty line
	}

    try {
        if (key == "x") {
            int value;
            if (iss >> value) {
                this->configData.numberOfThreads = value;
                isParsed = true;
            }
        }
        else if (key == "y") {
            int value;
            if (iss >> value) {
                this->configData.targetNumber = value;
                isParsed = true;
            }
        }
        else {
            throw invalid_argument("Unknown configuration key: " + key);
        }
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << " in line: " << line << endl;
		isParsed = false;
    }

    return isParsed;
}

