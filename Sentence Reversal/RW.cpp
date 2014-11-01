#include "RW.h"

/* Parameter: Pointer to a character array in reversed order.
 * Purpose: Reverses the character positions of each word.
 * Example: input - raB ooF, output - Bar Foo
 * Time & Space Complexity: T = O(n), S = O(n)
 */
void RW::reverse_words(char * sentence) {
	string s = string(sentence);
	string reversed = "";
	char * str;

	/* Parsing the sentence with spaces as a delimiter */
	str = strtok(&s[0], " ");
	while(str != NULL) {
		reverse(str); // Reversing the order of the Word.
		reversed += string(str) + " "; // Concatenating tokens with spaces. 
		str = strtok(NULL, " ");
	}
	reversed.erase(reversed.length()-1, 1); // Erasing extra space at the end of the string. 

	/* Checks for length of strings. 
	 * Prevents buffer overflow.
	 * Overwrites character from reversed string to sentence.
	 */
	if(strlen(sentence) == reversed.length()) {
		strcpy(sentence, &reversed[0]);
	}
}

/* Parameter: Pointer to a character array.
 * Purpose: Reverses the positions of each character.
 * Example: input - Foo Bar, output - raB ooF
 * Time & Space Complexity: T = O(n), S = O(1)
 */
void RW::reverse(char * string) {
	char *str = string;
	char temp;

	if(string) {
		/* Increment character pointer until NULL */
		while(*str) {
			++str;
		}
		--str; // Decrement pointer to last character poistion. 

		/* Swaps from the front to the back */
		while(string < str) {
			temp = *string;
			*string = *str;
			*str = temp;
			string++;
			str--;
		}		
	}
}

int main(int argc, char* argv[]) {

	/* Checks for correct # of arguments passed in to cmdline. */
	RW reverse;
	char test[]= "Now is the winter of our discontent made glorious summer by this son of York";
	
	reverse.reverse(test);
	reverse.reverse_words(test);
	printf("%s\n", test);
	return 0;
}
