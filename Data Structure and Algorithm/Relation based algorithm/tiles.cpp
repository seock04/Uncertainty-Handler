#include <iostream>

#define MAXN 100001

using namespace std;
int M;

int DT[MAXN];

int solve(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 3;
	else {
		return (2*solve(n - 2) + solve(n - 1))%M;
	}
}

int solve_DT(int n)
{
	if (-1 != DT[n]) return DT[n];

	if (n == 1) return DT[n] = 1;
	else if (n == 2) return DT[n] = 3;
	else {
		return DT[n] = (2 * solve(n - 2) + solve(n - 1)) % M;
	}
}

void solve_bottom_up_DT(int n)
{
	DT[1] = 1;
	DT[2] = 3;
	for (int i = 3; i <= n; i++) {
		DT[i] = (2 * DT[i - 2] + DT[i - 1]) % M;		
	}
	cout << DT[n];
}


int main()
{
	int N;
	
	cin >> N;
	cin >> M;

	for (int i = 0; i < MAXN; i++) {
		DT[i] = -1;
	}

	solve_bottom_up_DT(N);
	//int ret = solve_DT(N);

	//cout << ret % M;
	
	return 0;
}

