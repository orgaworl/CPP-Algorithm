






template<typename T>
bool showArr(T* arr, int lengthArr)
{
	for (int i = 0; i < lengthArr; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	return 1;
}
void Ex_12()
{
	const int MAXSIZE = 1000;
	clock_t tStart, tFinish;
	float tElapseTime;


	//1��ʼ��˳�����飺
	int record[MAXSIZE];
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = i;
	}



	tStart = clock();
	sortShell(record, MAXSIZE);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "���ĵ�ʱ�䣬����Ϊ�� " << tElapseTime << endl;
	//showArr(record, MAXSIZE);

	//2��ʼ���������飺

	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = MAXSIZE - 1 - i;
	}



	tStart = clock();
	sortShell(record, MAXSIZE);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "���ĵ�ʱ�䣬����Ϊ�� " << tElapseTime << endl;
	//showArr(record, MAXSIZE);


	//3��ʼ��������飺

	memset(record, 0, MAXSIZE * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = rand() % MAXSIZE;
	}



	tStart = clock();
	sortShell(record, MAXSIZE);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "���ĵ�ʱ�䣬����Ϊ�� " << tElapseTime << endl;
	//showArr(record, MAXSIZE);















}