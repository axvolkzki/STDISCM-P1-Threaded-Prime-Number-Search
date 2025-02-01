#pragma once
#include <iostream>
#include <chrono>
#include <mutex>

#include "../TypeDefRepo.h"
#include "../Config/GlobalConfig.h"
#include "APrint.h"

class PrintAtTheEnd : public APrint
{
public:
    static PrintAtTheEnd* getInstance();
    void logPrime(int prime, int threadId) override;

    void printPrimes() override;

private:
    PrintAtTheEnd() = default;
    std::vector<std::tuple<int, int, std::chrono::time_point<std::chrono::system_clock>>> primes;

    std::mutex printMutex;
};