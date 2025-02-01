#include "SearchRange.h"

mutex SearchRange::outputMutex;

void SearchRange::searchPrimes(int start, int end, int threadId, char printType, APrint* printer)
{
    // cout << "[Thread " << threadId << "] Searching for prime numbers from " << start << " to " << end << endl;

    lock_guard<mutex> lock(outputMutex);
    for (int i = start; i <= end; i++) {
        if (this->isPrime(i)) {

            // if (printType == 'A') {
            //     printer->logPrime(i, threadId);
            // }
            // else {
            //     cout << "Printing at the end" << endl;
            //     printer->logPrime(i, threadId);
            // }
            printer->logPrime(i, threadId);
        }
    }

    // cout << "[Thread " << threadId << "] Finished searching for prime numbers from " << start << " to " << end << endl;
}

bool SearchRange::isPrime(int num)
{
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}
