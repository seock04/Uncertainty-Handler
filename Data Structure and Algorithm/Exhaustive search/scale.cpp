#include<iostream>
using namespace std;

int Choo[7] = { 1, 3, 9, 27, 81, 243, 729 };
int visited[7];
int W;

void print()
{
	cout << W;
	for (int i = 0; i < 7; i++) {
		if (visited[i] == 1) cout << " " << Choo[i];
	}
	cout << " 0";
	for (int i = 0; i < 7; i++) {
		if (visited[i] == 2) cout << " " << Choo[i];
	}
	cout << endl;

}

void solve(int n, int left, int right)
{
	if (n == 7) {
		if (left == right) {
			print();
		}
		return;
	}

	visited[n] = 1;
	solve(n + 1, left + Choo[n], right);
	visited[n] = 2;
	solve(n + 1, left, right + Choo[n]);
	visited[n] = 0;
	solve(n + 1, left, right);
}


int main()
{
	cin >> W;
	solve(0, W, 0);
}