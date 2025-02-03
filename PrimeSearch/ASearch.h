#pragma once
#include <iostream>
#include <mutex>

#include "../TypeDefRepo.h"
#include "../Print/APrint.h"

class ASearch
{
public:
    virtual ~ASearch() = default;
    virtual void searchPrimes(int start, int end, int threadId, APrint* printer) = 0;

protected:
    static std::mutex searchMutex;

    bool isPrime(int number);
};