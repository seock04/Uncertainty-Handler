// 아직 해결 코드 
#include<iostream>

using namespace std;

#define MAX 1001
int M, N;
int map[MAX][MAX];

struct pos {
	int r;
	int c;
};

int mMAX(int a, int b) 
{
	return a > b ? a : b;
}
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

pos Que[MAX * MAX];
int Front, Rear;

int main()
{
	cin >> M >> N;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}

	int count = 0;
	Front = Rear = -1;
	int res = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == 1) {
				Que[++Rear] = { i, j};
			}
		}
	}	

	while (Front != Rear) {
		++count;
		int msize = Rear - Front;
		pos p = Que[++Front];

		for (int i = 0; i < msize; ++i) {
			for (int next = 0; next < 4; ++next) {
				int rr = p.r + dr[next];
				int cc = p.c + dc[next];
				if (rr < 0 || rr >= M || cc < 0 || cc >= N) continue;
				if (map[rr][cc] == -1 || map[rr][cc] == 1) continue;
				map[rr][cc] = 1;
				Que[++Rear] = { rr, cc };
			}
		}

	}

	cout << count;

	return 0;
}
