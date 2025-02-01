#pragma once
#include <iostream>
#include <chrono>
#include <mutex>

#include "../TypeDefRepo.h"
#include "../Config/GlobalConfig.h"
#include "APrint.h"

class PrintImmediately : public APrint
{
public:
    static PrintImmediately* getInstance();
    void logPrime(int prime, int threadId) override;

    void printPrimes() override;

private:
    PrintImmediately() = default;
    std::mutex printMutex;
};