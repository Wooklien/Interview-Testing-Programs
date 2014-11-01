#include "Word_Search.h"

int fx = 0, fy = 0;

/* Hardcoded the Board to test the accuracy of the algorithm.
 * Due to Dynamic programming, the algorithm will still run fast. Since we are using
 * the actual string in the word list to search in the board, not the words created
 * from the characters on the board. 
*/
Boggle::Boggle() {
	board[0][0] = 'y';
	board[1][0] = 'o';
	board[2][0] = 'x';
	board[0][1] = 'r';
	board[1][1] = 'b';
	board[2][1] = 'a';
	board[0][2] = 'v';
	board[1][2] = 'e';
	board[2][2] = 'd';
}

void Boggle::print_board() {
	for(int j = 0; j < 3; j++) {
		for(int i = 0; i < 3; i++) {
			cout << board[i][j] << "\t";
		}
		cout << "\n";
	}
}

/*This function checks all adjacent cells that have not been visited. 
* For every character it finds in the board, it marks it as visited and
* sets the position of next position to check from.
*/
bool check_char(int x, int y, char (&board)[SIZE][SIZE], bool (&visited)[SIZE][SIZE], char * c) {
	int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
	int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
	for(int index = 0; index < 8; index++) {
		int x2 = x + dx[index];
		int y2 = y + dy[index];
		if (x2 >= 0 && x2 < SIZE && y2 >= 0 && y2 < SIZE  && !visited[x2][y2]) {
			if(*c == board[x2][y2]) {
				visited[x2][y2] = true;
				fx = x2;
				fy = y2;
				return true;
			}
		}
	}

	return false;
}

/* Using Dynamic Programming, we use a look up table and search for the words on the board.
 * our lookup table, the dictionary, is preprocess before time. This reduces the complexity of the algorithm
 * allowing complexity time of O(N*W), N the length of the array * length of the string!
*/
vector<string> word_search(int w, int h, char (&board)[SIZE][SIZE], vector<string> wl) {
	bool visited[SIZE][SIZE];
	vector<string> found;

	for(unsigned int w = 0; w < wl.size(); w++) { // Traverse the length of the wordlist.
		string str = wl[w]; // Dynamic Programming. Checking the Word in the dictionary rather than compiling words and checking the dictionary.
		for(int y = 0; y < SIZE; y++) { // Height of the board.
			for(int x = 0; x < SIZE; x++) { // Width of the board.
				memset(visited, false, sizeof(visited)); // set (visited)adjacent matrix.

				if(str.at(0) == board[x][y]) { // Optimization, Compares first character to the board. If false, move to the next word.
					visited[x][y] = true; // Set current position to visited. 
					fx = x;
					fy = y;
					for(unsigned int i = 1; i < str.length(); i++) { 
						char * c = &str.at(i);

						/* Checking for the characters in adjacent cells */
						if(!check_char(fx, fy, board, visited, c)) {
							break; // Stop seaching character in the string if if the current character isnt found in the adjacent cells.
						}

						// If all the characters are found then add it to our found array.
						if(i == str.length() - 1) {
							found.push_back(str);
						}
					}
				}
			}
		}
	}

	return found;
}

// Creates a dictionary vector array, this will be used for our look up table. 
vector<string> create_dictionary(char* path) {
	vector<string> dictionary;
	ifstream fs(path);

	if(fs.fail()) {
		return dictionary;
	}

	string s;
	while(!fs.eof()) {
		fs >> s;
		dictionary.push_back(s);
	}
	cout << "Dictionary Size: " << dictionary.size() << endl;
	fs.close();
	return dictionary;
}

void print_list(vector<string> list) {
	for(size_t i = 0; i < list.size(); i++) {
		cout << list[i] << endl;
	}
}

int main(int argc, char* argv[]) {
	if(argc < 2) {
		printf("%s\n", "Invalid arguments: <filename>");
		exit(1);
	}

	Boggle boggle;
	clock_t timer, stop_timer;

	vector<string> wordlist, found_list;
	timer = clock();
	wordlist = create_dictionary(argv[1]);
	stop_timer = clock();

	cout << "Execution Time for Dictionary Creation: " << (double)(stop_timer - timer)/(CLOCKS_PER_SEC)<< endl;

	timer = clock();
	found_list = word_search(SIZE, SIZE, boggle.board, wordlist);
	stop_timer = clock();
	cout << "Execution Time for Word Search Func: " << (double)(stop_timer - timer)/(CLOCKS_PER_SEC)<< endl;

	print_list(found_list);
	return 0;
}
