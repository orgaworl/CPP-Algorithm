#pragma once
#include<iostream>
using namespace std;


class matrix
{
	friend matrix operator+(matrix& p_1, matrix& p_2);

private:

	double** m_matrix = NULL;
	int m_row = 0;
	int m_column = 0;

public:
	matrix();
	matrix(double** matrix, int m, int n);
	matrix(int m, int n);
	~matrix();

	//重载运算符
	matrix& operator = (matrix& p_2);

	

	//矩阵操作
	matrix transpose();


	//函数
	bool setValue(int i, int j, int value);
	void show();
	static void show(matrix& p);



};

matrix operator+(matrix& p_1, matrix& p_2);

/*matrix operator-(matrix p)
{

}
matrix operator*(matrix p)
{

}*/
void test_matrix();

