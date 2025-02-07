#pragma once
#include <iostream>
#include <mutex>

#include "../TypeDefRepo.h"

class APrint
{
public:
    virtual ~APrint() = default;
    virtual void logPrime(unsigned long int prime, unsigned int threadId) = 0;
    virtual void printPrimes(unsigned long int prime, unsigned int threadId) = 0;
};

