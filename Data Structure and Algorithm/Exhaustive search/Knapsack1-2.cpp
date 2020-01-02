#include<iostream>
using namespace std;

int N;
int W;
int stuff[101][2];
int answer = 0;

void solve(int n, int w, int v)
{
	if (w > W) return;
	if (n == N) {
		if (v > answer) 
			answer = v;
		return;
	}

	solve(n + 1, w + stuff[n][0], v + stuff[n][1]);
	solve(n + 1, w, v);
}


int main()
{
	cin >> N >> W;

	for (int i = 0; i < N; i++) {
		cin >> stuff[i][0];
		cin >> stuff[i][1];
	}

	solve(0, 0, 0);

	cout << answer << endl;
	return 0;
}