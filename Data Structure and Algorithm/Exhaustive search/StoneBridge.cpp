#include<iostream>
using namespace std;

char scroll[11];
char bridges[2][21];

int sol = 0;

void solve(int k, int AorD, int pos)
{
	if (scroll[k] == '\0') {
		++sol;
		return;
	}

	int next = (AorD == 1) ? 0 : 1;

	for (int i = pos; bridges[AorD][i] != '\0'; i++) {
		if (bridges[AorD][i] == scroll[k]) {
			solve(k + 1, next, i+1);
		}
	}
}

int main()
{
	cin >> scroll;
	cin >> bridges[0] >> bridges[1];

	solve(0, 0, 0);
	solve(0, 1, 0);

	cout << sol;
	return 0;
}