#pragma once
#include <iostream>
#include <mutex>

#include "../TypeDefRepo.h"

class ASearch
{
public:
    virtual void searchPrimes(int targetNumber) = 0;
    virtual ~ASearch() = default;

protected:
    bool isPrime(int number);
};