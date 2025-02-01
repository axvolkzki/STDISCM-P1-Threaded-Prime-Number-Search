#pragma once
#include <iostream>
#include <atomic>

#include "../TypeDefRepo.h"
#include "ASearch.h"
#include "../Helper/Colors.h"

class SearchLinear : public ASearch
{
public:
    SearchLinear() = default;
    void searchPrimes(int start, int end, int numThreads, char printType, APrint* printer) override;

private:
    Colors colors;

    bool isPrime(int dividend, int divisor);
    void initializeThreads(vector<pair<atomic<bool>, thread>>& threads);
    int availableThread(vector<pair<atomic<bool>, thread>>& threads);
    void worker(int n, int divisor, int t, vector<pair<atomic<bool>, thread>>& threads, char printType, APrint* printer, vector<int>& primes);

};