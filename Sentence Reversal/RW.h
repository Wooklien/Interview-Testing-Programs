/* Quoc Lien.
*  Reverse Words - Reverses the words in the sentence.
*  10/18/2014
*/

#ifndef RW_H
#define RW_H

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;

class RW {
public:
	// Reverse Words in a string, Assumes words are delimited by spaces.
	void reverse_words(char *);
	void reverse(char *);	
};

#endif
