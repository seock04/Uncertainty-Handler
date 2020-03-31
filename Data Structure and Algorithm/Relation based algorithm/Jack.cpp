#include <iostream>

using namespace std;

#define MAXN 101
#define MAXM 501

extern int mABS(int v);

int n, m;
int start, finish, cr, ca;

int line[MAXM];

int DT[MAXM][MAXN];

int isIn(int a, int b, int k)
{
	return ((a <= k && k < b) || (b <= k && k < a)) ? 1 : 0;
}

void solve()
{
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j == k && (line[i] == k || line[i] + 1 == k)) {
					DT[i][j] = (DT[i - 1][k] + cr < DT[i][j]) ? DT[i - 1][k] + cr : DT[i][j];
 				}
				else if (isIn(j, k, line[i])) {
					DT[i][j] = (DT[i - 1][k] + (mABS(j - k) - 1)*ca < DT[i][j]) ?
						DT[i - 1][k] + (mABS(j - k) - 1)*ca : DT[i][j];
				}
				else {
					DT[i][j] = DT[i - 1][k] + mABS(j - k)*ca < DT[i][j] ?
						DT[i - 1][k] + mABS(j - k)*ca : DT[i][j];
				}
			}
		}
	}

	cout << DT[m][finish] << endl;
}

int main()
{
	cin >> n >> m;
	cin >> start >> finish >> cr >> ca;

	for (int i = 1; i <= m; i++) {
		cin >> line[i];
	}

	//init
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			DT[i][j] = 9999999;
		}
	}

	// add the cost from zero to j
	for (int j = 1; j <= n; j++) {
		DT[0][j] = mABS(j-start)*ca;
	}

	solve();
	return 0;
}