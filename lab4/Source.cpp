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
		std::cout << "Error Can't Load Data!" << std::endl;
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
		std::cout << "Error in Saving Data!" << std::endl;
	}
	for (int i = 0; i < num; i++) { // loop to repeat text enter for num
		file << text << endl;
	}
	
}


int main() {
	readFile("text.txt"); // reads text
	int num;
	string text;
	cout << "Enter a number: ";
	cin >> num; // no error checking for num
	cout << "Enter text: ";
	cin.ignore(); // fixes issues with cin "\n" and getline
	std::getline(cin, text);
	saveFile("text.txt",num,text); // saves text

}