#include <iostream>
#include <vector>
#include "BruteQuery.hpp"
#include "skillQuery.hpp"

using namespace std;

int main()
{
	//
	int a1[] = { 1, 2, 8, 9, };
	vector<vector<int>> array;
	array.push_back(vector<int>(a1, a1 + 4));
	//
	int arr[3][4] = {{1, 2, 8, 9}, { 2, 4, 9, 12}, { 4, 7, 10, 13}};
	vector<vector<int>> vecArr(3);
	for (int i = 0; i < 3; i++)
	{
		vecArr[i].resize(4);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//¸³Öµ
			vecArr[i][j] = arr[i][j];
		}
	}
		Solution solution;
	//if (solution.BruteQuery(arr, 4, 4, 12))
	//{
	//	cout << "find num: " << endl;
	//}	

	SolutionSkillQuery skillQuerySolution;
	//skillQuerySolution.SkillQuery(vecArr, 10);
	skillQuerySolution.SkillQueryUpRight(vecArr, 11);
	return 0;
}