#include <iostream>
#define MAX 101
using namespace std;
extern int min(int a, int b);

int N, M;

int usedM[MAX];
int inActiveCost[MAX];

int solve(int k, int r) 
{
	if (k == N) {
		if (r <= 0)return 0;
		else
			return 9999999;
	}

	if (r < 0) {
		return solve(k + 1, r);
	}
	else {
		return min(solve(k + 1, r), solve(k + 1, r - usedM[k]) + inActiveCost[k]);
	}

}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> usedM[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> inActiveCost[i];
	}

	cout << solve(0, M);
	return 0;
}