void to_lower(char* s) {
	for (size_t i = 0; s[i] != '0'; i++){
		//65 A to 90 Z and 32 defference to lowercase
		if (s[i] >= 65 && s[i] <= 90) {
			s[i] = s[i] + 32;
		}
	}
}

int main() {
	char text[] = "Hello World0!!";
	to_lower(text);

	//check with out using iostream header
	for (size_t i = 0; text[i] != '0'; i++) {
		if (text[i] >= 65 && text[i] <= 90) {
			// If check asscii values for upper case
			// appears program will crash.
			throw 1; // causes crash
		}
	}
	return 0;
}