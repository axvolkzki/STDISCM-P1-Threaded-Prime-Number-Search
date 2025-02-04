#include "VariationManager.h"
#include <iostream>
#include <atomic>
#include <memory>

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
    std::vector<std::shared_ptr<std::atomic<bool>>> threadStates;

    // initialize thread states
    for (int i = 0; i < this->numThreads; i++) {
        threadStates.push_back(std::make_shared<std::atomic<bool>>(false));
    }

    for (int t = 0; t < this->numThreads; t++) {
        if (t == this->numThreads - 1) {
            end = this->targetNumber;
        }

        this->threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, start, end, t, std::ref(this->printer), threadStates[t], 'R'));

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
    std::vector<std::shared_ptr<std::atomic<bool>>> threadStates;

    // initialize thread states
    for (int i = 0; i < this->numThreads; i++) {
        threadStates.push_back(std::make_shared<std::atomic<bool>>(false));
    }


    for (int t = 0; t < this->numThreads; t++) {
        if (t == this->numThreads - 1) {
            end = this->targetNumber;
        }

        this->threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, start, end, t, std::ref(this->printer), threadStates[t], 'R'));

        start = end + 1;
        end = start + range - 1;
    }

    this->joinAllThreads();

    this->printer->printPrimes(0, 0, 'R');
}

void VariationManager::executeVariant3()
{
    int start = 1;
    int threadID = 0;
    int primeIndex = 0;
    int divisor = 0;
    std::vector<int> primes = { 2, 3 };
    std::vector<std::shared_ptr<std::atomic<bool>>> threadStates;

    // initialize thread states
    for (int i = 0; i < this->numThreads; i++) {
        threadStates.push_back(std::make_shared<std::atomic<bool>>(false));
    }


    for (int i = start; i <= this->targetNumber; i++) {

        lock_guard<mutex> lock(this->variationMutex);
        color.red();
        cout << "Checking: " << i << endl;
        color.reset();

        // do {
        //     divisor = primes[primeIndex];


        //     if (threadID == this->numThreads) {
        //         threadID = 0;
        //     }

        //     // check if thread is available
        //     if (threadStates[threadID]->load() == false) {
        //         this->threads.emplace_back(threadID, std::thread(&ASearch::searchPrimes, searchMethod, i, divisor, threadID, std::ref(this->printer), threadStates[threadID], 'L'));
        //         threadID++;
        //         break;
        //     }
            
        //     primeIndex++;
        // } while (primeIndex != primes.size() - 1);

        // if (primeIndex == primes.size() - 1) {
        //     primes.push_back(i);
        //     primeIndex = 0;
        // }

        for (int t = 0; t < this->numThreads; t++) {
            threads.emplace_back(t, std::thread(&ASearch::searchPrimes, searchMethod, i, i, this->numThreads, std::ref(this->printer), threadStates[t], 'L'));
        }

        lock_guard<mutex> lock2(this->variationMutex);
        color.red();
        cout << "Done Checking: " << i << endl;
        color.reset();

        this->joinAllThreads();
    }

    this->joinAllThreads();
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
