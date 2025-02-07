#pragma once
#include <vector>
#include <thread>
#include <mutex>

#include "../TypeDefRepo.h"
#include "../Helper/Colors.h"
#include "../PrimeSearch/ASearch.h"
#include "../Print/APrint.h"

class VariationManager
{
public:
    VariationManager(unsigned long int targetNumber, unsigned int numThreads, ASearch* searchMethod, APrint* printer, int variant) :
        targetNumber(targetNumber), numThreads(numThreads), searchMethod(searchMethod), printer(printer), variant(variant)
    {
    }

    void executeVariation();

private:
    unsigned int numThreads;
    unsigned long int targetNumber;
    ASearch* searchMethod;
    APrint* printer;
    int variant;

    vector<pair<unsigned int, std::thread>> threads;
    Colors color;
    std::mutex variationMutex;

    void executeVariant1();
    void executeVariant2();
    void executeVariant3();
    void executeVariant4();

    void joinAllThreads();

    void displayStartTime();
    void displayEndTime();
};
