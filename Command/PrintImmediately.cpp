#include "PrintImmediately.h"

using namespace chrono;

PrintImmediately* PrintImmediately::getInstance() {
    static PrintImmediately instance;
    return &instance;
}

void PrintImmediately::logPrime(int prime, int threadId) {
    lock_guard<mutex> lock(printMutex);
    auto now = system_clock::now();
    time_t now_c = system_clock::to_time_t(now);
    cout << "[Thread " << threadId << "] Prime found: " << prime 
         << " at " << ctime(&now_c);

    // delay to simulate processing time
    this_thread::sleep_for(milliseconds(100));
}

void PrintImmediately::printPrimes()
{
    // Do nothing
}
