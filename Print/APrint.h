#pragma once
#include <iostream>
#include <mutex>

#include "../TypeDefRepo.h"

class APrint
{
public:
    virtual ~APrint() = default;
    virtual void logPrime(int prime, int threadId, char variant) = 0;
    virtual void printPrimes(int prime, int threadId, char variant) = 0;
};

