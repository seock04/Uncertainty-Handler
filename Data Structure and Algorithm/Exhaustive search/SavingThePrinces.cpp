#include <iostream>
using namespace std;
#define MAX 20

bool visited[MAX];
int island[MAX][3];
int direction = 1;
int sol;

int N;

void solve(int p)
{
	if (direction == 2 && p == 0) {
		++sol;
		direction = 1;
		return;
	}
	if (direction == 1 && p == N - 1) 
		direction = 2; 

	for (int i = 0; i < N; i++) {
		if (direction == 2 && island[i][2] == 0) continue;
		if (direction == 1 && i == 0) continue;
		if (visited[i] != true) {
			visited[i] = true;
			
			if (island[i][0] >= island[p][0] - island[p][1] &&
				island[i][0] <= island[p][0] + island[p][1]) {
				solve(i);
			}

			visited[i] = false;
		}
	}
}

int main()
{	
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> island[i][0] >> island[i][1] >> island[i][2];
	}

	solve(0);

	cout << sol % 1000;

	return 0;
}