#ifndef SKILL_QUERY_H_
#define SKILL_QUERY_H_
#include <iostream>
#include <vector>
using std::vector;
using namespace std;

//��ʵ���õ��Ƿ��ε�˼�룬�Ӻ��ʵ���㿪ʼ�����ظ��Ĵ����ص�����),ѡ�����»����Ͻ�
class SolutionSkillQuery
{
public:
	//���½ǿ�ʼ
	bool SkillQuery(vector<vector<int>> arr,int findNum)
	{
		bool res = false;
		int i;
		int j;
		int height = arr.size();
		int width = arr[0].size();
		//����һ��
		//i = height -1: 0, j = 0:width -1
		//for (i = height-1; i >=0; i--)
		//{
		//	for (j = 0; j < width; j++)
		//	{
		//		//findNum < arr[i][j] �����ƶ� i--
		//		//findNum > arr[i][j] �����ƶ� j++
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
		//��������
		//i = height -1:0;
		//j = 0: width - 1;
		//
		for(int i = height - 1, j = 0; (i >=0 && i < height) && (j >= 0 && j < width); )
		{
			if (findNum == arr[i][j])
			{
				cout << "find num " << findNum << endl;
				res = true;
				break;//������ѭ��
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
	//���ڿ����ص�����
	bool SkillQueryUpLeft(vector<vector<int>> arr, int target)
	{
		bool res = false;
		int row = arr.size();
		int col = arr[0].size();

		//target > arr[i][j] i++ ȷ��i�� �ٲ���j
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

		//������˼��ͷ���˼����ͬ
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