#include "SearchLinear.h"

#include <atomic>
#include <cmath>

void SearchLinear::searchPrimes(int start, int end, int numThreads, char printType, APrint *printer)
{
    vector<pair<atomic<bool>, thread>> threads(numThreads);
    int threadId = 0;
    vector<int> primeNumbers = {2, 3};
    
    this->initializeThreads(threads);

    // Iterate through the range of numbers
    for (int n = start; n < end; n++) {
        this->colors.red();
        cout << "\nCurrent number: " << n << endl;
        
        this->colors.reset();
        threadId = this->availableThread(threads);
        int divisor = 0;

        do {
            if (threadId != -1 && divisor < primeNumbers.size()) {
                threads[threadId].first = false;
                threads[threadId].second = thread(&SearchLinear::worker, this, n, primeNumbers[divisor], threadId, ref(threads), printType, printer, ref(primeNumbers));

                threadId = this->availableThread(threads);
                divisor++;
            }
        } while (threadId != -1 && divisor < primeNumbers.size());
    }
    
    // Wait for all threads to finish
    for (int t = 0; t < numThreads; t++)
    {
        if (threads[t].second.joinable())
        {
            threads[t].second.join();
        }
    }

    if (printType == 'B')
    {
        cout << "[searchPrimes in SearchLinear] All threads are done. Printing prime numbers..." << endl;
        printer->printPrimes();
    }
}

bool SearchLinear::isPrime(int dividend, int divisor)
{
    if (dividend <= 1)
    {
        return false;
    }

    return dividend % divisor != 0; // If the remainder is not 0, then it is a prime number
}

void SearchLinear::initializeThreads(vector<pair<atomic<bool>, thread>> &threads)
{
    // Initialize threads as ready to start (true)
    for (int i = 0; i < threads.size(); i++)
    {
        threads[i].first = true;
    }
}

int SearchLinear::availableThread(vector<pair<atomic<bool>, thread>> &threads)
{
    // everytime a thread is available, return the index of the thread
    for (int i = 0; i < threads.size(); i++)
    {
        if (threads[i].first)
        {
            return i;
        }
    }

    return -1;
}

void SearchLinear::worker(int n, int divisor, int t, vector<pair<atomic<bool>, thread>> &threads, char printType, APrint *printer, vector<int> &primes)
{
    lock_guard<mutex> lock(outputMutex);
    cout << "[Thread " << t << "] checking divisor: " << divisor << endl;

    if (this->isPrime(n, divisor))
    {
        cout << "[Thread " << t << "] " << n << " is a prime number" << endl;
        primes.push_back(n);
        printer->logPrime(n, t);
    }

    threads[t].first = true;
}