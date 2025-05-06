#include <iostream>
#include "SelfCounter.h"

int main()
{
    SelfCounter s;
    SelfCounter s1;
    SelfCounter s2;

    {
        SelfCounter s3;
    }

    std::cout << SelfCounter::getAliveCount() << ' ' << SelfCounter::getCreatedCount();
}