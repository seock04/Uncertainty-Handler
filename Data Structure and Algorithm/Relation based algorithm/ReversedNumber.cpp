#include<iostream>
using namespace std;

void solve(int n)
{
	if (n <= 0) return;
	int v = n % 10;

	if (v > 0) {
		cout << n % 10;
	}
	
	solve(n / 10);
}


int main()
{
	int N;
	cin >> N;
	solve(N);

	return 0;
}