



void Ex_13_T1()
{

	clock_t tStart, tFinish;
	float tElapseTime;





	cout << "���ȡ��ֵ" << endl << endl;

	//˳������
	int* record = new int[MAXSIZE];
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = i;
	}


	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;

	//cout << "ԭ���� "; showArr(record, MAXSIZE);
	//cout << "����"; showArr(record,MAXSIZE); cout << endl;
	cout << "˳����������ʱ������Ϊ�� " << tElapseTime << endl;



	//��ʼ���������飺
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = MAXSIZE - 1 - i;
	}

	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	//cout << "ԭ���� "; showArr(record, MAXSIZE);
	//cout << "����"; showArr(record, MAXSIZE); cout << endl;
	cout << "������������ʱ������Ϊ�� " << tElapseTime << endl;



	//��ʼ��������飺
	memset(record, 0, MAXSIZE * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = rand() % MAXSIZE;
	}



	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	//cout << "ԭ���� "; showArr(record, MAXSIZE);
	//cout << "����"; showArr(record, MAXSIZE); cout << endl;
	cout << "�����������ʱ������Ϊ�� " << tElapseTime << endl;









	cout << endl << endl << "ȡ���������ֵ" << endl << endl;

	//˳������
	record[MAXSIZE];
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = i;
	}

	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1, 0);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "˳����������ʱ������Ϊ�� " << tElapseTime << endl;




	//��ʼ���������飺
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = MAXSIZE - 1 - i;
	}


	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1, 0);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "������������ʱ������Ϊ�� " << tElapseTime << endl;



	//��ʼ��������飺



	memset(record, 0, MAXSIZE * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = rand() % MAXSIZE;
	}



	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1, 0);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "�����������ʱ������Ϊ�� " << tElapseTime << endl;


	cout << endl;






}

template<typename T>
int search_kthBig(T* arr, unsigned int n, unsigned int k)
{
	//ʱ������: n+   (1+2+3+k)+k(n-k)    +2*n   =(3+k)n+(1-k)*k/2
	//         ����һ������,����������λ��,����
	if (n < k)
	{
		return -1;
	}

	list<int> linkList;//�������������Ԫ�ص��±�,��������
	int poiArr = 0;

	linkList.push_front(poiArr++);
	for (poiArr; poiArr <= n - 1; poiArr++)
	{
		int curSzie = linkList.size();
		list<int>::iterator it = linkList.begin();
		list<int>::iterator itNext = (++linkList.begin());


		if (arr[poiArr] >= arr[linkList.front()])
		{//��С�����
			linkList.push_front(poiArr);
			if (linkList.size() == 6)
			{
				linkList.pop_back();
			}

			continue;
		}
		while (itNext != linkList.end() && !(arr[*it] >= arr[poiArr] && arr[poiArr] >= arr[*itNext]))
		{
			it++;
			itNext++;
		}
		if (itNext == linkList.end())//it��Ϊ�������һ��
		{//����С��С
			if (curSzie < k)
			{
				linkList.push_back(poiArr);
			}
			else if (curSzie = k)
			{
				//��������
			}
			else
			{
				cout << "error" << endl;
			}
		}
		else if (arr[*it] >= arr[poiArr] && arr[poiArr] >= arr[*itNext])
		{//�������С֮��
			linkList.insert(++it, poiArr);
			if (linkList.size() == 6)
			{
				linkList.pop_back();
			}
		}
	}
	list<int>::iterator it = linkList.begin();
	for (int i = 0; i < linkList.size(); i++)
	{

		if (i == k - 1)
		{
			return *it;//���ص����±�,����ֵ
		}
		it++;
	}

}

void Ex_13_T2()
{
	int record[10] = { 9,4,1,3,3,5,4,2,5,1 };
	/*memset(record, 0, MAXSIZE * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = rand() % MAXSIZE;
	}*/

	cout << "ԭʽΪ";
	showArr(record, 10);
	cout << endl << "��" << 5 << "������� ";
	cout << record[search_kthBig(record, 10, 5)];
	cout << endl << endl << endl;








}
