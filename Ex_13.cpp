



void Ex_13_T1()
{

	clock_t tStart, tFinish;
	float tElapseTime;





	cout << "随机取轴值" << endl << endl;

	//顺序数组
	int* record = new int[MAXSIZE];
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = i;
	}


	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;

	//cout << "原序列 "; showArr(record, MAXSIZE);
	//cout << "快排"; showArr(record,MAXSIZE); cout << endl;
	cout << "顺序数组消耗时间秒数为： " << tElapseTime << endl;



	//初始化逆序数组：
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = MAXSIZE - 1 - i;
	}

	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	//cout << "原序列 "; showArr(record, MAXSIZE);
	//cout << "快排"; showArr(record, MAXSIZE); cout << endl;
	cout << "逆序数组消耗时间秒数为： " << tElapseTime << endl;



	//初始化随机数组：
	memset(record, 0, MAXSIZE * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = rand() % MAXSIZE;
	}



	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	//cout << "原序列 "; showArr(record, MAXSIZE);
	//cout << "快排"; showArr(record, MAXSIZE); cout << endl;
	cout << "随机数组消耗时间秒数为： " << tElapseTime << endl;









	cout << endl << endl << "取最左端做轴值" << endl << endl;

	//顺序数组
	record[MAXSIZE];
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = i;
	}

	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1, 0);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "顺序数组消耗时间秒数为： " << tElapseTime << endl;




	//初始化逆序数组：
	memset(record, 0, MAXSIZE * sizeof(int));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = MAXSIZE - 1 - i;
	}


	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1, 0);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "逆序数组消耗时间秒数为： " << tElapseTime << endl;



	//初始化随机数组：



	memset(record, 0, MAXSIZE * sizeof(int));
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXSIZE; i++) {
		record[i] = rand() % MAXSIZE;
	}



	tStart = clock();
	sortQuick(record, 0, MAXSIZE - 1, 0);
	tFinish = clock();
	tElapseTime = (float)(tFinish - tStart) / CLOCKS_PER_SEC;
	cout << "随机数组消耗时间秒数为： " << tElapseTime << endl;


	cout << endl;






}

template<typename T>
int search_kthBig(T* arr, unsigned int n, unsigned int k)
{
	//时间消耗: n+   (1+2+3+k)+k(n-k)    +2*n   =(3+k)n+(1-k)*k/2
	//         遍历一遍数组,查找链表中位置,插入
	if (n < k)
	{
		return -1;
	}

	list<int> linkList;//保存的是数组中元素的下标,而非数据
	int poiArr = 0;

	linkList.push_front(poiArr++);
	for (poiArr; poiArr <= n - 1; poiArr++)
	{
		int curSzie = linkList.size();
		list<int>::iterator it = linkList.begin();
		list<int>::iterator itNext = (++linkList.begin());


		if (arr[poiArr] >= arr[linkList.front()])
		{//不小于最大
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
		if (itNext == linkList.end())//it即为链表最后一个
		{//比最小的小
			if (curSzie < k)
			{
				linkList.push_back(poiArr);
			}
			else if (curSzie = k)
			{
				//不做操作
			}
			else
			{
				cout << "error" << endl;
			}
		}
		else if (arr[*it] >= arr[poiArr] && arr[poiArr] >= arr[*itNext])
		{//在最大最小之间
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
			return *it;//返回的是下标,不是值
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

	cout << "原式为";
	showArr(record, 10);
	cout << endl << "第" << 5 << "大的数是 ";
	cout << record[search_kthBig(record, 10, 5)];
	cout << endl << endl << endl;








}
