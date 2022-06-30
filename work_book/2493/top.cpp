//시간 복잡도 O(NlgN) 
//1. 맵을 만들어서 중요도와 숫자를 입력하고 그것들을 찾는다.
//2. 

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int check(stack<int> top, stack<int> comp,int num)
{
	while (!comp.empty())
	{
		if (top.top() <comp.top())
			return(num);
		else
		{
			num--;
			comp.pop();
		}
	}
	return (num);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	stack<int> top;
	stack<int> comp;
	int n;
	cin >> n;
	int input;
	int *result = new int[n];
	for (int i = 0; i < n ; i++)
	{
		cin >> input;
		top.push(input);
		comp.push(input);
	}
	int now =n -1;
	while (!top.empty())
	{
		result[now] = check(top,comp,now +1);
		top.pop();
		comp.pop();
		now--;
	}
	for (int i = 0; i < n; i++)
	{
		cout <<result[i] <<' ';
	}
}
