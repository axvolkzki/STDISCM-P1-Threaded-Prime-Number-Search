#include "PrintImmediately.h"

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace chrono;



void PrintImmediately::logPrime(int prime, int threadId) {
    printPrimes(prime, threadId);
}

void PrintImmediately::printPrimes(int prime, int threadId)
{
    lock_guard<mutex> lock(printMutex);
    cout << "[Thread " << threadId << "] Prime found: " << prime 
         << " at " << GlobalConfig::getInstance()->getTimestamp() << endl;

    // delay to simulate processing time
    this_thread::sleep_for(milliseconds(100));
}
