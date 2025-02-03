#include "SearchLinear.h"

#include <atomic>
#include <cmath>

void SearchLinear::searchPrimes(int start, int end, int numThreads, APrint *printer)
{
    vector<pair<atomic<bool>, thread>> threads(numThreads);
    vector<int> numbersReadyQueue(end - start);
    vector<pair<vector<int>, thread>> threadsReadyQueue(numThreads);  


    // Initialize threads
    this->initializeThreads(threads);
    


    // try {
    //     vector<pair<atomic<bool>, thread>> threads(numThreads);
    //     int threadId = 0;
    //     vector<int> primeNumbers = {2, 3};
    //     int currentNumber;
        
    //     // Initialize threads
    //     this->initializeThreads(threads);

    //     // Iterate through the range of numbers
    //     for (int n = start; n < end; n++) {     // ReadyQueue for all the number to be checked
            
    //         this->colors.red();
    //         cout << "Inside the for loop for numbers" << endl;
    //         this->colors.reset();
            
    //         this->numbersReadyQueue.push(n);

    //         int currentThread = 0;
    //         int divisor = 0;
            

    //         try {
    //             while(threads[currentThread].first == true) { // Check if the thread is available
                    
    //                 // this->colors.red();
    //                 // cout << "Inside the while loop for threads" << endl;
    //                 // this->colors.reset();
                    
    //                 try {
    //                     if (currentThread < numThreads && divisor < primeNumbers.size()) {
    //                         threads[currentThread].first = false;
    //                         threads[currentThread].second = thread(&SearchLinear::worker, this, n, primeNumbers[divisor], currentThread, ref(threads), printType, printer, ref(primeNumbers));
    //                         currentThread++;
    //                         divisor++;
    //                     }
    //                 } catch (const exception& e) {
    //                     cout << e.what() << endl;
    //                 }
                    
    //             }
    //         } catch (const exception& e) {
    //             cout << e.what() << endl;
    //         }


    //         // wait for all threads to finish before changing the current number
    //         // for (int t = 0; t < numThreads; t++)
    //         // {
    //         //     if (threads[t].second.joinable())
    //         //     {
    //         //         threads[t].second.join();
    //         //     }
    //         // }









    //         // threadId = this->availableThread(threads);
    //         // int divisor = 0;

    //         // do {
    //         //     if (threadId != -1 && divisor < primeNumbers.size()) {
    //         //         threads[threadId].first = false;
    //         //         threads[threadId].second = thread(&SearchLinear::worker, this, n, primeNumbers[divisor], threadId, ref(threads), printType, printer, ref(primeNumbers));

    //         //         threadId = this->availableThread(threads);
    //         //         divisor++;
    //         //     }
    //         // } while (threadId != -1 && divisor < primeNumbers.size());
    //     }
        
    //     // Wait for all threads to finish
    //     for (int t = 0; t < numThreads; t++)
    //     {
    //         if (threads[t].second.joinable())
    //         {
    //             threads[t].second.join();
    //         }
    //     }

    //     if (printType == 'B')
    //     {
    //         cout << "[searchPrimes in SearchLinear] All threads are done. Printing prime numbers..." << endl;
    //         printer->printPrimes();
    //     }
    // } catch (const exception& e) {
    //     cout << e.what() << endl;
    // }
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
    lock_guard<mutex> lock(searchMutex);
    cout << "[Thread " << t << "] Checking divisor: " << divisor << " for ";
    this->colors.red();
    cout << "number " << n << endl;
    this->colors.reset();

    if (this->isPrime(n, divisor))
    {
        cout << "[Thread " << t << "] " << n << " is a prime number" << endl;
        primes.push_back(n);
        printer->logPrime(n, t);

        // this->initializeThreads(threads);
    }

    threads[t].first = true;
}