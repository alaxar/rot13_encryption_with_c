#include <stdio.h>
#include <stdlib.h>

// functions prototype
char *rot13_encrypt(char letter, int iteration_value);


// global variables
char all_cases[52];
char alphabets[26];
char *cipher = NULL;
int index_pos;

int main(int argc, char *argv[]) {
	int cipher_size = 0;

	if(argc == 2) {

		// loading alphabets to a char array
		for(int i = 0, j = 0; i < 26; i++) {
			alphabets[i] = (char)97 + i;
		}

		printf("%c", all_cases[1 + 26]);
		// determine the size of the input characters
		for(int i = 0; argv[1][i] != '\0'; i++) {
			cipher_size++;
		}
		
		// allocate memory for cipher pointer variable by the size of the user input value
		cipher = (char*)malloc(cipher_size);

		// check if the letter is whether its uppercase or lowercase
		for(int i = 0; argv[1][i] != '\0'; i++) {
			rot13_encrypt(argv[1][i], i);
		}
		printf("Original text: %s\n", argv[1]);
		printf("Cipher text: %s\n", cipher);
	} else {
		fprintf(stdout, "Usage: %s <message_to_either_encrypt_or_decrypt>\n", argv[0]);
	}
	return 0;
}

char *rot13_encrypt(char letter, int iteration_value) {
	index_pos = letter - 97;
	int rotation_key = 13;
	cipher[iteration_value] =  alphabets[(index_pos + rotation_key) % 26];
	return cipher;
}
