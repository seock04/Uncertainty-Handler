#include<iostream>

using namespace std;

#define MOD 1000000003

int DT[1001][1001];
int N, K;
int ret;
void solve(int n, int k, bool can)
{
	if (n >= N || k == K) {
		ret += ((int)(k == K)) && (n <= N || can);
		ret %= MOD;
		return;
	}
	solve(n + 1, k, can);
	solve(n + 2, k + 1, can);
}

int main()
{
	cin >> N >> K;

	solve(1, 0, true);
	solve(2, 1, false);
	cout << ret;
	return 0;
}