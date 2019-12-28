#include <iostream>

using namespace std;

int n; // n steps away from current position, and how many possible way do user have to reach to here when user can either go up with 1 stair or 2 stairs in one time?

int cnt = 0;

void solve(int s)
{
	if (s > n) return;
	if (s == n) {
		cnt += 1;
		return;
	}

	solve(s + 1);
	solve(s + 2);
}

int main()
{
	cin >> n;

	solve(0);

	cout << cnt << endl;
}