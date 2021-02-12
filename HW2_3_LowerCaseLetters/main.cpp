#include <iostream> //for testing

void to_lower(char* s) {
	for (size_t i = 0; s[i] != '0'; i++){
		//65 A to 90 Z
		if (s[i] >= 65 && s[i] <= 90) {
			std::cout << s[i];
		}
	}
}

int main() {
	char text[] = "Hello World0!!";
	to_lower(text);

	return 0;
}