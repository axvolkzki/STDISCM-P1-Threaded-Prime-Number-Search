#include "SearchRange.h"

#include <cmath>  // sqrt

void SearchRange::searchPrimes(int start, int end, int threadId, APrint* printer, std::atomic<bool>& isPrimeFlag)
{
    for (int i = start; i <= end; i++) {
        if (this->isPrime(i)) {
            printer->logPrime(i, threadId);
        }
    }
}

// https://www.youtube.com/watch?v=d5cLIiTSoTA
bool SearchRange::isPrime(int number)
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
