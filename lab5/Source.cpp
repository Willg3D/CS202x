#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>

using std::ofstream;
using std::ifstream;

int main() {

	ifstream fin("data.dat", std::ios::binary | std::ios::in);

	int numInt = 0, sum = 0;

	int num;
	while (true){
		fin.read(reinterpret_cast<char*>(&num), sizeof(num));

		if (!fin) {
			break;
		}
		
		numInt++;
		sum += num;
	}

	std::cout << "Number of int: " << numInt << "\n";
	std::cout << "Sum: " << sum << "\n";
	std::cout << "Average: " << (double)sum / (double)numInt;

	return 0;
}