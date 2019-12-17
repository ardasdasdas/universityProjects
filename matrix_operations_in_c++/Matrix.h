#pragma once
struct Matrix {
	int rowSize = -1;
	int columnSize = -1;
	float** data = 0;
};
void Matrix_Allocate(Matrix& matrix, int rowSize, int columnSize);
void Matrix_Free(Matrix& matrix);
void Matrix_FillByValue(Matrix& matrix, float value);
void Matrix_FillByData(Matrix& matrix, float** data);
void Matrix_Display(const Matrix& matrix);
void Matrix_Addition(const Matrix& matrix_left, const Matrix& matrix_right, Matrix& result);
void Matrix_Subtraction(const Matrix& matrix_left, const Matrix& matrix_right, Matrix& result);
void Matrix_Multiplication(const Matrix& matrix_left, const Matrix& matrix_right, Matrix& result);
void Matrix_Multiplication(const Matrix& matrix_left, float scalarValue, Matrix& result);
void Matrix_Division(const Matrix& matrix_left, float scalarValue, Matrix& result);
void Matrix_Transpose(const Matrix & matrix, Matrix & result);