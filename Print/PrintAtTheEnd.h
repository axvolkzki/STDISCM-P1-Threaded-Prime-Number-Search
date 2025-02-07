#pragma once
#include <iostream>
#include <chrono>
#include <mutex>
#include <vector>

#include "../TypeDefRepo.h"
#include "../Config/GlobalConfig.h"
#include "APrint.h"

class PrintAtTheEnd : public APrint
{
public:
    PrintAtTheEnd() = default;
    void logPrime(int prime, int threadId) override;

    void printPrimes(int prime, int threadId) override;

private:
    std::mutex printMutex;
    std::vector<int> allPrimes;
};