#include <iostream>
#include <string>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void RunGame();
void InitializeGameboard(string gameboard[ROWS][COLS]);
void PrintCurrentBoard(string gameboard[ROWS][COLS]);
void GetUserInput(bool xTurn, string gameboard[ROWS][COLS]);
bool CellAlreadyOcupied(int row, int col, string gameboard[ROWS][COLS]);
string GetWinner(string gameboard[ROWS][COLS]);
bool IsBoardFull(string gameboard[ROWS][COLS]);

int main()
{
	RunGame();

	return 0;
}

void RunGame()
{
	string winner = "";
	string gameboard[ROWS][COLS];
	InitializeGameboard(gameboard);
	PrintCurrentBoard(gameboard);

	bool xTurn = true;
	while (winner == "")
	{
		if (xTurn == true) {
			GetUserInput(true, gameboard);
			xTurn = false;
		}
		else {
			GetUserInput(false, gameboard);
			xTurn = true;
		}
		PrintCurrentBoard(gameboard);
		winner = GetWinner(gameboard);
		if (IsBoardFull(gameboard)) {
			winner = "C";
		}
	}

	if (winner == "X") {
		cout << "X won!" << endl;
	}
	else if (winner == "O") {
		cout << "O won!" << endl;
	}
	else if (winner == "C") {
		cout << "Tie!" << endl;
	}
	else {
		cout << "DEBUG?" << endl;
	}
}

void InitializeGameboard(string gameboard[ROWS][COLS])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			gameboard[i][j] = " ";
		}
	}
}

void PrintCurrentBoard(string gameboard[ROWS][COLS])
{
	cout << gameboard[0][0] << " | " << gameboard[0][1] << " | " << gameboard[0][2] << endl;
	cout << "- - - - -" << endl;
	cout << gameboard[1][0] << " | " << gameboard[1][1] << " | " << gameboard[1][2] << endl;
	cout << "- - - - -" << endl;
	cout << gameboard[2][0] << " | " << gameboard[2][1] << " | " << gameboard[2][2] << endl;
}

void GetUserInput(bool xTurn, string gameboard[ROWS][COLS])
{
	bool isBetween = false;
	int inputRow;
	int inputCol;

	if (xTurn) {
		isBetween = false;

		while (!isBetween) {
			cout << "It's X's turn now! Write 0, 1 or 2 for the ROW, space and 0, 1 or 2 for the COLUMN." << endl;
			cin >> inputRow;
			cin >> inputCol;

			if (inputRow < 0 || inputRow > 2 || inputCol < 0 || inputCol > 2) {
				cout << "Please write a number between 0 and 2. And don't forget the space!" << endl;
			}
			else {
				if (CellAlreadyOcupied(inputRow, inputCol, gameboard)) {
					isBetween = true;
				}
				else {
					cout << "Cell already ocupied." << endl;
				}
			}
		}

		gameboard[inputRow][inputCol] = "X";

	} else {
		isBetween = false;

		while (!isBetween) {
			cout << "It's O's turn now! Write 0, 1 or 2 for the ROW, space and 0, 1 or 2 for the COLUMN." << endl;
			cin >> inputRow;
			cin >> inputCol;

			if (inputRow < 0 || inputRow > 2 || inputCol < 0 || inputCol > 2) {
				cout << "Please write a number between 0 and 2. And don't forget the space!" << endl;
			}
			else {
				if (CellAlreadyOcupied(inputRow, inputCol, gameboard)) {
					isBetween = true;
				}
				else {
					cout << "Cell already ocupied." << endl;
				}
			}
		}

		gameboard[inputRow][inputCol] = "O";
	}
}

bool CellAlreadyOcupied(int row, int col, string gameboard[ROWS][COLS])
{
	if (gameboard[row][col] == "X" || gameboard[row][col] == "O") {
		return false;
	}

	return true;
}

string GetWinner(string gameboard[ROWS][COLS])
{
	//I HATE THIS FUNCTION BC MY BRAIN CANNOT WORK AT ALL TO MAKE IT BETTER. WHERE ARE THE FORS?

	if (gameboard[0][0] == "X" && gameboard[0][1] == "X" && gameboard[0][2] == "X") {
		return "X";
	}
	else if (gameboard[1][0] == "X" && gameboard[1][1] == "X" && gameboard[1][2] == "X") {
		return "X";
	}
	else if (gameboard[2][0] == "X" && gameboard[2][1] == "X" && gameboard[2][2] == "X") {
		return "X";
	}

	if (gameboard[0][0] == "X" && gameboard[1][0] == "X" && gameboard[2][0] == "X") {
		return "X";
	}
	else if (gameboard[0][1] == "X" && gameboard[1][1] == "X" && gameboard[2][1] == "X") {
		return "X";
	}
	else if (gameboard[0][2] == "X" && gameboard[1][2] == "X" && gameboard[2][2] == "X") {
		return "X";
	}

	if (gameboard[0][0] == "X" && gameboard[1][1] == "X" && gameboard[2][2] == "X") {
		return "X";
	}
	else if (gameboard[2][0] == "X" && gameboard[1][1] == "X" && gameboard[0][2] == "X") {
		return "X";
	}

	if (gameboard[0][0] == "O" && gameboard[0][1] == "O" && gameboard[0][2] == "O") {
		return "O";
	}
	else if (gameboard[1][0] == "O" && gameboard[1][1] == "O" && gameboard[1][2] == "O") {
		return "O";
	}
	else if (gameboard[2][0] == "O" && gameboard[2][1] == "O" && gameboard[2][2] == "O") {
		return "O";
	}

	if (gameboard[0][0] == "O" && gameboard[1][0] == "O" && gameboard[2][0] == "O") {
		return "O";
	}
	else if (gameboard[0][1] == "O" && gameboard[1][1] == "O" && gameboard[2][1] == "O") {
		return "O";
	}
	else if (gameboard[0][2] == "O" && gameboard[1][2] == "O" && gameboard[2][2] == "O") {
		return "O";
	}

	if (gameboard[0][0] == "O" && gameboard[1][1] == "O" && gameboard[2][2] == "O") {
		return "O";
	}
	else if (gameboard[2][0] == "O" && gameboard[1][1] == "O" && gameboard[0][2] == "O") {
		return "O";
	}

	return "";
}

bool IsBoardFull(string gameboard[ROWS][COLS])
{
	//IDK HOW TO DO THIS FUNCTION zz

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (gameboard[i][j] == "X" || gameboard[i][j] == "O") {
				return true;
			}
		}
	}

	return false;
}