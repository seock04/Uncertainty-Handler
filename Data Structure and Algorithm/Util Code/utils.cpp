
// this file contain a few util code that is good to remember for the algorithm exam or coding interview


bool IsPrime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}


int min(int a, int b) { return a < b ? a : b; }

int max(int a, int b) { return a < b ? b : a; }

