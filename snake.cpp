#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
bool gameover = false;

enum Direction {
	STOP = 0, UP, DOWN, LEFT,RIGHT
};

Direction dir;
int width = 40, height = 20, x, y, Foodx, Foody, score;
int snakeX[100], snakeY[100];
int ntail;

void Setup() {
	gameover = false;
	x = width / 2;
	y = height / 2;
	ntail = 0;
	Foodx = rand() % width;
	Foody = rand() % height;
	dir = STOP;
	score = 0;
}

void Draw() {

	system("cls");

	cout << "\t SNAKE GAME  O~~~~~" << endl;

	for (int i = 0; i < width+1; i++)
		cout << "#";

	cout << endl;
	
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0) {
				cout << "#";
			}
			else if (i == y && j ==x ) {
				cout << "O";
			}
			else if (i == Foody && j == Foodx) {
				cout << "F";
			}
			else {
				cout << " ";
			}
			if (j == width - 1) {
				cout << "#";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width+1; i++)
		cout << "#";

	cout << endl;
	cout << "Score:" << score;
}

void Input() {
	 if (_kbhit()) {
		switch (_getch()) {
		case 'a': dir = LEFT;
			break;
		case 'd': dir = RIGHT;
			break;
		case 'w': dir = UP;
			break;
		case 's' :dir = DOWN;
				break;
		}
	}
}

void Logic() {

	int prevX = snakeX[0];
	int prevY = snakeY[0];
	int prev2X, prev2Y;

	for (int i = 1; i < ntail; i++) {
		prev2X = snakeX[i];
		prev2Y = snakeY[i];
		snakeX[i] = prevX;
		snakeY[i] = prevX;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)
	{
	case UP:y--;
		break;
	case DOWN:y++;
		break;
	case LEFT:x--;
		break;
	case RIGHT:x++;
		break;
	}

	if (x < 0)x = width;
	if (x > width)x = 0;
	if (y > height)y = 0;
	if (y < 0)y = height;

	if (Foodx == x && Foody == y) {
		Foodx = rand() % width;
		Foody = rand() % height;
		score = score + 10 ;
		ntail++;
	}

}

void GameOverScr() {
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t \t GAME OVER" << endl;
	cout << " \t \t Better luck next time" << endl;
	cout << " \t \t Your score: " << score;
}

int main() {
	Setup();
	while (!gameover) {
		Draw();
		Input();
		Logic();
		Sleep(70);
	}
	GameOverScr();

	cin.get();
}
