#include<iostream>
#include"string.h"
using namespace std;


int E5T1()
{
	string s;//主串
	string t;//模式串
	cin >> s;
	cin >> t;
	int sLength = s.length();//主串长
	int tLength = t.length();//模式串长
	
	if (s.length()< t.length())
	{
		cout << "error input" << endl;
		return -1;
	}





	//*begin计算next数组
	int* next = new int[tLength];
	int j = 0;    //j为模式串指针
	int k = 0;    //k为最大相同前后缀
	next[0] = 0;

	if (tLength >=2)
	{
		for (j = 1; j <=(tLength - 1); ++j)
		{

			


			//不等时,循环直至k==0或相等
			while (k > 0 && t[j] != t[k])
				k = next[k - 1];         
			
			//相等时,简单令k++
			if (t[j] == t[k])
			{
				k++;
			}
			next[j] = k;
			//0   0 0 0 0 1 1 2 3 1


		}
	}
	
	for (int i=0;i<=tLength-1;i++)
	{
		cout << next[i] << ' ';
	}
	cout << '\n';




	//*begin进行比较
	int i = 0;
	 j = 0;
	
	while (1)
	{
		if ((tLength + i + 1) == sLength)
		{
			//过程中模式串超出最大范围,可直接判定不存在
			return -1;
		}




		int mark = j + i;
		while (t[j] == s[i]&&t[j]!='\0'&&s[i]!='\0')
		{
			i++;
			j++;
		}

		
		if (j== tLength)
		{
			//全部符合
			return (i- tLength);
		}
		else
		{
			//遇到不同
			if (j==0)
			{
				j = next[0];
			}
			else
			{
				j = next[j - 1];
			}
			

			
		}
		   
		if (mark == j + i)
		{
			i++;
			j = 0;
		}
	
		



	}








}












