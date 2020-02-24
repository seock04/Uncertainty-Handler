#include <iostream>
using namespace std;

#define MAX 128

int N;
int map[MAX][MAX];

int gray, white;

void solve(int y, int x, int n)
{
	int w = 0;
	int g = 0;

	for (int i = y; i < y+n; i++) {
		for (int j = x; j < x+n; j++) {
			w += (map[i][j] == 1) ? 1 : 0;
			g += (map[i][j] == 0) ? 1 : 0;
		}
	}

	bool isOne = false;
	if (w == n*n) {
		isOne = true;
		++white;
	}
	if (g == n*n) {
		isOne = true;
		++gray;
	}

	if (isOne != true) {
		solve(y, x, n / 2);
		solve(y + n / 2, x, n / 2);
		solve(y, x + n / 2, n / 2);
		solve(y + n / 2, x + n / 2, n / 2);
	}
}

int main()
{

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	solve(0, 0, N);
	cout << white << endl;
	cout << gray;
	return 0;
}