#pragma once
#include <vector>
#include <thread>

#include "../TypeDefRepo.h"
#include "../Helper/Colors.h"
#include "../PrimeSearch/ASearch.h"
#include "../Print/APrint.h"

class VariationManager
{
public:
    VariationManager(int targetNumber, int numThreads, ASearch* searchMethod, APrint* printer, int variant) :
        targetNumber(targetNumber), numThreads(numThreads), searchMethod(searchMethod), printer(printer), variant(variant)
    {
    }

    void executeVariation();

private:
    int numThreads;
    int targetNumber;
    ASearch* searchMethod;
    APrint* printer;
    int variant;

    vector<pair<int, std::thread>> threads;
    Colors color;

    void executeVariant1();
    void executeVariant2();
    void executeVariant3();
    void executeVariant4();

    void joinAllThreads();
};
