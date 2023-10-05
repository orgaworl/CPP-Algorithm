#include"arrStack.hpp"
using namespace std;


const int arrStack_length = 30;
void getInput(arrStack<int>& number, arrStack<char>& symbol)
{
	//���ֽ��տ�ʼ
	int temp_n = -1;
	char temp_s = ' ';
	while (((int)cin.peek() >= 48 && (int)cin.peek() <= 57))
	{
		cin >> temp_n;
		number.push(temp_n);

		while (cin.peek() == ' ')
		{
			cin.get();
		}

	}
	//���ֽ��ս���

	//���Ž��տ�ʼ
	arrStack<char> tempsymbol(arrStack_length);
	while (cin.peek() != '#')
	{
		//��������˳����ջ(����)
		temp_s = cin.get();
		tempsymbol.push(temp_s);
		while (cin.peek() == ' ')
		{
			cin.get();
		}

	}
	cin.get(); cin.get();
	int times = tempsymbol.getCurSize();
	//���Ž��ս���


	//������˳����ջ(����)
	for (int i = 0; i < times; i++)
	{

		temp_s = tempsymbol.getTop();
		tempsymbol.pop();
		symbol.push(temp_s);
	}
}



void processDate(arrStack<int>& number, arrStack<char>& symbol)
{
	while (number.getCurSize() != 1)
	{
		int result = 1;

		int rightNum = number.getTop();
		number.pop();
		int leftNum = number.getTop();
		number.pop();
		char curSymbol = symbol.getTop();
		symbol.pop();

		switch (curSymbol)
		{
		case '+':
			result = leftNum + rightNum;
			break;


		case '-':
			result = leftNum - rightNum;
			break;
		case '*':
			result = leftNum * rightNum;
			break;
		case '/':
			result = leftNum / rightNum;
			break;
		case '%':
			result = leftNum % rightNum;
			break;
		case'^':

			for (int i = 0; i <= rightNum - 1; i++)
			{
				result *= leftNum;
			}
			break;

		}
		number.push(result);


	}

	number.show();
	cout << endl;


}
void third_experiment()
{
	arrStack<int> number(arrStack_length);
	arrStack<char> symbol(arrStack_length);

	getInput(number, symbol);
	processDate(number, symbol);
}
