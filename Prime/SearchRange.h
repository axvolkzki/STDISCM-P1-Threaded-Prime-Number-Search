#pragma once
#include <mutex>

#include "../TypeDefRepo.h"
#include "ASearch.h"

class SearchRange : public ASearch
{
public:
    SearchRange() = default;
    void searchPrimes(int start, int end, int threadId, char printType, APrint* printer) override;

private:
    bool isPrime(int num);
    static std::mutex outputMutex;
};