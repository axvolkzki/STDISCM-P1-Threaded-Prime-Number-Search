#pragma once
#include <iostream>
#include <chrono>
#include <mutex>
#include <vector>
#include <tuple>

#include "../TypeDefRepo.h"
#include "../Config/GlobalConfig.h"
#include "APrint.h"

class PrintAtTheEnd : public APrint
{
public:
    PrintAtTheEnd() = default;
    void logPrime(int prime, int threadId, char variant) override;

    void printPrimes(int prime, int threadId, char variant) override;

private:
    std::mutex printMutex;
    std::vector<std::tuple<int, int, std::chrono::time_point<std::chrono::system_clock>>> primes;
};