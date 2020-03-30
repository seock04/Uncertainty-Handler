#include <iostream>
#define MAXN 101
using namespace std;
extern int max(int a, int b);

int N, M;

int usedM[MAXN];
int inActiveCost[MAXN];

int DT[MAXN][10001];

int res = 9999999;
void solve()
{

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N*100; j++) {
			if (j >= inActiveCost[i]) {
				DT[i][j] = max(DT[i - 1][j], DT[i - 1][j - inActiveCost[i]] + usedM[i]);
			}
			else {
				DT[i][j] = DT[i - 1][j];
			}
		}
	}

	for (int j = 0; j < N * 100; j++) {
		if (DT[N - 1][j] >= M && res >j)
			res = j;
	}

	cout << res;
}

int main()
{

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			DT[i][j] = -1;
		}
	}

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> usedM[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> inActiveCost[i];
	}

	solve();
	return 0;
}