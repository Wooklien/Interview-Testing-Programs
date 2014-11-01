/* Quoc Lien.
*  Boggle Word Search Function.
*  10/18/2014
*/

#ifndef Word_Search_H
#define Word_Search_H
#define SIZE 3

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>

using namespace std;

class Boggle {
	public:
		Boggle();
		void print_board();
		char board[SIZE][SIZE];
};

class Word_Search {
public:
	vector<string> word_search(int, int, char[SIZE][SIZE], vector<string>);
	bool check_char(int, int, char[SIZE][SIZE], bool[SIZE][SIZE], char *);
	vector<string> create_dictionary(string);
	void print_list(vector<string>);
};

#endif
