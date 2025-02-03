#pragma once
#include <iostream>
#include <atomic>
#include <queue>
#include <thread>

#include "../TypeDefRepo.h"
#include "../Helper/Colors.h"
#include "ASearch.h"
#include "../Print/APrint.h"


class SearchLinear : public ASearch
{
public:
    SearchLinear() = default;
    void searchPrimes(int start, int end, int numThreads, APrint* printer) override;
    bool isPrime(int number) override;

private:
    Colors colors;
};