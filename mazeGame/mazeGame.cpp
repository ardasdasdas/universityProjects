#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include<fstream>
#include<iomanip>
#include<Windows.h>
int i, j, temp, n, l, m;
int maze[100][100];
FILE *filep;
char giris;
using namespace std;
void harita(int n)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
			{
				maze[i][j] = 1;
			}
	}

	for (i = 1; i < n - 1; i++)
	{
		for (j = 1; j < n - 1; j++)
		{
			if (i == j)
			{
				maze[i][j] = 0;
				if (i != n - 1 || j != n - 1)
					maze[i + 1][j] = 0;
			}
			else
				maze[i][j] = rand() % 4;
		}
	}
	maze[n - 1][n - 2] = 7;
}
void altinAtama(int n)
{
	int k = 0;
	while (true)
	{
		i = rand() % n;
		j = rand() % n;
		if (maze[i][j] == 0)
		{
			maze[i][j] = 3;
			k++;
		}
		if (k == n / 8)
			break;
	}
}
void canavarAtama(int n)
{
	int k = 0;
	while (true)
	{
		i = rand() % n;
		j = rand() % n;
		if (i != j)
		{
			if (maze[i][j] == 0)
			{
				maze[i][j] = 8;
				k++;
			}
		}
		if (k == n / 5)
			break;
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (i == j)
			{
				maze[i][j] = 0;
				if (i != n - 1 || j != n - 1)
					maze[i + 1][j] = 0;
			}
		}
	}
	maze[n - 1][n - 2] = 7;

}
void printMaze(int n)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (maze[i][j] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				cout << "$";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				continue;
			}
			if (maze[i][j] == 8)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << char(237);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				continue;
			}
			if (maze[i][j] == 1)
				cout << char(219);
			else
				cout << ' ';
		}
		cout << endl;
	}
}
void koordinat(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y + 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hareket(int maze[][100], int n)
{
	cout << "Use W,A,S,D to move!" << endl;
	cout << "Info: $ is a gold, " << char(237) << " is a monster. If you are cathed by monster, you will go start position and your golds will be zero!" << endl;
	int x = 1;
	int y = 0;
	int xcln = -1, ycln = 0;
	int gold = 0;

	while (true)
	{
		koordinat(xcln, ycln);
		cout << " ";
		koordinat(x, y);
		cout << 'P';
		giris = _getch();
		xcln = x;
		ycln = y;

		if (giris == 'w' || giris == 'W')
			y -= 1;
		if (giris == 's' || giris == 'S')
			y += 1;
		if (giris == 'a' || giris == 'A')
			x -= 1;
		if (giris == 'd' || giris == 'D')
			x += 1;
		if (maze[y][x] == 3)
		{
			maze[y][x] = 0;
			gold++;
		}
		if (maze[y][x] == 1)
		{
			x = xcln;
			y = ycln;
		}
		if (maze[y][x] == 8)
		{
			maze[y][x] == 0;
			x = 1;
			y = 0;
			gold = 0;
		}
		if (maze[y][x] == 7)
		{
			system("cls");
			cout << endl << endl << "\nYOU WIN!" << endl;
			cout << "Number of Golds: " << gold << endl;
			system("color B");
			break;
		}
	}
}
int main()
{

	cout << "Enter the maze size: " << endl;
	cin >> n;

	srand(time(NULL));
	maze[n][n] = 1;
	altinAtama(n);
	harita(n);
	canavarAtama(n);
	printMaze(n);

	hareket(maze, n);

	system("pause");
	return 0;
}