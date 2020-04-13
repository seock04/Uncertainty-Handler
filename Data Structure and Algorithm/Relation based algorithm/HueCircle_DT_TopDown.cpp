#include<iostream>

using namespace std;

#define MOD 1000000003

int DT[1001][1001];
int N, K;

int solve(int n, int k)
{
	if (DT[n][k] != 0) return DT[n][k];

	if (k > n / 2) {
		DT[n][k] = 0;
	}
	else if (k == 1) {
		DT[n][k] = n;
	}
	else {
		DT[n][k] = (solve(n - 2, k - 1) + solve(n - 1, k))%MOD;
	}
	return DT[n][k];
}

int main()
{
	cin >> N >> K;

	cout << solve(N, K);

	return 0;
}