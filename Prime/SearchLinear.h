#pragma once
#include <iostream>

#include "../TypeDefRepo.h"
#include "ASearch.h"

class SearchLinear : public ASearch
{
public:
    void searchPrimes(int start, int end, int threadId, char printType, APrint* printer) override;

private:
    bool isPrime(int num);
    static std::mutex outputMutex;
};