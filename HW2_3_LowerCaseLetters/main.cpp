// William Glass
// CS 202x
// HW 2_3
void to_lower(char* s) {
	for (size_t i = 0; s[i] != 0; i++){
		//65 A to 90 Z and 32 defference to lowercase (ascii)
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] = s[i] + 32;
		}
	}
}

int main() {
	char text[] = "Hello, World!";
	to_lower(text);

	// a check without using iostream header
	for (size_t i = 0; text[i] != 0; i++) {
		if (text[i] >= 65 && text[i] <= 90) {
			// If check sees ascii values for upper case
			// letters appear then the program will crash.

			throw 1; // causes crash on purpose
			//return 1; // could return 1 as an indicator if crashing is bad
		}
	}
	return 0;
}