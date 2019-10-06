#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
bool again = true;
bool winner = false;

void display();
int p1choice1, p2choice1;
int row = 5;
char board[6][7] = { {'_','_','_','_','_','_','_'},{'_','_','_','_','_','_','_'} ,{'_','_','_','_','_','_','_'} ,{'_','_','_','_','_','_','_'} ,{'_','_','_','_','_','_','_'} ,{'_','_','_','_','_','_','_'} };
void display() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			cout << setw(2) << board[i][j] << " ";
		
		}
		cout  << endl;
	
	}
	for (int k = 0; k < 7; k++) {
		cout << "  " << k;
	}
	cout << endl;
}

void checkFull() {
	while (board[row][p1choice1] != '_') {
		row--;                                     
	}
	if (row < 0) {
		cout << "FULL COLUMN!" << endl;
		row = -1;
	}
}

void checkFull2() {
	while (board[row][p2choice1] != '_') {
		row--;
	}
	if (row < 0) {
		cout << "FULL COLUMN!" << endl;
		row = -1;
	}
}

void clearBoard() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			board[i][j] = '_';
		}
	}
}
/*
_ _ _ _ _ _ _
_ _ _ _ _ _ _
_ _ _ _ _ _ _
_ _ _ _ _ _ _
_ _ _ _ _ _ _
_ _ _ _ _ _ _
*/

void checkWin() {
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			//cout << board[i][j] << " ";
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j + 3] != NULL && board[i][j] != '_') {
				cout << "Found a horizontal match on " << i << " " << j << endl;
				winner = true;
				display();
				cout << "Again (0/1)";
				cin >> again;
				clearBoard();
			}
			if ((board[i][j] == board[i + 1][j]) && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j] && board[i + 3][j] != NULL && board[i][j] != '_') {
				cout << "Found a vertical match on " << i << " " << j << endl;
				winner = true;
				display();
				cout << "Again (0/1)";
				cin >> again;
				clearBoard();
			}
		}
	}

}

void player1turn() {
	cout << "Player 1 (X).....enter column choice (0-6): ";
	cin >> p1choice1;
	checkFull();
	board[row][p1choice1] = 'X';
	checkWin();
	
}

void player2turn() {
	cout << "Player 2 (O) .... enter column choice (0-6): ";
	cin >> p2choice1;
	checkFull2();
	board[row][p2choice1] = 'O';
	checkWin();
}



bool checkFullBoard() {
	int count = 0;
	for (int i = 0; i < 7; i++) {
		if (board[0][i] != '_') {
			count++;
		}
	}
	if (count >= 7) {
		cout << "FULL BOARD";
		cout << "Again? (1/0)";
		cin >> again;
		return true;
	}
	else {
		return false;
	}
}




int main() {
	
	display();
	do {
		winner = false;
		if (!winner && !checkFullBoard()) {
			player1turn();
			display();
			row = 5;
		}
		if (!winner && !checkFullBoard()) {
			player2turn();
			display();
			row = 5;
		}
	} while (again);

	
	system("PAUSE");
	return 0;
}