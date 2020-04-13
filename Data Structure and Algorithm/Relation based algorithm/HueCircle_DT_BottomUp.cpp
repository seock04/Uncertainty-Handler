#include<iostream>

using namespace std;

#define MOD 1000000003

int DT[1001][1001];
int N, K;

void solve()
{
	for (int n = 2; n <= N; n++) {
		for (int k = 1; k <= N / 2; k++) {
			if (k == 1)DT[n][k] = n;
			else {
				DT[n][k] = (DT[n - 2][k - 1] + DT[n - 1][k])% MOD;
			}
		}
	}
}

int main()
{
	cin >> N >> K;

	solve();

	cout << DT[N][K];
	return 0;
}