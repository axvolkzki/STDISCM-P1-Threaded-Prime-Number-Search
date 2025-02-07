#include "GlobalConfig.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>


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
    // milliseconds
    // auto now = chrono::system_clock::now();
    // auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()) % 1000;

    // time_t currentTime = chrono::system_clock::to_time_t(now);

    // tm localTime;
    // localtime_s(&localTime, &currentTime);

    // stringstream time;
    // time << put_time(&localTime, "%I:%M:%S") << '.' << setfill('0') << setw(3) << ms.count();

    // return time.str();

    // nanoseconds
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(duration) % 1000000000; // Nanoseconds part

    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm localTime;
    localtime_s(&localTime, &currentTime);

    std::stringstream time;
    time << std::put_time(&localTime, "%I:%M:%S") << '.' 
         << std::setfill('0') << std::setw(9) << ns.count(); // 9 digits for nanoseconds

    return time.str();
}

bool GlobalConfig::validateThreadCount(int threadCount) {
    return threadCount > 0;
}

bool GlobalConfig::validateTargetNumber(int targetNumber) {
    return targetNumber > 0;
}