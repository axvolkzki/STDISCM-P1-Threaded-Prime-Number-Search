#include "ASearch.h"

// #include <cmath>  // sqrt

// mutex for output
std::mutex ASearch::searchMutex;

// bool ASearch::isPrime(int number)
// {
//     if (number <= 1) {
//         return false;
//     }

//     // Checks up to the square root of the number
//     // for (int i = 2; i * i <= number; i++) {
//     //     if (number % i == 0) {
//     //         return false;
//     //     }
//     // }

//     // return true;

//     // Optimized version
//     for (int i = 2; i <= sqrt(number); i++) {
//         if (number % i == 0) {
//             return false;
//         }
//     }

//     return true;
// }
