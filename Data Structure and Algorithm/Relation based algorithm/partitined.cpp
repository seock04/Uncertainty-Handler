#include <iostream>
using namespace std;
#define MAX 30

int arr[MAX];
int cnt;
extern int min(int a, int b);

void solve(int n, int k)
{
	if (n == 0) {
		for (int i = 0; i < cnt; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
	else {
		for (int i = min(n,k); i > 0; i--) {
			arr[cnt++] = i;
			solve(n - i, i);
			cnt--;
		}		
	}
}

int main()
{
	int n;

	cin >> n;

	solve(n, n);

	return 0;
}