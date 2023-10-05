#pragma once
#include"matrix.h"
#include<iostream>
using namespace std;

matrix::matrix()
{
	m_column = 0;
	m_row = 0;
	m_matrix = NULL;
}
matrix::matrix(double** matrix, int m, int n)
{


	m_matrix = new double* [m];
	for (int i = 0; i < m; i++)
	{
		m_matrix[i] = new double[n];
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			this->m_matrix[i][j] = matrix[i][j];
			//cout << this->m_matrix[i][j]<<" ";
		}
		cout << endl;
	}



	m_row = m;
	m_column = n;



}
matrix::matrix(int m, int n)
{

	m_matrix = new double* [m];
	for (int i = 0; i < m; i++)
	{
		m_matrix[i] = new double[n] {0};
	}


	m_row = m;
	m_column = n;



}

matrix::~matrix()
{
	/*if (m_matrix!=NULL)
	{
		delete m_matrix;
		m_matrix = NULL;
	}*/

	m_row = 0;
	m_column = 0;
	cout << "析构一次" << endl;

}


matrix& matrix::operator = (matrix& p_2)
{

	if (this->m_matrix != NULL)
	{
		delete this->m_matrix;
		this->m_matrix = NULL;
	}
	if (p_2.m_matrix != NULL)
	{
		this->m_row = p_2.m_row;
		this->m_column = p_2.m_column;


		this->m_matrix = new double* [p_2.m_row];
		for (int i = 0; i < p_2.m_row; i++)
		{
			m_matrix[i] = new double[p_2.m_column];
		}


		for (int i = 0; i < p_2.m_row; i++)
		{
			for (int j = 0; j < p_2.m_column; j++)
			{
				this->m_matrix[i][j] = p_2.m_matrix[i][j];

			}

		}





	}

	return*this;



}


bool matrix::setValue(int i, int j, int value)
{
	if (i >= this->m_row || i < 0 || j < 0 || j >= this->m_column)
	{
		return 0;
	}
	this->m_matrix[i][j] = value;
	return 1;
}




void matrix::show()
{
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_column; j++)
		{

			cout << this->m_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void matrix::show(matrix& p)
{
	for (int i = 0; i < p.m_row; i++)
	{
		for (int j = 0; j < p.m_column; j++)
		{

			cout << p.m_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

matrix matrix::transpose()
{
	matrix temp(m_column, m_row);

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_column; j++)
		{
			temp.m_matrix[j][i] = this->m_matrix[i][j];
			//cout << temp.m_matrix[i][j] << " ";
		}
		cout << endl;
	}


	return temp;




}

matrix operator+(matrix& p_1, matrix& p_2)
{

	if (p_1.m_column == p_2.m_column && p_1.m_row == p_2.m_row)
	{


		matrix temp(p_2.m_row, p_2.m_column);

		for (int i = 0; i < p_2.m_row; i++)
		{
			for (int j = 0; j < p_2.m_column; j++)
			{
				temp.m_matrix[i][j] = p_1.m_matrix[i][j] + p_2.m_matrix[i][j];
				//cout << this->m_matrix[i][j] << " ";
			}
			cout << endl;
		}



		return temp;
	}
	else
	{
		cout << "无法+" << endl;
	}




}

/*matrix operator-(matrix p)
{
cout<<endl;
for(int i=0;i<=10;i++)
{

}

}
matrix operator*(matrix p)
{

}*/
void test_matrix()
{

	double arr[2][2] =
	{
		{1,2},
		{3,4}

	};
	double arr_1[2] = { 1,2 };
	double arr_2[2] = { 3,4 };
	double* p[2] = { arr_1,arr_2 };




	matrix M1(p, 2, 2);
	matrix::show(M1);



	matrix M2(3, 4);
	M2 = M1;//赋值号重载
	M2.show();
	(M1 + M2).show();//加号重载


	matrix M3 = M1 + M2;//加号&赋值号
	//复制构造


	//M3 = M1 + M2;


	int b = 0;
	int& a = b;

	M3.show();
	return;
}
