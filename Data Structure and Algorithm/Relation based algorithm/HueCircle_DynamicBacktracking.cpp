#include<iostream>

using namespace std;

#define MOD 1000000003

int DT[1001][1001][2];
int N, K;


int solve(int n, int k, bool can)
{
	if (DT[n][k][can] != -1) {
		return DT[n][k][can];
	}

	if (n >= N || k == K) {
		return ((int)(k == K)) && (n <= N || can);
	}
	else {
		DT[n][k][can] = (solve(n + 1, k, can) + solve(n + 2, k + 1, can)) % MOD;
		return DT[n][k][can];
	}
}

int main()
{
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			DT[i][j][0] = -1;
			DT[i][j][1] = -1;
		}
	}

	cin >> N >> K;

	cout << (solve(1, 0, true) + solve(2, 1, false))%MOD;

	return 0;
}