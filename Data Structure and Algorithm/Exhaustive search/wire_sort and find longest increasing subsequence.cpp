#include<iostream>
//debugging #include<string>

using namespace std;

extern void SWAP(int& a, int& b);

int N;
int pole[501][2];

void quickSort(int left, int right)
{
	int pivot, i, j;

	if (left < right) {
		pivot = left;
		i = left;
		j = right;

		while (i < j) {
			while (pole[i][0] <= pole[pivot][0] && i < right) i++;
			while (pole[j][0] > pole[pivot][0])j--;

			if (i < j) {
				SWAP(pole[i][0], pole[j][0]);
				SWAP(pole[i][1], pole[j][1]);
			}
		}
		SWAP(pole[pivot][0], pole[j][0]);
		SWAP(pole[pivot][1], pole[j][1]);

		quickSort(left, j - 1);
		quickSort(j + 1, right);
	}
}
int ret = 0;
//debugging string ret_list;
void solve(int k, int cur, int count)
{
	if (k == N) {
		if (ret < count) {
			ret = count;
		//debugging	cout << ret_list << endl;
		}
		//debugging ret_list = "";
		return;
	}

	if (cur < pole[k][1]) {
		//debugging ret_list += to_string(pole[k][1]);
		//debugging ret_list += " ";
		solve(k + 1, pole[k][1], count + 1);
	}
	else {
		solve(k + 1, cur, count);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pole[i][0] >> pole[i][1];
	}

	quickSort(0, N - 1);
	
	for (int i = 0; i < N; i++) {
		solve(i, 0, 0);
	}
	

	cout << N - ret;

	return 0;
}