#include <iostream>
using namespace std;
#define MAX 81

int S[MAX];
int N;
int end_logic;

bool IsSame(int a, int b)
{
	int i;
	for (i = a; i < b; i++) {
		if (S[i] != S[i + b - a]) break;
	}
	return (a == b) ? false : i == b;
}

bool IsGood(int len)
{
	for (int i = 1; i < len/2; i++) {
		for (int j = 0; j < len - i; j++) {
			if (IsSame(j, j + i)) 
				return false;
		}
	}
	return true;
}

void solve(int n)
{
	if (end_logic) return;
	if (n == N) {
		end_logic = true;
		for (int i = 0; i < N; i++) {
			cout << S[i];
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= 3; i++) {
		S[n] = i;
		if (IsGood(n)) solve(n + 1);
		S[n] = 0;
	}
}

int main()
{
	cin >> N;

	solve(0);

	return 0;
}