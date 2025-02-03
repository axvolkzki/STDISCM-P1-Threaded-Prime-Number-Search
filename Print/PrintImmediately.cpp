#include "PrintImmediately.h"

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace chrono;



void PrintImmediately::logPrime(int prime, int threadId, char variant) {
    printPrimes(prime, threadId, variant);
}

void PrintImmediately::printPrimes(int prime, int threadId, char variant)
{
    lock_guard<mutex> lock(printMutex);
    switch (variant) {
        case 'R':
            cout << GlobalConfig::getInstance()->getTimestamp() << " [Thread " << threadId << "] Prime Found: " << prime << endl;
            break;
        case 'L':
            cout << GlobalConfig::getInstance()->getTimestamp() << " [Thread " << threadId << "] Checking divisibility for: " << prime << endl;
            break;
    };

    // delay to simulate processing time
    this_thread::sleep_for(milliseconds(100));
}
