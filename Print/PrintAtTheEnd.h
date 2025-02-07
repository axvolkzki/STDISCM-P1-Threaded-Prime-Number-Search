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
    void logPrime(unsigned long int prime, unsigned int threadId) override;

    void printPrimes(unsigned long int prime, unsigned int threadId) override;

private:
    std::mutex printMutex;
    std::vector<unsigned long int> allPrimes;
};