#pragma once
#include <mutex>

#include "../TypeDefRepo.h"
#include "ASearch.h"

class SearchRange : public ASearch
{
public:
    SearchRange() = default;
    
    void searchPrimes(int start, int end, int threadId, APrint* printer) override;
    bool isPrime(int number) override;
};