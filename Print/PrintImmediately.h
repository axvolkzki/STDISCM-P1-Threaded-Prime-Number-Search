#pragma once

#include "../TypeDefRepo.h"
#include "../Config/GlobalConfig.h"
#include "APrint.h"

class PrintImmediately : public APrint
{
public:
    PrintImmediately() = default;

    void logPrime(unsigned long int prime, unsigned int threadId) override;
    void printPrimes(unsigned long int prime, unsigned int threadId) override;

private:
    std::mutex printMutex;
};