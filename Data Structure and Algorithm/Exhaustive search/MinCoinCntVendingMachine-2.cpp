#include <iostream>

using namespace std;
#define MAX 11

int M, N;
int coins[MAX];
int t_cnt = 0xfffffff;

void solve(int changes, int k, int cnt)
{
	if (k == N || changes > M) return;
	if (changes == M) {
		if (t_cnt>cnt) t_cnt = cnt;
		return;
	}

	for (int i = 0; changes + (coins[k] * i) <= M; i++) {
		if(cnt+i < t_cnt)
			solve(changes + (coins[k] * i), k + 1, cnt + i);
	}
}

int main()
{
	cin >> M;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}

	solve(0, 0, 0);

	cout << t_cnt;

	return 0;
}