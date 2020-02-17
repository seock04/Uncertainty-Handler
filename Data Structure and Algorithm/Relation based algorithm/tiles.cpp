#include <iostream>

using namespace std;
int M;

int solve(int n)
{
	if (n == 1) return 1;
	else if (n == 2) return 3;
	else {
		return (2*solve(n - 2) + solve(n - 1))%M;
	}
}

int main()
{
	int N;
	
	cin >> N;
	cin >> M;

	int ret = solve(N);

	cout << ret % M;
	
	return 0;
}

