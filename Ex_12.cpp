






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


	//1初始化顺序数组：
	int record[MAXSIZE];
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = i;
	}



	tStart = clock();
	sortShell(record, MAXSIZE);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "消耗的时间，秒数为： " << tElapseTime << endl;
	//showArr(record, MAXSIZE);

	//2初始化逆序数组：

	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = MAXSIZE - 1 - i;
	}



	tStart = clock();
	sortShell(record, MAXSIZE);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "消耗的时间，秒数为： " << tElapseTime << endl;
	//showArr(record, MAXSIZE);


	//3初始化随机数组：

	memset(record, 0, MAXSIZE * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = rand() % MAXSIZE;
	}



	tStart = clock();
	sortShell(record, MAXSIZE);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "消耗的时间，秒数为： " << tElapseTime << endl;
	//showArr(record, MAXSIZE);















}