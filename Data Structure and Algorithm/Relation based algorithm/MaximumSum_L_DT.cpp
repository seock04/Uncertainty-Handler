#include<iostream>
#define MAXN 100001
using namespace std;

extern int max(int a, int b);

int N;
int input[MAXN];

int DT[MAXN];
	
int solve(int n)
{
	if (DT[n] != 0) return DT[n];

	if (n == 0)return (DT[n] = input[n]);
	return (DT[n] = max(solve(n - 1) + input[n], input[n]));
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