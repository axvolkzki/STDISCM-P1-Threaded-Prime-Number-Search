#include "PrintAtTheEnd.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace chrono;

void PrintAtTheEnd::logPrime(int prime, int threadId) {
    lock_guard<mutex> lock(printMutex);
    allPrimes.push_back(prime);

    this_thread::sleep_for(milliseconds(100));  // Delay to simulate processing time
}

void PrintAtTheEnd::printPrimes(int prime, int threadId)
{
    lock_guard<mutex> lock(printMutex);
    for (auto prime : allPrimes) {
        cout << prime << " ";
    }
    cout << endl;
}
