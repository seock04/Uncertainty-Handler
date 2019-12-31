#include<iostream>
using namespace std;
#define MAX 10

int M, N;
int coins[MAX];

int t_cnt = 0x7fffffff;

void solve(int changes, int cnt)
{
	if (changes < 0) return;
	if (changes == 0) {
		if (cnt < t_cnt) 
			t_cnt = cnt;
		return;
	}
	for (int i = 0; i < N; i++) {
		if(cnt+1 < t_cnt)
			solve(changes - coins[i], cnt + 1);
	}
		
}

int main()
{
	cin >> M;
	cin >> N;

	for (int i = N-1; i >=0; i--) //because input is already ordered
		cin >> coins[i];

	solve(M, 0);
	cout << t_cnt << endl;
}