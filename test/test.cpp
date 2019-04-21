// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
	int n;
	cin >> n;

	int i = 2;
	while (i<n)
	{
		int s = n % i;
		if (s == 0)
		{
			cout << "1" << "*"<< i;
			n = n / i;
			break;
		}
		else
		{
			i++;
		}
		if (n==i)
		{
			cout <<"*"<< i;
		}
	}

	
	system("pause");
}
	
	
	



