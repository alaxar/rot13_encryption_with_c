#include <stdio.h>
#include <stdlib.h>

// functions prototype
char *rot13_encrypt(char letter, int iteration_value);


// global variables
char alphabets[26];
char *cipher = NULL;
int index_pos;

int main(int argc, char *argv[]) {
	int cipher_size = 0;

	if(argc == 2) { // checking if the user has provided a message to either encrypt or decrypt.

		// loading alphabets to a char array
		for(int i = 0, j = 0; i < 26; i++) {
			alphabets[i] = (char)97 + i;
		}

		// determine the size of the input characters
		for(int i = 0; argv[1][i] != '\0'; i++) {
			cipher_size++;
		}
		
		// allocate memory for cipher pointer variable by the size of the user input value
		cipher = (char*)malloc(cipher_size);

		// parsing into user input character and sending it to rot13_encrpt function
		for(int i = 0; argv[1][i] != '\0'; i++) {
			rot13_encrypt(argv[1][i], i);
		}
		fprintf(stdout, "Original text: %s\n", argv[1]);
		fprintf(stdout, "Cipher text: %s\n", cipher);
	} else {
		fprintf(stdout, "Usage: %s <message_to_either_encrypt_or_decrypt>\n", argv[0]);
	}
	return 0;
}

char *rot13_encrypt(char letter, int iteration_value) {
	index_pos = letter - 97;	// get the index value by subtracting 97 from the letter which the user provided, 97 is for lowercase of a
	
	int rotation_key = 13;		// rotation key
	cipher[iteration_value] =  alphabets[(index_pos + rotation_key) % 26];
	return cipher;
}
