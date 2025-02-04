#include "SearchRange.h"

#include <cmath>  // sqrt

void SearchRange::searchPrimes(int start, int end, int threadId, APrint* printer, char variant)
{
    for (int i = start; i <= end; i++) {
        if (this->isPrime(i)) {
            printer->logPrime(i, threadId, variant);
        }
    }
}

// https://www.youtube.com/watch?v=d5cLIiTSoTA
bool SearchRange::isPrime(int number)
{
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
