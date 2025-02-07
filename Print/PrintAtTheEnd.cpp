#include "PrintAtTheEnd.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace chrono;

// void PrintAtTheEnd::logPrime(int prime, int threadId, char variant) {
//     lock_guard<mutex> lock(printMutex);
//     primes.push_back(std::make_tuple(threadId, prime, system_clock::now()));

//     // delay to simulate processing time
//     this_thread::sleep_for(milliseconds(100));
// }

// void PrintAtTheEnd::printPrimes(int prime, int threadId, char variant)
// {
//     lock_guard<mutex> lock(printMutex);
//     for (auto& prime : primes) {
//         switch (variant) {
//             case 'R':
//                 cout << GlobalConfig::getInstance()->getTimestamp() << " [Thread " << std::get<0>(prime) << "] Prime Found: " << std::get<1>(prime) << endl;
//                 break;
//             case 'L':
//                 cout << GlobalConfig::getInstance()->getTimestamp() << " [Thread " << std::get<0>(prime) << "] Checking divisibility for: " << std::get<1>(prime) << endl;
//                 break;
//         };
//     }
// }

void PrintAtTheEnd::logPrime(int prime, int threadId) {
    lock_guard<mutex> lock(printMutex);
    allPrimes.push_back(prime);

    // delay to simulate processing time
    this_thread::sleep_for(milliseconds(100));
}

void PrintAtTheEnd::printPrimes(int prime, int threadId)
{
    lock_guard<mutex> lock(printMutex);
    for (auto prime : allPrimes) {
        cout << prime << " ";
    }
    cout << endl;
}
