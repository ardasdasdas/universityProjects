#include "Matrix.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void PrintFrameLine(int length);
void PrintMessageInFrame(const string& message);
float** GetRandomData(int row, int column);
void TEST_FILL_BY_VALUE();
void TEST_FILL_BY_DATA();
void TEST_ADDITION();
void TEST_SUBSTRUCTION();
void TEST_MULTIPLICATION_MATRIX();
void TEST_MULTIPLICATION_CONSTANT();
void TEST_DIVISION();
void TEST_TRANSPOSE();
int main() {
	TEST_FILL_BY_VALUE();
	TEST_FILL_BY_DATA();
	TEST_ADDITION();
	TEST_SUBSTRUCTION();
	TEST_MULTIPLICATION_MATRIX();
	TEST_MULTIPLICATION_CONSTANT();
	TEST_DIVISION();
	TEST_TRANSPOSE();
	//return 0;
	system("pause");
}
void PrintFrameLine(int length) {
	cout << "+";
	length -= 2;
	for (int i = 0; i < length; i++) {
		cout << "-";
	}
	cout << "+" << endl;
}
void PrintMessageInFrame(const string& message) {
	PrintFrameLine(message.length() + 4);
	cout << "| " << message << " |" << endl;
	PrintFrameLine(message.length() + 4);
}
float** GetRandomData(int row, int column) {
	float** matrixData = new float*[row]; for (int i = 0; i < row; i++) {
		matrixData[i] = new float[column];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			matrixData[i][j] = -10 + rand() % (22);
		}
	}
	return matrixData;
}
void TEST_FILL_BY_VALUE() {
	PrintMessageInFrame("FILL BY VALUE TEST");
	Matrix m1;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByValue(m1, 1.34);
	Matrix_Display(m1);
	Matrix_Free(m1);
	Matrix_Allocate(m1, 4, 3);
	Matrix_FillByValue(m1, -2.65);
	Matrix_Display(m1);
	Matrix_Free(m1);
}
void TEST_FILL_BY_DATA() {
	PrintMessageInFrame("FILL BY DATA TEST");
	Matrix m1;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	Matrix_Display(m1);
	Matrix_Free(m1);
	Matrix_Allocate(m1, 4, 3);
	Matrix_FillByData(m1, GetRandomData(4, 3));
	Matrix_Display(m1);
	Matrix_Free(m1);
}
void TEST_ADDITION() {
	PrintMessageInFrame("ADDITION TEST");
	Matrix m1, m2, m3;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	cout << "First Matrix:" << endl;
	Matrix_Display(m1);
	Matrix_Allocate(m2, 2, 3);
	Matrix_FillByData(m2, GetRandomData(2, 3));
	cout << "Second Matrix:" << endl;
	Matrix_Display(m2);
	Matrix_Addition(m1, m2, m3);
	cout << "Result Matrix:" << endl;
	Matrix_Display(m3);
	Matrix_Free(m1);
	Matrix_Free(m2);
	Matrix_Free(m3);
}
void TEST_SUBSTRUCTION() {
	PrintMessageInFrame("SUBTRACTION TEST");
	Matrix m1, m2, m3;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	cout << "First Matrix:" << endl;
	Matrix_Display(m1); Matrix_Allocate(m2, 2, 3);
	Matrix_FillByData(m2, GetRandomData(2, 3));
	cout << "Second Matrix:" << endl;
	Matrix_Display(m2);
	Matrix_Subtraction(m1, m2, m3);
	cout << "Result Matrix:" << endl;
	Matrix_Display(m3);
	Matrix_Free(m1);
	Matrix_Free(m2);
	Matrix_Free(m3);
}
void TEST_MULTIPLICATION_MATRIX() {
	PrintMessageInFrame("MATRIX MULTIPLICATION TEST");
	Matrix m1, m2, m3;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	cout << "First Matrix:" << endl;
	Matrix_Display(m1);
	Matrix_Allocate(m2, 3, 2);
	Matrix_FillByData(m2, GetRandomData(3, 2));
	cout << "Second Matrix:" << endl;
	Matrix_Display(m2);
	Matrix_Multiplication(m1, m2, m3);
	cout << "Result Matrix:" << endl;
	Matrix_Display(m3);
	Matrix_Free(m1);
	Matrix_Free(m2);
	Matrix_Free(m3);
}
void TEST_MULTIPLICATION_CONSTANT() {
	PrintMessageInFrame("SCALAR MULTIPLICATION TEST");
	Matrix m1, m2;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	Matrix_Display(m1);
	float scalar = 3;
	Matrix_Multiplication(m1, scalar, m2);
	cout << "Result Matrix:" << endl;
	Matrix_Display(m2);
	Matrix_Free(m1);
	Matrix_Free(m2);
}
void TEST_DIVISION() {
	PrintMessageInFrame("SCALAR DIVISION TEST");
	Matrix m1, m2;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	Matrix_Display(m1);
	float scalar = 3;
	Matrix_Division(m1, scalar, m2);
	cout << "Result Matrix:" << endl;
	Matrix_Display(m2);
	Matrix_Free(m1);
	Matrix_Free(m2);
}
void TEST_TRANSPOSE()
{
	PrintMessageInFrame("TRANSPOSE TEST");
	Matrix m1, m2;
	Matrix_Allocate(m1, 2, 3);
	Matrix_FillByData(m1, GetRandomData(2, 3));
	Matrix_Display(m1);
	Matrix_Allocate(m2, 3, 2);
	Matrix_Transpose(m1, m2);
	cout << "Result Matrix:" << endl;
	Matrix_Display(m2);
	Matrix_Free(m1);
	Matrix_Free(m2);
}