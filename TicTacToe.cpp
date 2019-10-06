#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int p1choice1;
int p1choice2;
int p2choice1;
int p2choice2;

bool winner = false;
bool again = true;
bool fullBoard = false;

char board[3][3] = { {'_','_','_'},{'_','_','_'},{'_','_','_'} };
void displayBoard();
void clearBoard();

void displayBoard() {
	for (int i = 0; i < 3; i++) {
		cout << i << " ";
		for (int j = 0; j < 3; j++) {
			cout << setw(5) << board[i][j] << ' ';
		}
		cout << endl;
}
	cout << "     0     1     2";
}

void clearBoard() {
	winner = false;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '_';
		}
	}
}



void checkWin() {
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' || board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
		winner = true;
	}
	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' || board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') {          //check horizontal wins
		winner = true;
	}
	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' || board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
		winner = true;
	}
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' || board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
		winner = true;
	}
	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' || board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {       //check vertical
		winner = true;
	}
	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' || board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
		winner = true;
	}
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' || board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {      //check diagonal
		winner = true;
	}
	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X' || board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
		winner = true;
	}
	int fillCount = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != '_')
				fillCount++;
		}
	}
	if (fillCount >= 9) {
		winner = true;
		fullBoard = true;
	}

}

void player2Loop() {
	cout << endl << "Player 2 (O), enter row number (0-2): ";
	cin >> p2choice1;
	cout << "Enter column: (0-2): ";
	cin >> p2choice2;
	while (board[p2choice1][p2choice2] != '_') {
		cout << "ERROR, spot taken/unavailable... Re-enter choices " << endl;
		cout << "Row choice :";
		cin >> p2choice1;
		cout << "column choice: ";
		cin >> p2choice2;
	}
	board[p2choice1][p2choice2] = 'O';
	displayBoard();
	checkWin();
}

void player1Loop() {
	cout << endl << "Player 1, (X), enter row number (0-2): ";
	cin >> p1choice1;
	cout << "Enter column: (0-2): ";
	cin >> p1choice2;
	while (board[p1choice1][p1choice2] != '_') {
		cout << "ERROR, spot taken/unavailable... Re-enter choices " << endl;
		cout << "Row choice :";
		cin >> p1choice1;
		cout << "column choice: ";
		cin >> p1choice2;
	}
	board[p1choice1][p1choice2] = 'X';
	displayBoard();
	checkWin();
}



int main() {
	
	while (again) {
		clearBoard();
		displayBoard();
		do {
			player1Loop();
			if (!winner) {
				player2Loop();
			}
		} while (!winner);


		if (!fullBoard) {
			cout << setw(20) << "       GAME OVER, WINNER! Again? (0/1)";
			cin >> again;
			while (again != 0 && again != 1)
			{
				cin.clear();
				cin.ignore();
				cin >> again;

			}
		}
		else {
			cout << "      full board! Tie Game! Again?(0/1)" << endl;
			cin >> again;
			while (again != 0 && again != 1)
			{
				cin.clear(); 
				cin.ignore();
				cin >> again;

			}
		}
	}
	
	system("PAUSE");
	return 0;
}