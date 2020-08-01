#include <iostream>
using namespace std;
int n;
int gift[21];
int W, A, B, C;
int ans=987654321;
int DT[2][668][668];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> gift[i];
		W += gift[i];
	}
	DT[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int a = 0; a <= 667; a++) {
			for (int b = 0; b <= 667; b++) {
				DT[i%2][a][b] = (DT[(i - 1)%2][a][b]
					|| (a - gift[i] < 0 ? false : DT[(i - 1) % 2][a - gift[i]][b])
					|| (b - gift[i] < 0 ? false : DT[(i - 1) % 2][a][b - gift[i]]));
			}
		}
	}
	for (int a = 0; a <= 667; a++) {
		for (int b = 0; b <= 667; b++) {
			if (DT[n%2][a][b]) {
				if (W - (a + b) >= a && a >= b && W - (a + b) - b <= ans) {
					ans = W - (a + b) - b, A = W - (a + b), B = a, C = b;
				}
			}
		}
	}

	cout << ans << " " << A << " " << B << " " << C << endl;

	return 0;
}