#include <iostream>
using namespace std;

int LCA(int a, int b)
{
	if (a == b) return 0;

	if (a > b) {
		return LCA(a / 2, b) + 1;
	}
	else {
		return LCA(a, b / 2) + 1;
	}

}


int main()
{
	int a, b;

	cin >> a >> b;

	cout << LCA(a, b);
	
	return 0;
}