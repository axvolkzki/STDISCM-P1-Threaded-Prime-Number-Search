#include "SearchRange.h"

#include <cmath>  // sqrt

void SearchRange::searchPrimes(int start, int end, int threadId, APrint* printer, char variant, std::atomic<bool>& isPrimeFlag)
{
    for (int i = start; i <= end; i++) {
        // if (!isPrimeFlag) {
        //     return; // stop immediately the thread if the number is not a prime number
        // }

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

    // if (number <= 1) return false;          // 1 and below are not primes
    // if (number == 2) return true;           // 2 is the only even prime
    // if (number % 2 == 0) return false;      // Other even numbers are not primes

    // // Check divisibility up to the square root of the number
    // for (int i = 3; i <= std::sqrt(number); i += 2) {
    //     if (number % i == 0) return false;
    // }

    // return true;

    return true;
}
