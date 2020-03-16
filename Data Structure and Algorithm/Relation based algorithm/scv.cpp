#include<iostream>
#define MAX 201
using namespace std;

int N, M;
int map[MAX][MAX];
extern int max(int a, int b);

void solve_reculsive(int n, int m, int cnt)
{
	if (map[n][m] == 1) cnt++;

	map[n][m] = max(map[n][m], cnt);

	if (n == N && m == M) {	
		return;
	}
	
	if (n + 1 <= N) {
		solve_reculsive(n + 1, m, map[n][m]);
	}
	
	if (m + 1 <= M) {
		solve_reculsive(n, m + 1, map[n][m]);
	}
	
}

void solve()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = map[i][j] + max(map[i-1][j], map[i][j-1]);
		}
	}
}



int main()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	//solve_reculsive(1, 1, 0);
	solve();
	cout << map[N][M] << endl;
	return 0;
}