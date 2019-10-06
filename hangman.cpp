#include<iostream>
#include<string>
#include<iomanip>
#include<conio.h>


using namespace std;

char alphabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

string secretWord;
char wordArray[32] = "";

string guess;
int guessCount = 0;
bool correctGuess = false;
bool gameOver = false;

void display() {
	for (int i = 0; i < sizeof(alphabet) / sizeof(*alphabet); i++) {       
		cout << alphabet[i] << " ";
	}
	cout << endl;
}

void update(char x) {
	for (int i = 0; i < sizeof(alphabet) / sizeof(*alphabet); i++) {       // update the displayed alphabet, removing letters that have already been guessed
		if (x == alphabet[i]) {
			alphabet[i] ='_';
		}
	}
}

void Draw() {
	if (guessCount == 1) {
		cout << " |" << endl << endl;
	}
	else if (guessCount == 2) {
		cout << " |" << endl;
		cout << " |" << endl << endl;
	}
	else if (guessCount == 3) {
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " O" << endl << endl;
	}
	else if (guessCount == 4) {
		cout << " |" << endl;
		cout << " |" << endl;                            //draw hangman after each incorrect guess
		cout << " O" << endl;
		cout << "/" << endl << endl;
	}
	else if (guessCount == 5) {
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " O" << endl;
		cout << "/";
		cout << "|" << endl << endl;
	}
	else if (guessCount == 6) {
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " O" << endl;
		cout << "/";
		cout << "|";
		cout << "\\" << endl << endl;
	}
	else if (guessCount == 7) {
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " O" << endl;
		cout << "/";
		cout << "|";
		cout << "\\" << endl;
		cout << "/ " << endl << endl;
	}
	else if (guessCount == 8) {
		cout << " |" << endl;
		cout << " |" << endl;
		cout << " O" << endl;
		cout << "/";
		cout << "|";
		cout << "\\" << endl;
		cout << "/ ";
		cout << "\\" << endl;
		cout << "THE SECRET WORD WAS " << secretWord << endl;
		gameOver = true;
	}
	else
		exit;
}

void wordSoFar() {
	cout << "Here is what you guessed correctly so far: ";
	for (int i = 0; i < secretWord.size(); i++) {
		if (secretWord[i] == guess[0]) {
			wordArray[i] = secretWord[i];
		}	
	}
	for (int i = 0; i < sizeof(wordArray)/sizeof(*wordArray); i++){
		cout << wordArray[i];
		}
	cout << endl;
}

void winCheck(){
	if (secretWord == wordArray) {
		gameOver = true;
}
	else {
		gameOver = false;
	}
}

void getGuess() {
	correctGuess = false;
	cout << "Enter a letter: ";
	cin >> guess;
	while (guess.length() > 1) {
		cout << "Too many characters! Re-enter a guess, 1 character only. \n";
		cin >> guess;
	}
	guess[0] = toupper(guess[0]);
	for (int i = 0; i < secretWord.size(); i++) {
		if (guess[0] == secretWord[i]) {
			cout << "That is in the word, guess again" << endl;
			update(secretWord[i]);
			correctGuess = true;
		}	
	}
	if (!correctGuess) {
		guessCount++;
		update(guess[0]);
		Draw();
	}
}


void getWord() {
	char c = ' ';
	secretWord = "";
	cout << "ENTER SECRET WORD: ";
	while (c!=13){
		c = _getch();
		if (c != 13 && c != 8){
			secretWord += c;
			cout << "*";
		}
	}
	cout << endl;
	for (int i = 0; i < secretWord.length(); i++) {
		secretWord[i] = toupper(secretWord[i]);
	}
}

int main() {

	cout << "WELCOME TO HANGMAN" << endl;
	cout << " |" << endl;
	cout << " |" << endl;
	cout << " O"<< endl;
	cout << "/";
	cout << "|";
	cout << "\\" << endl;
	cout << "/ ";
	cout << "\\" << endl;
	cout << endl;
	display();
	getWord();

	while(!gameOver && guessCount <=7){

		winCheck();
		getGuess();                                              //gameLoop
		display();
		wordSoFar();
		winCheck();
	}
	if (guessCount >= 8) {
		cout << "GUESSER LOSES! \n";
		cout << "Word was " << secretWord << endl;
	}
	else {
		cout << "YOU ARE CORRECT! YOU WIN \n";
		cout << "\n \n Gameover" << endl;
		cout << "Don't press any key to continue. . .";
	}
	system("PAUSE");
	return 0;
}