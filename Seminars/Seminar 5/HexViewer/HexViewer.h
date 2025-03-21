#pragma once
class HexViewer
{
	unsigned char* data = nullptr;
	size_t size = 0;
public:
	HexViewer(const char* fileName);
	void print() const;

	~HexViewer();
};

