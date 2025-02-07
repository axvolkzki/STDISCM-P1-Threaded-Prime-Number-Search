#include "SearchLinear.h"

#include <cmath>

#include "../Config/GlobalConfig.h"

void SearchLinear::searchPrimes(unsigned long int start, unsigned long int end, unsigned int threadID, APrint *printer, std::atomic<bool> &isPrimeFlag)
{
    unsigned int numThreads = GlobalConfig::getInstance()->getNumberOfThreads();
    bool isLastThread = false; 

    for (unsigned int divisor = threadID + 2; divisor < start; divisor += numThreads) {
        if (!isPrimeFlag) {
            return; // stop immediately the thread if the number is not a prime number
        }

        if (!this->isPrime(start, divisor)) {       // Check if the number is prime, if not, set the flag to false
            isPrimeFlag = false;
            return;
        }

        if (divisor == start - 1) {
            isLastThread = true;
        }
    }

    if (isPrimeFlag && isLastThread) {
        printer->logPrime(start, threadID);
    }

}

bool SearchLinear::isPrime(unsigned int dividend, unsigned int divisor)
{   
    if (dividend % divisor == 0) {
        return false;
    }

    return true;
}