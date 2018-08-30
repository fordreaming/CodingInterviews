#ifndef SKILL_QUERY_H_
#define SKILL_QUERY_H_
#include <iostream>
#include <vector>
using std::vector;
using namespace std;

//其实采用的是分治的思想，从合适的起点开始（不重复的处理重叠区域),选择左下或右上角
class SolutionSkillQuery
{
public:
	//左下角开始
	bool SkillQuery(vector<vector<int>> arr,int findNum)
	{
		bool res = false;
		int i;
		int j;
		int height = arr.size();
		int width = arr[0].size();
		//方法一：
		//i = height -1: 0, j = 0:width -1
		//for (i = height-1; i >=0; i--)
		//{
		//	for (j = 0; j < width; j++)
		//	{
		//		//findNum < arr[i][j] 向上移动 i--
		//		//findNum > arr[i][j] 向右移动 j++
		//		//findNum == arr[i][j] return
		//		if (findNum == arr[i][j])
		//		{
		//			cout << "find num " << findNum << endl;
		//			return true;
		//		}
		//		else if (findNum < arr[i][j])
		//		{
		//			break;
		//		}
		//		else
		//		{

		//		}
		//	}
		//}
		//方法二：
		//i = height -1:0;
		//j = 0: width - 1;
		//
		for(int i = height - 1, j = 0; (i >=0 && i < height) && (j >= 0 && j < width); )
		{
			if (findNum == arr[i][j])
			{
				cout << "find num " << findNum << endl;
				res = true;
				break;//跳出该循环
			}
			else if (findNum < arr[i][j])
			{
				i--;
			}
			else
			{
				j++;
			}
		}
		return res;
	}

	bool SkillQueryUpRight(vector<vector<int>> arr, int target)
	{
		int res = false;
		//row
		//col
		int row = arr.size();
		int col = arr[0].size();
		int i;
		int j;
		//row:i = 0:row-1; col:col-1:0
		for (i = 0, j = col -1; (i>=0 && i < row)&&(j<col && j >=0); )
		{
			//target>arr[i][j] i++
			//target<arr[i][j] j--
			if (target == arr[i][j])
			{
				res = true;
				cout << "find" << endl;
				break;
			}
			else if (target > arr[i][j])
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		return false;
	}
	//存在可能重叠区域
	bool SkillQueryUpLeft(vector<vector<int>> arr, int target)
	{
		bool res = false;
		int row = arr.size();
		int col = arr[0].size();

		//target > arr[i][j] i++ 确定i后， 再查找j
		int row1;
		for (int i = 0; i < row; )
		{
			if (target > arr[i][0])
			{
				i++;
			}
			else
			{
				row1 = i;
				break;
			}
		}

		//后续的思想和分治思想相同
		for (int j = 0; j < col; j++)
		{
			if ()
			{
			}
		}



		return res;
	}
};
#endif