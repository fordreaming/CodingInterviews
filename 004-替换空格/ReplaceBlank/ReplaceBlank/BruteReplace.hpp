#ifndef BRUTE_REPLACEMENT_H_
#define BRUTE_REPLACEMENT_H_
#include <string>

using std::string;

class BruteReplace
{
public:
	//create one temp string 
	bool ReplaceBlank(string &str)
	{
		string temp;
		int size = str.size();
		int blankNum = 0;
		//计算空格数
		for (int i = 0; i < size; i++)
		{
			if(str[i] == ' ')
			{
				blankNum++;
			}
		}
		int totalSize = size + 2*blankNum;
		temp.resize(totalSize);
		int j;
		for (int i = 0, j = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				temp[j++] = '%';
				temp[j++]  = '2';
				temp[j++]  = '0';
			}
			else
			{
				temp[j++] = str[i];
			}
		}
		//strcpy(str, temp);
		str.resize(temp.size());
		memcpy(&str[0], &temp[0], temp.size());
		return true;
	}

	//in place brute
	
	void replaceSpace(char *str, int length)
	{
		int len = length;
		int i = length - 1;
		for (i; i >=0 ;i--)
		{
			//replace
			if (str[i] == ' ')
			{
				int k = i;//记录空格的位置
				len = len +2;
				int j;
				//后移两个空格

				//后移元素:k:len-3:i+1;
				//j:len-1:i+3
				for (j = len - 1; j > k+2 ; j--)
				{
					str[j] = str[j-2];
				}
				str[i+2] = '0';
				str[i+1] = '2';
				str[i] = '%';
			}
			//copy
		}
		str[len] = '\0';
	}

	//统计空格的个数
	void replaceSpaceByCal(char *str,int length)
	{
		//统计空格的个数
		int spaceNum = 0;
		int i;
		for (i = 0; i < length; i++)
		{
			if (str[i] == ' ')
			{
				spaceNum++;
			}
		}

		//根据空格的个数计算修改字符串后字符串的总长度
		int len = length + 2*spaceNum;

		//
		int k = len -1;
		for (int j = length -1; j >=0; j--)
		{
			if (str[j] == ' ')
			{
				str[k--] = '0';
				str[k--] = '2';
				str[k--] = '%';
			}
			else
			{
				str[k--] = str[j];
			}
		}
		str[len] = '\0';
	}
};



#endif