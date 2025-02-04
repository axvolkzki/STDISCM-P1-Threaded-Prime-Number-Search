#pragma once
#include <iostream>
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
    void searchPrimes(int start, int end, int threadID, APrint* printer, char variant) override;
    
private:
    Colors colors;
    bool isPrime(int number);
};