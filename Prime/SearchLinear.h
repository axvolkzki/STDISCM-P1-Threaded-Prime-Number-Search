#pragma once
#include <iostream>

#include "../TypeDefRepo.h"
#include "ASearch.h"

class SearchLinear : public ASearch
{
public:
    SearchLinear(bool printImmediately) : printImmediately(printImmediately) {}

    void searchPrimes(int targetNumber) override;

private:
    bool printImmediately;
    static mutex outputMutex;
};