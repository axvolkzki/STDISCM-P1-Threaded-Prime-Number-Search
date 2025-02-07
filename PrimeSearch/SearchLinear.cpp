#include "SearchLinear.h"

#include <cmath>

#include "../Config/GlobalConfig.h"

void SearchLinear::searchPrimes(int start, int end, int threadID, APrint *printer, std::atomic<bool> &isPrimeFlag)
{
    int numThreads = GlobalConfig::getInstance()->getNumberOfThreads();

    for (int divisor = threadID + 2; divisor < start; divisor += numThreads) {
        // if (!isPrimeFlag) {
        //     return; // stop immediately the thread if the number is not a prime number
        // }

        // {
        //     lock_guard<mutex> lock(this->searchMutex);
        //     printer->logPrime(divisor, threadID);
        // }

        if (!this->isPrime(start, divisor)) {       // Check if the number is prime, if not, set the flag to false
            isPrimeFlag = false;
            return;
        }
    }

}

bool SearchLinear::isPrime(int dividend, int divisor)
{
    if (dividend % divisor == 0) {
        return false;
    }

    return true;
}