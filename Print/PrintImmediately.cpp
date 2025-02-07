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
    cout << GlobalConfig::getInstance()->getTimestamp() << " [Thread " << threadId << "] Prime Found: " << prime << endl;
    this_thread::sleep_for(milliseconds(100));  // Delay to simulate processing time
}
