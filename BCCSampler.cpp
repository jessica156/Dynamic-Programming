#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

typedef unsigned long long int ull;

ull CountSampler(const int n, const int s, const int l);

int main()
{
	int n, s, l, x;
	std::string line;
	std::ifstream inFile;
	std::ofstream outFile;

	inFile.open("input.txt");
	outFile.open("output.txt");

	// Check to make sure file open correctly
	if (!inFile)
	{
		std::cout << "Error: Unable to open input file!";
		return 1;		// Terminate the program with error
	}

	std::getline(inFile, line);
	std::istringstream input(line);

	input >> x;

	for (int i = 1; i <= x; ++i)
	{
		std::getline(inFile, line);
		std::istringstream input(line);

		input >> n >> s >> l;

		outFile << CountSampler(n, s, l) << '\n';
	}

	return 0;
}

ull CountSampler(const int n, const int s, const int l)
{
	std::vector<ull>samp(n+1);

	for (int i = 0; i <= n; ++i)
	{
		if (i == 0)
			samp[i] = 1;
		else if (i == 1)
			samp[i] = s;
		else
			samp[i] = (samp[i - 1]*s) + (samp[i - 2]*l);
	}

	return samp[n];
}