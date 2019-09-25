#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include<fstream>
using namespace std;
int a[3][3];
int row[2] = { 0 };                           //用来存放已知数字的行
int line[2] = { 0 };                          //用来存放已知数字的列
int t=0
int b[2];                                 //用于存放已知数字
const int c[3] = { 1,2,3 };
void input()
{
	FILE* fp1;
	fp1 = fopen("input.txt", "r");

	for (int i = 0; i < 3; i++)                      //读取数据
	{
		for (int j = 0; j < 3; j++)
		{
			fscanf(fp1, "%d", &a[i][j]);
			if (a[i][j] != 0)                    //遇到已知数字，放入b数组�?
			{
				row[t] = i;
				line[t] = j;
				b[t] = a[i][j];
				t++;
			}
		}
	}
}
void search()
{
	int y = 6;
	for (int i = 0; i < 2; i++)
	{

		for (int j = 0; j < 3; j++)
		{
			if (b[i] == c[j])                //遇到相同数字，用6减这个数，最后剩下的就是空缺的这个数
				y = y - c[j];
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[row[i]][line[j]] == 0)           //找出空格，空缺的这个�?
			{
				a[row[i]][line[j]] = y;
			}
		}
	}

}
void hang()
{
	int y = 6;
	for (int i = 0; i < 3; i++)              //从第一行开始遍�?
	{
		int temp = 0;
		for (int j = 0; j < 3; j++)
		{
			if (a[i][j] != 0)
				temp++;
		}
		if (temp == 2)                         //如果遇到已知两个值的，就把剩下那个空填上
		{
			for (int k = 0; k < 3; k++)        //找出未知数，方法和search一�?
			{
				if (a[i][k] != 0)
				{
					y = y - a[i][k];
				}
			}

			for (int f = 0; f < 3; f++)       //把空缺填�?
			{
				if (a[i][f] == 0)
				{
					a[i][f] = y;
				}

			}
			y = 6;

		}
		else
			continue;
	}
}
void lie()
{
	int y = 6;
	for (int i = 0; i < 3; i++)              //从第一列开始遍�?
	{
		int temp = 0;
		for (int j = 0; j < 3; j++)
		{
			if (a[j][i] != 0)
				temp++;
		}
		if (temp == 2)                         //如果遇到已知两个值的，就把剩下那个空填上
		{
			for (int k = 0; k < 3; k++)
			{
				if (a[k][i] != 0)
				{
					y = y - a[k][i];
				}
			}
			for (int f = 0; f < 3; f++)
			{
				if (a[f][i] == 0)
					a[f][i] = y;
			}
		}
		y = 6;
	}
}

void output()
{
	FILE* fp2;
	fp2 = fopen("output.txt", "w");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			fprintf(fp2, "%d ", a[i][j]);
		}
		fprintf(fp2, "\n");
	}
}
int main()
{
	FILE* fp1;
	FILE* fp2;
	fp1 = fopen("input.txt", "r");
	if (fp1 == NULL)
	{
		return -1;
	}
	fp2 = fopen("output.txt", "w");
	if (fp2 == NULL)
	{
		return -1;
	}
	fclose(fp2);
	input();
	search();
	hang();
	lie();
	output();
	return 0;
}