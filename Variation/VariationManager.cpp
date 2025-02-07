#include "VariationManager.h"
#include <iostream>
#include <atomic>
#include <memory>

#include "../Config/GlobalConfig.h"

void VariationManager::executeVariation()
{
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

    this->joinAllThreads();
}

void VariationManager::executeVariant1()
{
    std::atomic<bool> dummyFlag = true; // Unused, but needed for function signature
    unsigned long int range = this->targetNumber / this->numThreads;
    unsigned long int start = 0;
    unsigned long int end = range;

    color.green();
    cout << "All Prime Numbers: " << endl;
    color.reset();

    for (unsigned int t = 0; t < this->numThreads; t++) {
        if (t == this->numThreads - 1) {
            end = this->targetNumber;
        }

        this->threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, start, end, t, std::ref(this->printer), std::ref(dummyFlag)));

        start = end + 1;
        end = start + range - 1;
    }

    this->joinAllThreads();

    color.green();
    cout << "End of Prime Numbers" << endl;
    cout << endl;
    color.reset();
}

void VariationManager::executeVariant2()
{
    std::atomic<bool> dummyFlag = true; // Unused, but needed for function signature
    unsigned long int range = this->targetNumber / this->numThreads;
    unsigned long int start = 0;
    unsigned long int end = range;

    this->displayStartTime();   // Display start time
    cout << endl;

    for (unsigned int t = 0; t < this->numThreads; t++) {
        if (t == this->numThreads - 1) {
            end = this->targetNumber;
        }

        this->threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, start, end, t, std::ref(this->printer), std::ref(dummyFlag)));

        start = end + 1;
        end = start + range - 1;
    }

    this->joinAllThreads();

    color.green();
    cout << "All Prime Numbers: " << endl;
    color.reset();
    
    this->printer->printPrimes(0, 0);

    color.green();
    cout << "End of Prime Numbers" << endl;
    cout << endl;
    color.reset();

    this->displayEndTime();     // Display end time
}

void VariationManager::executeVariant3()
{
    std::atomic<bool> isPrimeFlag = true;

    color.green();
    cout << "All Prime Numbers: " << endl;
    color.reset();

    for (unsigned long int i = 2; i <= this->targetNumber; i++) {

        isPrimeFlag = true;

        if (i == 2) {
            this->printer->logPrime(i, 0);
            continue;
        }

        for (unsigned int t = 0; t < this->numThreads; t++) {
            threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, i, i, t, std::ref(this->printer), std::ref(isPrimeFlag)));
        }

        this->joinAllThreads();
    }

    this->joinAllThreads();

    color.green();
    cout << "End of Prime Numbers" << endl;
    cout << endl;
    color.reset();
}

void VariationManager::executeVariant4()
{
    std::atomic<bool> isPrimeFlag = true;

    this->displayStartTime();   // Display start time

    for (unsigned long int i = 2; i <= this->targetNumber; i++) {
        
        isPrimeFlag = true;

        if (i == 2) {
            this->printer->logPrime(i, 0);
            continue;
        }

        for (unsigned int t = 0; t < this->numThreads; t++) {
            threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, i, i, t, std::ref(this->printer), std::ref(isPrimeFlag)));
        }

        this->joinAllThreads();
    }

    this->joinAllThreads();

    color.green();
    cout << "\nAll primes: ";
    this->printer->printPrimes(0, 0);
    cout << endl;
    color.reset();

    this->displayEndTime();     // Display end time
}

void VariationManager::joinAllThreads()
{
    for (auto& thread : this->threads) {
        if (thread.second.joinable()) {
            thread.second.join();
        }
    }
}

void VariationManager::displayStartTime()
{
    color.blue();
    cout << "Start Time: " << GlobalConfig::getInstance()->getTimestamp() << endl;
    color.reset();
}

void VariationManager::displayEndTime()
{
    color.blue();
    cout << "End Time: " << GlobalConfig::getInstance()->getTimestamp() << "\n" << endl;
    color.reset();
}