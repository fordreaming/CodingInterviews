#ifndef BRUTE_QUERY_H_
#define BRUTE_QUERY_H_

class Solution
{
public:
	bool BruteQuery(int (*a)[4], int width, int height, int findNum)
	{
		bool res = false;
		int i;
		int j;
		for (i = 0; i < height && !res; i++)
		{
			for (j = 0; j < width; j++)
			{
				if (a[i][j] == findNum)
				{
					res = true;
					break;
				}
			}
		}
		return res;
	}

};

#endif