#pragma once

class VectorsArraysExampleClass
{
public:

	VectorsArraysExampleClass() = default;
	VectorsArraysExampleClass(int numInt, double numDouble) : mNumInt{ numInt }, mNumDouble{ numDouble }{}

private:

	int mNumInt;
	double mNumDouble;
};

void executeVectorsArraysExample();