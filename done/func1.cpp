#include<iostream>

using namespace std;
int func1(int N)
{
	int result = 0;
	for(int i =1; i <=N; i++)
	{
		if (i % 3==0 || i % 5 == 0)
			result+=i;
	}
	return (result);
}

int func2(int arr[],int length)
{
	for (int i = 0 ; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (arr[i] + arr[j] == 100)
				return (1);
		}
	}
	return (0);
}

int func3(int N)
{
	for (int i = 1; i*i <=N; i++)
	{
		if (i * i ==N)
			return (1);
	}
	return (0);
}

int func4(int N)
{
	int result = 1;
	while (result<=N)
	{
		result*=2;
	}
	return (result/2);
}

int main()
{
	cout << func1(16)<<"\n";
	cout << func1(34567) << "\n";
	cout << func1(27638) << "\n";

	int arr1[3] = {1,52,48};
	int arr2[2] = {50,42};
	int arr3[4] = {4,13,63,87};

	cout << func2(arr1,3)<<"\n";
	cout << func2(arr2,2) << "\n";
	cout << func2(arr3,4) << "\n";
	cout << "-----------------------------"<<"\n";
	cout << func3(9)<<"\n";
	cout << func3(693953651) << "\n";
	cout << func3(756580036) << "\n";
	cout << "-----------------------------"<<"\n";
	cout << func4(5)<<"\n";
	cout << func4(97615282) << "\n";
	cout << func4(1024) << "\n";
}
