#include<iostream>
using namespace std;
#define MAX 31

int N, K;

int DT[MAX][MAX];

void resetDT()
{
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			DT[i][j] = 0;
		}
	}
}

int combinationLoof(int n, int k)
{
	if (DT[n][k]) return DT[n][k];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 1) {
				DT[i][j] = i;
			}
			else if (j == i) {
				DT[i][j] = 1;
			}
			else {
				DT[i][j] = DT[i - 1][j - 1] + DT[i - 1][j];
			}
		}
	}
	
	return DT[n][k];
}

int combination(int n, int k)
{
	if (DT[n][k]) return DT[n][k];

	if (k == 1) {
		DT[n][k] = n;
	}
	else if (k == n) {
		DT[n][k] = 1;
	}
	else {
		//DT[n][k] = DT[n - 1][k - 1] + DT[n - 1][k];
		DT[n][k] = combination(n - 1, k - 1) + combination(n - 1, k);
	}
	
	return DT[n][k];
}


int main()
{
	int tc;
	cin >> tc;

	while (tc--) {
		cin >> N >> K;

		//int ret = combination(N, K);
		int ret = combinationLoof(N, K);
		cout << ret << endl;
		resetDT();
	}

	return 0;
}