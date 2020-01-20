#include<iostream>
#include<math.h>

using namespace std;

extern int min(int a, int b);
extern int max(int a, int b);
extern int Ceiling(int v);

int Path[13][2];
bool visited[13];
int N, K;
int sol = 0x7fffffff;

int distant(int a, int b)
{
	return (Path[a][0] - Path[b][0])* (Path[a][0] - Path[b][0]) + (Path[a][1] - Path[b][1])*(Path[a][1] - Path[b][1]);
}

void solve(int cur, int cnt, int max_dist)
{
	if (cnt == N) {
		int dis = max(max_dist, distant(cur, N + 1));
		if (sol > dis) sol = dis;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == true) continue;

		visited[i] = true;
		solve(i, cnt + 1, max(max_dist, distant(cur, i)));
		visited[i] = false;
	}
}

int main()
{
	cin >> N >> K;
	
	Path[0][0] = Path[0][1] = 0;
	
	for (int i = 1; i < N; i++) {
		cin >> Path[i][0] >> Path[i][1];
	}
	Path[0][0] = Path[0][1] = 10000;

	solve(0, 0, 0); //cur_pos, cnt, max_dist

	cout << ceil(sqrt(sol) / 10);
	return 0;
}