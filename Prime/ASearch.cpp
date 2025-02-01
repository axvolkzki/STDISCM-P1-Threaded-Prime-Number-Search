#include "ASearch.h"

std::mutex ASearch::outputMutex;

bool ASearch::isPrime(int num)
{
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}
