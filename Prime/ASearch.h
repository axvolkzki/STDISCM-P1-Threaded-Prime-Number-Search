#pragma once
#include <iostream>
#include <mutex>

#include "../TypeDefRepo.h"
#include "../Command/APrint.h"

class ASearch
{
public:
    virtual void searchPrimes(int start, int end, int threadId, char printerType, APrint* printer) = 0;
    virtual ~ASearch() = default;

protected:
    static std::mutex outputMutex;
};