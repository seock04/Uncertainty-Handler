#include <iostream>

using namespace std;

extern int min(int a, int b);

#define MAX 100

int minv = 0x7fffffff;

int N, M;
int Mem[MAX];
int Cost[MAX];

void Solve(int n, int m, int cost)
{
	if (n == N) {
		if (m >= M && cost < minv) minv = cost;
		return;
	}
	
	if (m >= M) return Solve(n + 1, m, cost);
	else {
		Solve(n + 1, m, cost);
		Solve(n + 1, Mem[n] + m, cost +Cost[n]);
	}
}

int main() {

	cin >> N >> M;
	
	for (int i = 0; i < N; i++) cin >> Mem[i];
	for (int i = 0; i < N; i++) cin >> Cost[i];

	Solve(0, 0, 0);

	cout << minv << endl;
}