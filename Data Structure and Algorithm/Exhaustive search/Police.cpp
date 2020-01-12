#include <iostream>
using namespace std;

#define MAX_WAY 1001
#define MAX_EVENT 16

extern int mABS(int v);
extern int min(int a, int b);

int N, W;
int Event[MAX_EVENT][2];
int ret = 0x7fffffff;

int Distance[MAX_WAY][MAX_WAY][MAX_EVENT][MAX_EVENT] = { 0, };

int solve(int x1, int y1, int x2, int y2, int w, int dis)
{
	if (w == W) {
		return dis;
	}
	if (Distance[x1][y1][Event[w][0]][Event[w][1]] == 0) {
		Distance[x1][y1][Event[w][0]][Event[w][1]] = mABS(Event[w][0] - x1) + mABS(Event[w][1] - y1);
	}
	if (Distance[x2][y2][Event[w][0]][Event[w][1]] == 0) {
		Distance[x2][y2][Event[w][0]][Event[w][1]] = mABS(Event[w][0] - x2) + mABS(Event[w][1] - y2);
	}

	//int dis1 = mABS(Event[w][0] - x1) + mABS(Event[w][1] - y1);
	//int dis2 = mABS(Event[w][0] - x2) + mABS(Event[w][1] - y2);

	return min(solve(Event[w][0], Event[w][1], x2, y2, w + 1, dis + Distance[x1][y1][Event[w][0]][Event[w][1]]), solve(x1, y1, Event[w][0], Event[w][1], w + 1, dis + Distance[x2][y2][Event[w][0]][Event[w][1]]));

}

int main()
{
	cin >> N >> W;

	for (int i = 0; i < W; i++) {
		cin >> Event[i][0] >> Event[i][1];
	}

	int sol = solve(1, 1, N, N, 0, 0);

	cout << sol;
	return 0;
}