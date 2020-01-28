#include<iostream>
using namespace std;

long long int N; // can be as big as 10 billions

int solve() //not optimized
{
	int ret = 0;

	for (int i = 1; i <= N; i++) {
		if (N%i == 0) ret += i;
	}

	return ret;
}

long long int solve_opt()
{
	long long int ret = 0;
	for (long long int i = 1; i*i <= N; i++) {
		if (N%i == 0) ret += i + (N / i);
	}

	return ret;
}


int main()
{
	cin >> N;

	cout << solve_opt();


	return 0;
}