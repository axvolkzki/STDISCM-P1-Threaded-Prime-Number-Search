#pragma once
#include <mutex>

#include "../TypeDefRepo.h"
#include "ASearch.h"

class SearchRange : public ASearch
{
public:
    SearchRange(bool printImmediately) : printImmediately(printImmediately) {}

    void searchPrimes(int targetNumber) override;

private:
    bool printImmediately;
    static mutex outputMutex;
};