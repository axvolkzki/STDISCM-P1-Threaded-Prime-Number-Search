#pragma once
#include <mutex>
#include <atomic>

#include "../TypeDefRepo.h"
#include "ASearch.h"

class SearchRange : public ASearch
{
public:
    SearchRange() = default;
    
    void searchPrimes(int start, int end, int threadId, APrint* printer, std::shared_ptr<std::atomic<bool>> threadState, char variant) override;
private:
    bool isPrime(int number);
};