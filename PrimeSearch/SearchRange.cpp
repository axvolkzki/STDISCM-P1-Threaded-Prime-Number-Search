#include "SearchRange.h"

#include <cmath>  // sqrt

void SearchRange::searchPrimes(int start, int end, int threadId, APrint* printer, std::shared_ptr<std::atomic<bool>> threadState, char variant)
{
    // change the state of the thread to true
    threadState->store(true);

    for (int i = start; i <= end; i++) {
        if (this->isPrime(i)) {
            printer->logPrime(i, threadId, variant);
        }
    }

    threadState->store(false);
}

// https://www.youtube.com/watch?v=d5cLIiTSoTA
bool SearchRange::isPrime(int number)
{
    if (number <= 1) {
        return false;
    }

    // Checks up to the square root of the number
    // for (int i = 2; i * i <= number; i++) {
    //     if (number % i == 0) {
    //         return false;
    //     }
    // }

    // return true;

    // Optimized version
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
