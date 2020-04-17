#include<iostream>
#define MAXN 100001
using namespace std;

int N;
int input[MAXN];

extern int max(int a, int b);
	
int solve(int n)
{
	if (n == 0)return input[n];
	return max(solve(n - 1) + input[n], input[n]);
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	int answer = 0;

	for (int i = 0; i < N; i++) {
		answer = max(solve(i), answer);
	}

	cout << answer;
	return 0;
}