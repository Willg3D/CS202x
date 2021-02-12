
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
	return 0;
}