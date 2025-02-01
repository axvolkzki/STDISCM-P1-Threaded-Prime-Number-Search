#pragma once
#include <vector>

#include "../TypeDefRepo.h"

class APrint
{
public:
    virtual ~APrint() = default;
    virtual void logPrime(int prime, int threadId) = 0;
    virtual void printPrimes() = 0;

};

