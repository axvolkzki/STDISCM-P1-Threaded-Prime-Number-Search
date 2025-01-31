#include "SearchRange.h"

mutex SearchRange::outputMutex;

void SearchRange::searchPrimes(int targetNumber)
{
    IntVector primes;

    for (int i = 2; i <= targetNumber; i++) {
        if (this->isPrime(i)) {
            if (this->printImmediately) {
                lock_guard<mutex> lock(outputMutex);
                cout << i << endl;
            }
            else {
                primes.push_back(i);
            }
        }
    }

    if (!this->printImmediately) {
        lock_guard<mutex> lock(outputMutex);
        for (int prime : primes) {
            cout << prime << endl;
        }
    }
}