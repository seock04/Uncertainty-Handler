#include <iostream>
using namespace std;

extern int mABS(int v);

int Pumps[12];
int FireTrucks[11];

bool visited[12];

int P, F;

int sol = 0x7fffffff;

int getDistance(int p, int f)
{
	return mABS(Pumps[p] - FireTrucks[f]);
}

void solve( int f, int dis)
{
	if (f == F) {
		if (sol > dis) sol = dis;
		return;
	}

	for (int i = 0; i < P; i++) {
		if (visited[i] != true) {
			visited[i] = true;

			solve(f + 1, dis + getDistance(i, f));

			visited[i] = false;
		}
	}
}

int main()
{
	cin >> P >> F;

	for (int i = 0; i < P; i++) cin >> Pumps[i];
	for (int i = 0; i < F; i++) cin >> FireTrucks[i];

	solve( 0, 0);

	cout << sol;
	return 0;
}