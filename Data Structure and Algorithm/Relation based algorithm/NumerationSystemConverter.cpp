#include<iostream>
using namespace std;
char decimal[21] = "0123456789ABCDEFGHIJ";

void ConvertNumSystem(int from, int to) 
{
	if (from < to) {
		cout << from;
	}
	else {
		ConvertNumSystem(from / to, to);
		cout << decimal[from%to];
	}
}

int main()
{
	int n, k;
	cin >> n >> k;

	ConvertNumSystem(n, k);
	
	return 0;
}