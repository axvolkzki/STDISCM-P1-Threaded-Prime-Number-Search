#pragma once

#include "../TypeDefRepo.h"
#include "../Config/GlobalConfig.h"
#include "APrint.h"

class PrintImmediately : public APrint
{
public:
    PrintImmediately() = default;

    void logPrime(int prime, int threadId) override;
    void printPrimes(int prime, int threadId) override;

private:
    std::mutex printMutex;
};