#include<iostream>
#include"string.h"
using namespace std;


int E5T1()
{
	string s;//����
	string t;//ģʽ��
	cin >> s;
	cin >> t;
	int sLength = s.length();//������
	int tLength = t.length();//ģʽ����
	
	if (s.length()< t.length())
	{
		cout << "error input" << endl;
		return -1;
	}





	//*begin����next����
	int* next = new int[tLength];
	int j = 0;    //jΪģʽ��ָ��
	int k = 0;    //kΪ�����ͬǰ��׺
	next[0] = 0;

	if (tLength >=2)
	{
		for (j = 1; j <=(tLength - 1); ++j)
		{

			


			//����ʱ,ѭ��ֱ��k==0�����
			while (k > 0 && t[j] != t[k])
				k = next[k - 1];         
			
			//���ʱ,����k++
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




	//*begin���бȽ�
	int i = 0;
	 j = 0;
	
	while (1)
	{
		if ((tLength + i + 1) == sLength)
		{
			//������ģʽ���������Χ,��ֱ���ж�������
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
			//ȫ������
			return (i- tLength);
		}
		else
		{
			//������ͬ
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












