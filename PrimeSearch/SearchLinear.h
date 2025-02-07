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
    void searchPrimes(int start, int end, int threadID, APrint* printer, std::atomic<bool>& isPrimeFlag) override;
    
private:
    Colors colors;
    bool isPrime(int dividend, int divisor);
};