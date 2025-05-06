#pragma once
class SelfCounter
{
	int n = 0;

	static unsigned createdCount;
	static unsigned aliveCount;

public:
	SelfCounter();
	SelfCounter(int n);

	~SelfCounter();

	static unsigned getCreatedCount();
	static unsigned getAliveCount();
};

