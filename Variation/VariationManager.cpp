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
    int range = this->targetNumber / this->numThreads;
    int start = 0;
    int end = range;

    color.green();
    cout << "All Prime Numbers: " << endl;
    color.reset();

    for (int t = 0; t < this->numThreads; t++) {
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
    int range = this->targetNumber / this->numThreads;
    int start = 0;
    int end = range;

    this->displayStartTime();   // Display start time
    cout << endl;

    for (int t = 0; t < this->numThreads; t++) {
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
    std::vector<int> allPrimes;
    std::atomic<bool> isPrimeFlag = true;

    for (int i = 1; i <= this->targetNumber; i++) {

        // {
        //     lock_guard<mutex> lock(this->variationMutex);
        //     color.yellow();
        //     cout << "\nChecking: " << i << endl;
        //     color.reset();
        // }

        for (int t = 0; t < this->numThreads; t++) {
            threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, i, i, t, std::ref(this->printer), std::ref(isPrimeFlag)));

            // if the 
        }

        this->joinAllThreads();

        // if (!isPrimeFlag || i == 1) {
        //     color.red();
        //     cout << "Result: " << i << " is not a prime number" << endl;
        //     color.reset();
        // }

        // if (isPrimeFlag && i != 1) {
        //     color.green();
        //     cout << "Result: " << i << " is a prime number" << endl;
        //     color.reset();

        //     // Add
        //     allPrimes.push_back(i);
        // }

        // if (isPrimeFlag && i != 1) {
        //     // Add
        //     // allPrimes.push_back(i);
        //     this->printer->logPrime(i, 0);
        // }

        // reset the flag
        isPrimeFlag = true;
    }

    this->joinAllThreads();

    // color.green();
    // cout << "\nAll primes: ";
    // for (auto prime : allPrimes) {
    //     cout << prime << " ";
    // }
    // cout << endl;
    // color.reset();
}

void VariationManager::executeVariant4()
{
    std::vector<int> allPrimes;
    std::atomic<bool> isPrimeFlag = true;

    this->displayStartTime();   // Display start time

    for (int i = 1; i <= this->targetNumber; i++) {

        for (int t = 0; t < this->numThreads; t++) {
            threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, i, i, t, std::ref(this->printer), std::ref(isPrimeFlag)));
        }

        this->joinAllThreads();

        if (isPrimeFlag && i != 1) {
            this->printer->logPrime(i, 0);
        }

        // reset the flag
        isPrimeFlag = true;

        // this->printer->printPrimes(0, 0);
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