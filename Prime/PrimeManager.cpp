#include "PrimeManager.h"

void PrimeManager::executeSearch(int variant)
{
    if (variant == '1' || variant == '2') {
        int range = this->targetNumber / this->numThreads;
        int start = 0;
        int end = range;

        cout << "[executeSearch in PrimeManager] Searching for prime numbers from 1 to " << this->targetNumber << " using " << this->numThreads << " threads..." << endl;
        cout << "Start time: " << GlobalConfig::getInstance()->getTimestamp() << endl;

        for (int i = 0; i < this->numThreads; i++) {
            if (i == this->numThreads - 1) {
                end = this->targetNumber;   
            }

            this->threads.push_back(std::thread(&PrimeManager::searchByRange, this, start, end, i, this->printType));
            start = end + 1;
            end = start + range - 1;
        }

        for (auto& thread : this->threads) {
            thread.join();
        }

        if (this->printType == 'B') {
            cout << "[executeSearch in PrimeManager] All threads are done. Printing prime numbers..." << endl;
            this->printer->printPrimes();
        }

        cout << "End time: " << GlobalConfig::getInstance()->getTimestamp() << endl;

    } else if (variant == '3' || variant == '4') {
        cout << "[executeSearch in PrimeManager] Searching for prime numbers from 1 to " << this->targetNumber << " using " << this->numThreads << " threads..." << endl;
    }
}

void PrimeManager::searchByRange(int start, int end, int threadId, char printType)
{
    this->searchMethod->searchPrimes(start, end, threadId, printType, this->printer);
}
