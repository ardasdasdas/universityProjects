#include<stdio.h>//to use functons of printf() and scanf_s()
#include<stdlib.h>//to use functon of system()
#include<string.h>//to use arrays in scanf
#define SIZE 40 //digits
int from_character_to_number(char character)//Function of converting character to integer.
{
	return character % 48;//0 of integer is 48 in ascii table.
}
int main()
{
	int sum_of_digits = 0, difference_of_digits = 0, plus = 0, difference = 0;
	char number1[SIZE + 1], number2[SIZE + 1], addition[SIZE + 1], subtraction[SIZE + 1];
	//can not keep integer with 40 digits, but can keep 40 integers with 1 digit in char.
	//size + 1 = 41. Array[41] = null, '\0'

	printf("Enter a number: ");
	scanf_s("%40s", number1, sizeof(number1));
	printf("Enter a number: ");
	scanf_s("%40s", number2, sizeof(number2));
	//gets(number1)  //Use string in scanf_s

	for (int i = SIZE; i >= 0; i--)
	{
		sum_of_digits = from_character_to_number(number1[i]) + from_character_to_number(number2[i]) + plus;//use the function of from_character_to_number
		plus = 0;// reset the plus

		if (sum_of_digits > 9 && i != 0)
		{
			plus = 1;
			sum_of_digits %= 10;
		}
		// if sum of 2 integer is with 2 digits, print only units digit and add one to the next number.

		addition[i] = sum_of_digits;
	}
	for (int i = SIZE - 1; i >= 0; i--)
	{
		difference_of_digits = from_character_to_number(number1[i]) - from_character_to_number(number2[i]) + difference;
		difference = 0;//reset the difference

		if (difference_of_digits < 0)
		{
			difference_of_digits += 10;
			difference = -1;
		}
		// if difference of 2 integer is smaller than 0, add 10 diggerence of digits, print only units digit and add 1 to the next number.

		subtraction[i] = difference_of_digits;
	}
	printf("Addition of numbers: ");
	for (int i = 0; i < SIZE; i++)//print array of addition by loop
		printf("%d", addition[i]);

	printf("\n");

	printf("Difference of numbers: ");
	for (int i = 0; i < SIZE; i++)//print array of difference by loop
		printf("%d", subtraction[i]);

	printf("\n");
	system("pause");
}