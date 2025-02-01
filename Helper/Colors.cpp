#include "Colors.h"

void Colors::reset() const
{
    cout << "\033[0m";
}

void Colors::red() const
{
    cout << "\033[1;31m";
}
