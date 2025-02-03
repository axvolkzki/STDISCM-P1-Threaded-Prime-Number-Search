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

private:
    Colors colors;

    // queue of prime numbers for each thread
    queue<int> numbersReadyQueue;

    bool isPrime(int dividend, int divisor);
    void initializeThreads(vector<pair<atomic<bool>, thread>>& threads);
    int availableThread(vector<pair<atomic<bool>, thread>>& threads);
    void worker(int n, int divisor, int t, vector<pair<atomic<bool>, thread>>& threads, char printType, APrint* printer, vector<int>& primes);

};