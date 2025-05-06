#include "SelfCounter.h"

unsigned SelfCounter::aliveCount = 0;
unsigned SelfCounter::createdCount = 0;

SelfCounter::SelfCounter() : SelfCounter(0)
{
}

SelfCounter::SelfCounter(int n) : n(n)
{
    createdCount++;
    aliveCount++;
}

SelfCounter::~SelfCounter()
{
    aliveCount--;
}

unsigned SelfCounter::getCreatedCount()
{
    return createdCount;
}

unsigned SelfCounter::getAliveCount()
{
    return aliveCount;
}
