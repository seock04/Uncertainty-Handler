#include <iostream>
using namespace std;
#define MAX 101
int N = 0;
int arr[MAX];

int max_sum = 0;

void solve()
{
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			int s = 0;
			if (i == j && arr[i] > max_sum) max_sum = arr[i]; // because it allows the subset with 1 element
			else
			{
				for (int k = i; k <= j; k++) {
					s += arr[k];
					if (s > max_sum) max_sum = s;
				}
			}
		}
	}
}


int main()
{

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	//solve(0, 0);
	solve();

	cout << max_sum;
	return 0;
}