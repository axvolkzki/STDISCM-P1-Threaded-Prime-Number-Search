#pragma once
#include <iostream>
#include <mutex>
#include <atomic>

#include "../TypeDefRepo.h"
#include "../Print/APrint.h"

class ASearch
{
public:
    virtual ~ASearch() = default;
    virtual void searchPrimes(unsigned long int start, unsigned long int end, unsigned int threadId, APrint* printer, std::atomic<bool>& isPrimeFlag) = 0;

protected:
    static std::mutex searchMutex;
};