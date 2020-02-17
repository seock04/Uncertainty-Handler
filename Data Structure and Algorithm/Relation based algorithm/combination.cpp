#include<iostream>
using namespace std;

int N;
int K;

int combination(int n, int k)
{
	if (n == k) return 1;
	else if (k == 1) return n;
	else {
		return combination(n - 1, k - 1) + combination(n - 1, k);
	}

}

int main()
{
	cin >> N >> K;

	

	cout << combination(N, K);;
	return 0;
}