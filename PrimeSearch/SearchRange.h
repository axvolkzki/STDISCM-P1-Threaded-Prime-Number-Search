#pragma once
#include <mutex>
#include <atomic>

#include "../TypeDefRepo.h"
#include "ASearch.h"

class SearchRange : public ASearch
{
public:
    SearchRange() = default;
    
    void searchPrimes(unsigned long int start, unsigned long int end, unsigned int threadId, APrint* printer, std::atomic<bool>& isPrimeFlag) override;
private:
    bool isPrime(unsigned long int number);
};