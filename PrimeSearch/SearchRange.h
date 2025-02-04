#pragma once
#include <mutex>
#include <atomic>

#include "../TypeDefRepo.h"
#include "ASearch.h"

class SearchRange : public ASearch
{
public:
    SearchRange() = default;
    
    void searchPrimes(int start, int end, int threadId, APrint* printer, char variant, std::atomic<bool>& isPrimeFlag) override;
private:
    bool isPrime(int number);
};