

class unionFind
{
private:
	int* poiArr;
	int length;//不计入0位置的长度
public:
	unionFind(int length);

	bool union_(int from, int to);
	int find(int toFind);
	int findAll();
	int getValue(int ordinal);
	void showArr();
};
void Ex_09_rewrite();