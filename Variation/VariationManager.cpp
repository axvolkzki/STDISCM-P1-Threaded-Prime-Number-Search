#include "VariationManager.h"
#include <iostream>

#include "../Config/GlobalConfig.h"

void VariationManager::executeVariation()
{
    color.red();
    cout << "Start Time: " << GlobalConfig::getInstance()->getTimestamp() << endl;
    color.reset();

    switch (this->variant) {
        case 1:
            this->executeVariant1();
            break;
        case 2:
            this->executeVariant2();
            break;
        case 3:
            this->executeVariant3();
            break;
        case 4:
            this->executeVariant4();
            break;
    }

    color.red();
    cout << "End Time: " << GlobalConfig::getInstance()->getTimestamp() << "\n" << endl;
    color.reset();

    this->joinAllThreads();
}

void VariationManager::executeVariant1()
{
    int range = this->targetNumber / this->numThreads;
    int start = 0;
    int end = range;

    for (int t = 0; t < this->numThreads; t++) {
        if (t == this->numThreads - 1) {
            end = this->targetNumber;
        }

        this->threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, start, end, t, std::ref(this->printer)));

        start = end + 1;
        end = start + range - 1;
    }

    this->joinAllThreads();
}

void VariationManager::executeVariant2()
{
    int range = this->targetNumber / this->numThreads;
    int start = 0;
    int end = range;

    for (int t = 0; t < this->numThreads; t++) {
        if (t == this->numThreads - 1) {
            end = this->targetNumber;
        }

        this->threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, start, end, t, std::ref(this->printer)));

        start = end + 1;
        end = start + range - 1;
    }

    this->joinAllThreads();

    this->printer->printPrimes(0, 0);
}

void VariationManager::executeVariant3()
{
}

void VariationManager::executeVariant4()
{
}

void VariationManager::joinAllThreads()
{
    for (auto& thread : this->threads) {
        if (thread.second.joinable()) {
            thread.second.join();
        }
    }
}