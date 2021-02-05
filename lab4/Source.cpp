#include <iostream>
using std::endl;
using std::cout;
using std::cin;
#include <string>
using std::string;
#include <fstream>

void readFile(std::string filename) {
	std::ifstream open(filename);
	if (!open) { // quick error check
		cout << "Error Can't Load Data!" << std::endl;
	}
	else {
		while (!open.eof()) {
			string input;
			std::getline(open, input);
			cout << input << std::endl;
		}
	}
}


void saveFile(string filename, int num, string text) {

	std::ofstream file(filename, std::ios::app); // std::ios::app set the file to be in append mode
	if (!file) { // quick error checks
		cout << "Error in Saving Data!" << std::endl;
	}
	for (int i = 0; i < num; i++) { // loop to repeat text enter for num
		file << text << endl;
	}
	
}

// Determine amount of digits in num 
int numberDigits(int num) {
	int numdigit = 0;
	do
	{
		num = num / 10;
		numdigit++;
	} while (num != 0);
	return numdigit;
}

int main() {
	while (true) {
		readFile("text.txt"); // reads text
		int num;
		string text;
		cout << "Enter Num then Text: ";
		std::getline(cin, text);
		num = std::stoi(text); // Takes first in from text
		text.erase(0, numberDigits(num)); // removes num
		saveFile("text.txt", num, text); // saves text
	}
}