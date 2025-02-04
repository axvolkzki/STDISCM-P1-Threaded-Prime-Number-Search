#include "SearchLinear.h"

#include <cmath>

#include "../Config/GlobalConfig.h"

void SearchLinear::searchPrimes(int start, int end, int threadID, APrint *printer, std::shared_ptr<std::atomic<bool>> threadState, char variant)
{
    cout << "Debug: SearchLinear::searchPrimes" << endl;

    
    // change the state of the thread to true
    threadState->store(true);
    int numThreads = GlobalConfig::getInstance()->getNumberOfThreads();

    for (int i = start; i <= end; i += numThreads) {
        int currentNumber = i;

        lock_guard<mutex> lock(this->searchMutex);
        cout << "Current number: " << currentNumber << endl;

        for (int divisor = 2; divisor <= std::sqrt(currentNumber); ++divisor) {
            // if (currentNumber % divisor == 0) {
            //     break;
            //     printer->logPrime(currentNumber, threadID, variant);
            // }
            // // if (divisor == std::sqrt(currentNumber)) {
            // //     lock_guard<mutex> lock(this->printMutex);
            // //     printer->printPrimes(currentNumber, numThreads, variant);
            // // }

            printer->logPrime(currentNumber, threadID, variant);
        }

        if (isPrime(currentNumber) && currentNumber != 1) {
            lock_guard<mutex> lock(this->searchMutex);
            colors.red();
            cout << "Current number: " << currentNumber << " is prime" << endl;
            colors.reset();
        }

        cout << endl;
    }

    threadState->store(false);
}

bool SearchLinear::isPrime(int number)
{
    if (number <= 1) return false; // 1 and below are not primes
    if (number == 2) return true;  // 2 is the only even prime
    if (number % 2 == 0) return false; // Other even numbers are not primes

    // Check divisibility up to the square root of the number
    for (int i = 3; i <= std::sqrt(number); i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}