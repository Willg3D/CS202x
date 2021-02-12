#include <iostream> //for testing

void to_lower(char* s) {
	for (size_t i = 0; s[i] != '0'; i++){
		std::cout << s[i];
	}
}

int main() {
	char text[] = "Hello World0!!";
	to_lower(text);

	return 0;
}