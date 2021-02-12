void to_lower(char* s) {
	for (size_t i = 0; s[i] != '0'; i++){
		//65 A to 90 Z and 32 defference to lowercase (ascii)
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] = s[i] + 32;
		}
	}
}

int main() {
	// text array with terminating zero
	char text[] = "Hello, World!0";
	to_lower(text);

	//check with out using iostream header
	for (size_t i = 0; text[i] != '0'; i++) {
		if (text[i] >= 65 && text[i] <= 90) {
			// If check ascii values for upper case
			// appears program will crash.
			throw 1; // causes crash
			//return 1; // could return 1 as an indicator if crashing is bad
		}
	}
	return 0;
}