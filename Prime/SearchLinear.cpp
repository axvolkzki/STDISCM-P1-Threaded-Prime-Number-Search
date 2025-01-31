#include "SearchLinear.h"

mutex SearchLinear::outputMutex;

void SearchLinear::searchPrimes(int targetNumber)
{
    IntVector primes;
    int num = 2;

    while (num <= targetNumber) {
        if (this->isPrime(num)) {
            if (this->printImmediately) {
                lock_guard<mutex> lock(outputMutex);
                cout << num << endl;
            }
            else {
                primes.push_back(num);
            }
        }

        num++;
    }

    if (!this->printImmediately) {
        lock_guard<mutex> lock(outputMutex);
        for (int prime : primes) {
            cout << prime << endl;
        }
    }
}