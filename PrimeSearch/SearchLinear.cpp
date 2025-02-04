#include "SearchLinear.h"

#include <cmath>

#include "../Config/GlobalConfig.h"

void SearchLinear::searchPrimes(int start, int end, int threadID, APrint *printer, char variant)
{
    int numThreads = GlobalConfig::getInstance()->getNumberOfThreads();

    for (int divisor = threadID + 2; divisor < start; divisor += numThreads) {
        {
            lock_guard<mutex> lock(this->searchMutex);
            printer->logPrime(divisor, threadID, variant);
        }

        if (start % divisor == 0) {
            return;
        }
    }

}

bool SearchLinear::isPrime(int number)
{
    if (number <= 1) return false;          // 1 and below are not primes
    if (number == 2) return true;           // 2 is the only even prime
    if (number % 2 == 0) return false;      // Other even numbers are not primes

    // Check divisibility up to the square root of the number
    for (int i = 3; i <= std::sqrt(number); i += 2) {
        if (number % i == 0) return false;
    }

    return true;
}