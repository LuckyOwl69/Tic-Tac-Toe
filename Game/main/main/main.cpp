#include <iostream>;

using namespace std;

char boardRowOne[] = { Q, W, E };
char boardRowTwo[] = { A, S, D };
char boardRowThree[] = { Z, X, C };

char board[3][3];

char playermove;

void printarray(int arg[], int length) {
	for (int n = 0; n < length; ++n)
		cout << arg[n] << ' ';
	cout << '\n';
}

int main() {
	board[1][1] = 7;
	board[1][2] = 8;
	board[1][3] = 9;
	board[2][1] = 4;
	board[2][2] = 5;
	board[2][3] = 6;
	board[3][1] = 1;
	board[3][2] = 2;
	board[3][3] = 3;

	//cout << board[3][3];


	printarray(boardRowOne, 3);
	printarray(boardRowTwo, 3);
	printarray(boardRowThree, 3);

	cout << "Where do you wanna place a x?";
	cin >> playermove;

	if (playermove = 7) {
		board[1][1] = X;

	}
}


//implement pointers!