#include<iostream>
using namespace std;

float infinite = 99;

template<typename T>

class graphMat
{
private:
	
	//T* dateVertex;
	int numVertex;//顶点数
	float** matrix;
	float** matrixCost;
public:
	
	graphMat(int length);//默认全零
	graphMat(int numVertex,float**matrix, float** matrixCost=NULL);//默认全零
	~graphMat();
	bool setValue(int i, int j,int value);
	bool setEdge(int i, int j,float weight);
	bool removeEdge();
	float** getMatrix();
	float** getMatrixCost();
	int getNumVertex();
	float** getTransitiveMatrix(int **matrix,int numVertex);
	float getShorDist(int start, int finish);
	bool showMatrix(float** matrix,int numVertex);
	
	void getShorDistWithShorCost(int start, int finish);
	int getAllShorDist();
	
	
	
	
};


template<typename T>
graphMat<T>::graphMat(int numVertex)
{
	//date = new T[length];
	this->numVertex = numVertex;
	matrix = new float* [numVertex];
	////
	matrixCost = new float* [numVertex];

	for (int i = 0; i <= numVertex - 1; i++)
	{
		matrix[i] = new float[numVertex];
		matrixCost[i] = new float[numVertex];
		for (int j=0;j<=numVertex;j++)
		{
			matrix[i][j] = infinite;
			matrixCost[i][j] = infinite;
		}
	}
	
}

template<typename T>
graphMat<T>::graphMat(int numVertex, float** matrix,float**matrixCost)
{
	
	this->numVertex = numVertex;
	this->matrix = matrix;
	this->matrixCost = matrixCost;
	
}

template<typename T>
graphMat<T>::~graphMat()
{
	delete this->matrix;
	this->matrix = NULL;
	numVertex = 0;
}
template<typename T>
bool graphMat<T>::setValue(int i, int j, int value)
{
	if (i >= this->length || i < 0 || j < 0 || j >= this->length)
	{
		return 0;
	}
	this->matrix[i][j] = value;
	return 1;
}
template<typename T>
float** graphMat<T>::getMatrix()
{
	return this->matrix;
}

template<typename T>
float** graphMat<T>::getMatrixCost()
{
	return this->matrixCost;
}

template<typename T>
bool graphMat<T>::setEdge(int i, int j,float weight)
{
	this->matrix[i][j] = weight;
	return 1;
}




//////////////


template<typename T>
int graphMat<T>::getNumVertex()
{
	return this->numVertex;
}
template<typename T>
bool graphMat<T>::showMatrix(float** matrix, int numVertex)
{
	if (matrix==NULL||numVertex==0)
	{
		return 0;
	}

	for (int i=0;i<=numVertex-1;i++)
	{
		for (int j = 0; j <= numVertex - 1; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	return 1;

}





