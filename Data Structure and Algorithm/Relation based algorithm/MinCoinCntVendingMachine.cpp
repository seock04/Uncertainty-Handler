#include <iostream>
using namespace std;

#define MAXN 11

int M;
int N;
int coins[MAXN];

int coin_cnt = 987654321;
int DT[10001];

extern int min(int a, int b);

void solve(int m, int cnt)
{
	if (m > M || cnt >= coin_cnt) return;
	if (m == M) {
		if (cnt < coin_cnt) {
			coin_cnt = cnt;
		}			
		return;
	}

	for (int i = N - 1; i >= 0; --i) {
		solve(m + coins[i], cnt + 1);
	}
}
//not appropriate as it runs infinite
int betterSol(int m)
{
	int ans = 987654321;
	if (m == M) 
		return 0;

	for (int i = 0; i < N; i++) {
		if (m + coins[i] <= M) {
			ans = min(ans, betterSol(m + coins[i]) + 1);			
		}
	}
	
}

int betterSol_DT(int m)
{

	if (m == M) return DT[m] = 0;
	if (DT[m] == 0) {
		DT[m] = 987654321;
		for (int i = 0; i < N; i++) {
			if (m + coins[i] <= M) {
				DT[m] = min(DT[m], betterSol_DT(m + coins[i]) + 1);
			}
		}
	}
	
	return DT[m];
}

int main()
{
	cin >> M;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> coins[i];
	}
	// exhaustive search approach
	/*solve(0, 0);
	cout << coin_cnt << endl;*/

	/*cout << betterSol(0); // it does not work*/

	//with DT
	cout << betterSol_DT(0);
	return 0;
}