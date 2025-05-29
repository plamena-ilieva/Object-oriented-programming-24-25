#include <iostream>
#include <fstream>
#include <iomanip>

#include "HexViewer.h"

int main() {
	HexViewer hv("test.dat");
	hv.print();
}