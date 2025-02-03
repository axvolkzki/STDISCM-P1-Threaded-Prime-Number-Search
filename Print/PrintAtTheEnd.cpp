#include "PrintAtTheEnd.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace chrono;

void PrintAtTheEnd::logPrime(int prime, int threadId) {
    lock_guard<mutex> lock(printMutex);
    primes.push_back(std::make_tuple(threadId, prime, system_clock::now()));

    // delay to simulate processing time
    this_thread::sleep_for(milliseconds(100));
}

void PrintAtTheEnd::printPrimes(int prime, int threadId)
{
    lock_guard<mutex> lock(printMutex);
    for (auto& prime : primes) {
        cout << "[Thread " << std::get<0>(prime) << "] Prime found: " << std::get<1>(prime)
         << " at " << GlobalConfig::getInstance()->getTimestamp() << endl;
    }
}
