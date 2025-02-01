#include "PrintAtTheEnd.h"

using namespace chrono;

PrintAtTheEnd* PrintAtTheEnd::getInstance() {
    static PrintAtTheEnd instance;
    return &instance;
}

void PrintAtTheEnd::logPrime(int prime, int threadId) {
    lock_guard<mutex> lock(printMutex);
    primes.push_back(std::make_tuple(threadId, prime, system_clock::now()));

    // delay to simulate processing time
    this_thread::sleep_for(milliseconds(100));
}

void PrintAtTheEnd::printPrimes()
{
    lock_guard<mutex> lock(printMutex);
    for (auto& prime : primes) {
        // auto now = system_clock::now();
        // time_t now_c = system_clock::to_time_t(now);
        // cout << "[Thread " << std::get<0>(prime) << "] Prime found: " << std::get<1>(prime)
        //     << " at " << ctime(&now_c);

        cout << "[Thread " << std::get<0>(prime) << "] Prime found: " << std::get<1>(prime)
         << " at " << GlobalConfig::getInstance()->getTimestamp() << endl;
    }
}
