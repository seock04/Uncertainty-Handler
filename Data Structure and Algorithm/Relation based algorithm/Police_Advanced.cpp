#include <iostream>
using namespace std;

extern int min(int a, int b);
extern int mABS(int a);

#define MAXN 1001
#define MAX_EVENT 18

int N;
int EventCount;
int Events[MAX_EVENT][2];

int dis(int a, int b)
{
	return mABS(Events[a][0] - Events[b][0]) + mABS(Events[a][1] - Events[b][1]);
}

int solve(int a, int b)
{
	int next = (a > b ? a : b) + 1;
	if (next >= EventCount + 2)
		return 0;

	return min(solve(next,b)+dis(a,next), solve(a,next)+dis(next, b));
}
int main()
{
	cin >> N;
	cin >> EventCount;
	
	// set initial police car
	Events[0][0] = 1;
	Events[0][1] = 1;
	Events[1][0] = N;
	Events[1][1] = N;

	for (int i = 2; i < EventCount + 2; i++) {
		cin >> Events[i][0] >> Events[i][1];
	}

	cout << solve(0,1);
}