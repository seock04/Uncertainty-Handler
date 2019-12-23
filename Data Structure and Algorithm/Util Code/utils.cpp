#include <iostream>
using namespace std;

// this file contain a few util code that is good to remember for the algorithm exam or coding interview

bool isPrime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}


int main()
{
	for (int i = 1; i < 100; i++) {
		if (!isPrime(i)) cout << i << "is not Prime" << endl;
	}

	return 0;
}