#include <iostream>

using namespace std;

extern int max(int a, int b);

int N, W, input[102][2];
int ret;

int DT[102][10002];

void solve_exhaustive(int k, int w, int p) 
{
	if (k == N) {
		if (w <= W) {
			ret = (p > ret) ? p : ret;
		}
		return;
	}

	solve_exhaustive(k + 1, w + input[k][0], p + input[k][1]);
	solve_exhaustive(k+1, w, p);
}

int solve_memoization(int k, int r) {
	if (DT[k][r] != -1) return DT[k][r];
	if (k == N) return DT[k][r] = 0;
	if (r < input[k][0]) return solve_memoization(k + 1, r);
	else {
		return max(solve_memoization(k + 1, r), solve_memoization(k + 1, r - input[k][0]) + input[k][1]);
	}
}



int main()
{
	cin >> N >> W;

	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 10002; j++) {
			DT[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> input[i][0] >> input[i][1];
	}

	
	cout << solve_memoization(0, W);
	return 0;
}