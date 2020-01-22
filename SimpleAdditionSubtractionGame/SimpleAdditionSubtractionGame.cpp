#include<iostream>
#include<stdio.h>
#include<cmath>
#include<ctime>
using namespace std;
char displayMenu()
{
	char giris;
	cout << "Choose Difficult Level" << endl;
	cout << "1. Easy" << endl << "2. Moderate" << endl << "3. Advanced" << endl;
	cin >> giris;
	return giris;
}
char generateOperands()
{
	int a = rand() % 999 + 1;
	if (a % 2 == 0)
	{
		return '+';

	}
	if (a % 2 == 1)
	{
		return '-';
	}
}
int randomInt(int minimum, int maximum)
{
	int random;
	random = rand() % maximum + minimum;
	return random;
}
long int displayProblem(char artieksi, int number1, int number2)
{
	long int result;
	if (artieksi == '+')
	{
		cout << number1 << "+" << number2 << "=";
		cin >> result;
	}
	if (artieksi == '-')
	{
		cout << number1 << "-" << number2 << "=";
		cin >> result;
	}
	return result;
}
bool isCorrect(long int result, long int trueresult) {
	if (result == trueresult)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void displayMessage(bool a)
{
	if (a == true)
	{
		cout << "Correct!" << endl;
	}
	else
	{
		cout << "Incorrect!" << endl;
	}
}
void displayFinalResult(int temp1, int temp2) {

	cout << "Number of true is " << temp1 << endl;
	cout << "Number of false is " << temp2 << endl;
}
int main(void)
{
	int minimum, maximum;
	char giris, artiEksi;
	int number1, number2;
	long int result, trueResult;
	bool correct;
	int temp1 = 0, temp2 = 0;
	giris = displayMenu();
	srand(time(NULL));
	if (giris == '1')
	{
		maximum = 9;
		minimum = 1;
	}
	if (giris == '2')
	{
		maximum = 90;
		minimum = 10;
	}
	if (giris == '3')
	{
		maximum = 9000;
		minimum = 1000;
	}
	system("CLS");
	for (int i = 0; i < 10; i++)
	{
		number1 = randomInt(minimum, maximum);
		number2 = randomInt(minimum, maximum);
		artiEksi = generateOperands();
		if (artiEksi == '+')
		{
			trueResult = number1 + number2;
		}
		else
		{
			trueResult = number1 - number2;
		}
		result = displayProblem(artiEksi, number1, number2);
		correct = isCorrect(result, trueResult);
		displayMessage(correct);
		if (correct == false)
		{
			result = displayProblem(artiEksi, number1, number2);
			correct = isCorrect(result, trueResult);
			displayMessage(correct);
		}
		if (correct == true)
		{
			temp1++;
		}
		else
		{
			temp2++;
		}
	}
	displayFinalResult(temp1, temp2);
	cout << "Do you want to play again? Y/N" << endl;
	cin >> giris;
	if (giris == 'n' || giris == 'N')
		exit(0);
	system("pause");
}