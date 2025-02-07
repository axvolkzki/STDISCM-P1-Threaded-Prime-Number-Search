#pragma once
#include <iostream>
#include <queue>
#include <thread>
#include <atomic>

#include "../TypeDefRepo.h"
#include "../Helper/Colors.h"
#include "ASearch.h"
#include "../Print/APrint.h"


class SearchLinear : public ASearch
{
public:
    SearchLinear() = default;
    void searchPrimes(unsigned long int start, unsigned long int end, unsigned int threadID, APrint* printer, std::atomic<bool>& isPrimeFlag) override;
    
private:
    Colors colors;
    bool isPrime(unsigned int dividend, unsigned int divisor);
};