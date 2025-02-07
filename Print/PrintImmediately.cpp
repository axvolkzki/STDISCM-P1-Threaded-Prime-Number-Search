#include "PrintImmediately.h"

#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>

using namespace chrono;


void PrintImmediately::logPrime(unsigned long int prime, unsigned int threadId) {
    printPrimes(prime, threadId);
}

void PrintImmediately::printPrimes(unsigned long int prime, unsigned int threadId)
{
    lock_guard<mutex> lock(printMutex);
    cout << GlobalConfig::getInstance()->getTimestamp() << "\t" << "[Thread " << threadId << "]" << "\t" << "Prime Found: " << prime << endl;
    this_thread::sleep_for(milliseconds(100));  // Delay to simulate processing time
}
