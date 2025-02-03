#include "SearchLinear.h"

void SearchLinear::searchPrimes(int start, int end, int threadID, APrint *printer, std::shared_ptr<std::atomic<bool>> threadState, char variant)
{
    // change the state of the thread to true
    threadState->store(true);

    if (this->isPrime(start, end)) {
        printer->logPrime(start, threadID, variant);
    }

    threadState->store(false);
}

bool SearchLinear::isPrime(int dividend, int divisor)
{
    bool result = true;

    if (dividend <= 1) {
        result = false;
    }

    if (dividend % divisor == 0) {
        result = false;
    } 

    return result;
}