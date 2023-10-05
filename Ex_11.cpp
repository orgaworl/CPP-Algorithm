





struct coordinate
{
	int x;
	int y;
};
void Ex_11_T1()
{


	int numVertex = 0;
	cin >> numVertex;

	//初始化邻接矩阵
	float** matrix = new float* [numVertex];
	for (int i = 0; i <= numVertex - 1; i++)
	{
		matrix[i] = new float[numVertex];
		for (int j = 0; j <= numVertex - 1; j++)
		{
			matrix[i][j] = infinite;
		}
	}


	//坐标数组,用以求权
	coordinate* coorArr = new coordinate[numVertex];
	int x; int y;
	for (int i = 0; i <= numVertex - 1; i++)
	{
		cin >> x; cin >> y;
		coorArr[i].x = x; coorArr[i].y = y;
	}



	//求出所有边的权重
	int numEdge = 0; cin >> numEdge; int m; int n;

	for (int i = 0; i <= numEdge - 1; i++)
	{
		cin >> m; cin >> n;
		coordinate point1 = coorArr[m - 1];
		coordinate point2 = coorArr[n - 1];
		float xDiff = (float)point1.x - point2.x;
		float yDiff = (float)point1.y - point2.y;
		float distance = pow((pow(xDiff, 2) + pow(yDiff, 2)), 0.5);


		int tempD = (int)(distance * 1000);
		tempD = (tempD % 10 >= 5) ? tempD + 10 - tempD % 10 : tempD - tempD % 10;
		distance = ((float)tempD) / 1000;

		matrix[m - 1][n - 1] = distance;
	}

	//计算最短路径
	graphMat<int>graph(numVertex, matrix);


	int start; int end; cin >> start; cin >> end;
	cout << "最短距离 " << graph.getShorDist(start - 1, end - 1) << endl;



}


float** creatMatrix(int numVertex)
{
	float** matrix = new float* [numVertex];
	for (int i = 0; i <= numVertex - 1; i++)
	{
		matrix[i] = new float[numVertex];
		for (int j = 0; j <= numVertex - 1; j++)
		{
			matrix[i][j] = infinite;
		}
	}
	return matrix;
}
void Ex_11_T2()
{

	int numVertex = 1; int numEdge = 1;
	while (1)
	{
		cout << endl;
		cin >> numVertex; cin >> numEdge;
		if (numVertex == 0 && numEdge == 0)
		{
			break;
		}
		float** matrixWeight = creatMatrix(numVertex);
		float** matrixCost = creatMatrix(numVertex);

		int a = -1; int b = -1; float d = infinite; float p = infinite;
		for (int i = 0; i <= numEdge - 1; i++)
		{
			cin >> a; cin >> b; cin >> d; cin >> p;
			matrixWeight[a - 1][b - 1] = d;
			matrixWeight[b - 1][a - 1] = d;
			matrixCost[a - 1][b - 1] = p;
			matrixCost[b - 1][a - 1] = p;

		}
		int start = -1; int finish = -1;
		cin >> start; cin >> finish;

		graphMat<void>graph(numVertex, matrixWeight, matrixCost);
		//graph.showMatrix(graph.getMatrix(), graph.getNumVertex());
		cout << endl << endl;
		//graph.showMatrix(graph.getMatrixCost(), graph.getNumVertex());

		graph.getShorDistWithShorCost(start - 1, finish - 1);
	}



}