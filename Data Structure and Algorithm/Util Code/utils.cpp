
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

void SWAP(int& a, int& b) { int t = a; a = b; b = t; }

int mABS(int v) { return v < 0 ? -v : v; }

int mStrlen(char str[])
{
	int idx = 0;
	while (str[idx] != '\0') idx++;
	return idx;
}


//int Ceiling(float v)
//{
//	int a = v;
//	if ((float)a != v)
//		return v + 1;
//	return a;
//}
