#pragma once
#include <vector>
#include <thread>
#include <mutex>

#include <condition_variable>

#include "../TypeDefRepo.h"
#include "../Config/GlobalConfig.h"
#include "ASearch.h"
#include "../Command/APrint.h"
#include "../Command/PrintImmediately.h"
#include "../Command/PrintAtTheEnd.h"

class PrimeManager
{
public:
    PrimeManager(ASearch* searchMethod, int targetNumber, int numThreads, char printType) :
        searchMethod(searchMethod), numThreads(numThreads), targetNumber(targetNumber), printType(printType)
    {
        if (printType == 'A') { // Print immediately
            this->printer = PrintImmediately::getInstance();
        }
        else { // Print at the end once all threads are done
            this->printer = PrintAtTheEnd::getInstance();
        }
    }

    void executeSearch(int variant);

private:
    void searchByRange(int start, int end, int threadId, char printType);

    ASearch* searchMethod;
    int numThreads;
    int targetNumber;
    char printType;
    APrint* printer;
    ThreadVector threads;
    std::mutex mutex;  // For synchronizing output or shared data

    std::condition_variable cv;
    std::atomic<int> ready{0};
};