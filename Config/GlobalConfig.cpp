#include "GlobalConfig.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>


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

bool GlobalConfig::loadConfigFile(String &filename)
{
    bool isLoaded = false;

	// try {
	// 	ifstream file(filename);
	// 	if (!file.is_open()) {
	// 		throw runtime_error("Error: Could not open file " + filename);
	// 	}
	// 	else {
	// 		String line;
	// 		while (getline(file, line)) {
	// 			if (!parseConfigFile(line)) {
	// 				throw runtime_error("Error: Could not parse line " + line);
	// 				file.close();
	// 				break;
	// 			}
	// 		}

	// 		file.close();
	// 		isLoaded = true;
	// 	}
	// }
	// catch (const runtime_error& e) {
	// 	cerr << e.what() << endl;
	// 	isLoaded = false;
	// }

    std::ifstream file(filename);
    String keyThread, keyTarget;

    if (!file.is_open()) {
        return isLoaded;
    } else {
        if (!(file >> keyThread >> this->configData.numberOfThreads) || keyThread != "x") {
            return isLoaded;
        } else {
            if (!validateThreadCount(this->configData.numberOfThreads)) {
                return isLoaded;
            }
        }

        if (!(file >> keyTarget >> this->configData.targetNumber) || keyTarget != "y") {
            return isLoaded;
        } else {
            if (!validateTargetNumber(this->configData.targetNumber)) {
                return isLoaded;
            } else {
                isLoaded = true;
            }
        }

    }

    return isLoaded;
}

void GlobalConfig::printErrorConfigFile()
{
    color.red();
    cerr << "Error: Could not load configuration file." << endl;
    cerr << "Please check the following:" << endl;
    cerr << "1. The file must exist in the same directory. If not, please move it to the same directory as the executable." << endl;
    cerr << "2. The file must be named 'config.txt'." << endl;
    cerr << "3. The file must contain the following keys and values:" << endl;
    cerr << "   x <number of threads>" << endl;
    cerr << "   y <target number>" << endl;
    cerr << "4. The values must be positive integer." << endl;
    cerr << "5. The keys must be separated from the values by a space." << endl;
    cerr << "Example:" << endl;
    color.yellow();
    cerr << "x 4" << endl;
    cerr << "y 100" << endl;
    color.red();
    cerr << "Exiting..." << endl;
    color.reset();
}

int GlobalConfig::getNumberOfThreads() const {
    return this->configData.numberOfThreads;
}

int GlobalConfig::getTargetNumber() const {
    return this->configData.targetNumber;
}

String GlobalConfig::getTimestamp() const
{
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm localTime;
    localtime_s(&localTime, &currentTime);

    stringstream time;
    time << put_time(&localTime, "%I:%M:%S %p");
    return time.str();
}

bool GlobalConfig::validateThreadCount(int threadCount) {
    return threadCount > 0;
}

bool GlobalConfig::validateTargetNumber(int targetNumber) {
    return targetNumber > 0;
}

bool GlobalConfig::parseConfigFile(String& line) {
	bool isParsed = false;

	// istringstream iss(line);
	// String key;

	// if (!(iss >> key)) {
    //     return isParsed;
    // }

    // try {
    //     if (key == "x") {
    //         int value;
    //         if (iss >> value) {
    //             this->configData.numberOfThreads = value;
    //             isParsed = true;
    //         }
    //     }
    //     else if (key == "y") {
    //         int value;
    //         if (iss >> value) {
    //             this->configData.targetNumber = value;
    //             isParsed = true;
    //         }
    //     }
    //     else {
    //         throw invalid_argument("Unknown configuration key: " + key);
    //     }
    // }
    // catch (const invalid_argument& e) {
    //     cerr << "Error: " << e.what() << " in line: " << line << endl;
	// 	isParsed = false;
    // }

    return isParsed;
}

