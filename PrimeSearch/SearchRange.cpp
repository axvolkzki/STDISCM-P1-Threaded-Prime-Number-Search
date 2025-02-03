#include "SearchRange.h"

void SearchRange::searchPrimes(int start, int end, int threadId, APrint* printer)
{
    for (int i = start; i <= end; i++) {
        if (this->isPrime(i)) {
            printer->logPrime(i, threadId);
        }
    }
}

// bool SearchRange::isPrime(int number)
// {
//     if (number <= 1) {
//         return false;
//     }

//     // Checks up to the square root of the number
//     for (int i = 2; i * i <= number; i++) {
//         if (number % i == 0) {
//             return false;
//         }
//     }

//     return true;
// }
