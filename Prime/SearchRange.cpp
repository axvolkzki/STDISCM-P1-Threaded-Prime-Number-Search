#include "SearchRange.h"

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

bool SearchRange::isPrime(int number)
{
    if (number <= 1) {
        return false;
    }

    // Checks up to the square root of the number
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
