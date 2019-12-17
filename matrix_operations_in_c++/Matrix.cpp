/**
* @author	: Muzaffer Arda Uslu -> e-mail -> usluarda60@icloud.com
* @date		: 15 Ekim 2019 Cuma
* @brief	: Bu kod parcacigi Nesne Tabanlý Programlama Lab 2 icin yazýlmýþtýr.
*/
#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;
/**
* @brief	: Bu fonksiyon iki boyutlu dinamik matrisin her elemaný icin hafýzada yer acar.
* @param	: struct tipinde matrix referans, integer tipinde row ve column parametrelerini icerir.
*/
void Matrix_Allocate(Matrix& matrix, int rowSize, int columnSize) {
	int i;
	matrix.data = new float*[rowSize];
	for (i = 0; i < rowSize; i++)
	{
		matrix.data[i] = new float[columnSize];
	}
	matrix.rowSize = rowSize;
	matrix.columnSize = columnSize;
}
/**
* @brief	: Bu fonksiyon iki boyutlu dinamik matrisin her elemani icin hafizada ayirilan yeri siler.
* @param	: struct tipinde matrix parametresini icerir.
*/
void Matrix_Free(Matrix& matrix) {
	int i, j;
	for (i = 0; i < matrix.rowSize; i++)
	{
		delete[] matrix.data[i];
	}
	delete[] matrix.data;

	matrix.rowSize = -1;
	matrix.columnSize = -1;
	matrix.data = nullptr;
}
/**
* @brief	: Bu fonksiyon iki boyutlu dinamik matrisin her elemanina value parametresini atar.
* @param	: struct tipinde matrix ve float tipinde value parametresini icerir.
*/
void Matrix_FillByValue(Matrix& matrix, float value) {
	for (int i = 0; i < matrix.rowSize; i++)
	{
		for (int j = 0; j < matrix.columnSize; j++)
		{
			matrix.data[i][j] = value;
		}	
	}
}
/**
* @brief	: Bu fonksiyon iki boyutlu dinamik matrisin her elemanina data parametresini atar.
* @param	: struct tipinde matrix ve float tipinde iki boyutlu data parametresini icerir.
*/
void Matrix_FillByData(Matrix & matrix, float ** data) {
	for (int i = 0; i < matrix.rowSize; i++)
	{
		for (int j = 0; j < matrix.columnSize; j++)
		{
			matrix.data[i][j] = data[i][j];
		}
	}
}
/**
* @brief	: Bu fonksiyon iki boyutlu dinamik matrisin her elemanini iki boyutlu olarak ekrana yazdirir.
* @param	: const struct tipinde matrix parametresini icerir.
*/
void Matrix_Display(const Matrix& matrix) {
	cout << "MATRIX: " << matrix.rowSize <<" x "<<matrix.columnSize << endl;
	for (int i = 0; i < matrix.rowSize; i++)
	{
		for (int j = 0; j < matrix.columnSize; j++)
		{
			cout << setw(10)<< left << matrix.data[i][j] << "	";
		}
		cout << endl;
	}
}
/**
* @brief	: Bu fonksiyon iki boyutlu dinamik matrisleri birbiriyle toplar ve result matrixine kaydeder.
* @param	: const struct tipinde iki tane matrix ve struct tipinde result parametrlerini icerir.
*/
void Matrix_Addition(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result) {
	Matrix_Allocate(result, matrix_left.rowSize, matrix_right.columnSize);
	for (int i = 0; i < result.rowSize; i++)
	{
		for (int j = 0; j < result.columnSize; j++)
		{
			result.data[i][j] = matrix_left.data[i][j] + matrix_right.data[i][j];
		}
	}
}
/**
* @brief	: Bu fonksiyon iki boyutlu dinamik matrisleri birbirinden cýkarýr ve result matrixine kaydeder.
* @param	: const struct tipinde iki tane matrix ve struct tipinde result parametrlerini icerir.
*/
void Matrix_Subtraction(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result) {
	Matrix_Allocate(result, matrix_left.rowSize, matrix_right.columnSize);
	for (int i = 0; i < result.rowSize; i++)
	{
		for (int j = 0; j < result.columnSize; j++)
		{
			result.data[i][j] = matrix_left.data[i][j] - matrix_right.data[i][j];
		}
	}
}
/**
* @brief	: Bu fonksiyon iki boyutlu dinamik matrisleri birbiriyle carpar ve result matrixine kaydeder.
* @param	: const struct tipinde iki tane matrix ve struct tipinde result parametrlerini icerir.
*/
void Matrix_Multiplication(const Matrix & matrix_left, const Matrix & matrix_right, Matrix & result) {
	Matrix_Allocate(result, matrix_left.rowSize, matrix_right.columnSize);
	int sum = 0;
	for (int i = 0; i < matrix_left.rowSize; i++)
	{
		for (int j = 0; j < matrix_right.columnSize; j++)
		{
			for (int k = 0; k < matrix_left.columnSize; k++)
				sum += matrix_left.data[i][k] * matrix_right.data[k][j];
			result.data[i][j] = sum;
			sum = 0;
		}
		
	}
}
/**
* @brief	: Bu fonksiyon sabit bir matrixi bir tam sayiyla carpar ve result matrixine kaydeder.
* @param	: const struct tipinde bir matrix, float tipinde scalerValue ve struct tipinde result parametrlerini icerir.
*/
void Matrix_Multiplication(const Matrix & matrix_left, float scalarValue, Matrix & result) {
	Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
	for (int i = 0; i < result.rowSize; i++)
	{
		for (int j = 0; j < result.columnSize; j++)
		{
			result.data[i][j] = matrix_left.data[i][j] * scalarValue;
		}
	}
}
/**
* @brief	: Bu fonksiyon sabit bir matrixi bir tam sayiya boler ve result matrixine kaydeder.
* @param	: const struct tipinde bir matrix, float tipinde scalerValue ve struct tipinde result parametrlerini icerir.
*/
void Matrix_Division(const Matrix & matrix_left, float scalarValue, Matrix & result) {
	Matrix_Allocate(result, matrix_left.rowSize, matrix_left.columnSize);
	for (int i = 0; i < result.rowSize; i++)
	{
		for (int j = 0; j < result.columnSize; j++)
		{
			result.data[i][j] = matrix_left.data[i][j] / scalarValue;
		}
	}
}
void Matrix_Transpose(const Matrix & matrix, Matrix & result)
{
	Matrix_Allocate(result, matrix.columnSize, matrix.rowSize);

	for (int i = 0; i < result.columnSize; i++)
	{
		for (int j = 0; j < result.rowSize; j++)
		{
			result.data[j][i] = matrix.data[i][j];
		}
	}
}