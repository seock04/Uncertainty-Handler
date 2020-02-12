#include <iostream>
using namespace std;

#define MAX 10000
char stars[MAX];
int idx = 0;

void solve(int n)
{
	if (n <= 0) return;
	else if (n == 1) {
		stars[idx++] = '*';
		cout << stars<<endl;
		return;
	}

	solve(n - 1);
	stars[idx++] = '*';
	cout << stars << endl;
}

int main()
{
	int N;

	cin >> N;

	solve(N);
}