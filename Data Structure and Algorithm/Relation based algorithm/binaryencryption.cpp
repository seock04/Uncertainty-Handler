#include <iostream>

using namespace std;

int N;
char binaryArray[1<<19];

bool isSameBinary(char arr[], int len) {
	char c = arr[0];

	bool isSame = true;
	for (int i = 0; i < len; i++) {
		if (arr[i] != c) isSame = false;
	}

	return isSame;
}

void solve(char arr[], int len)
{
	if (isSameBinary(arr, len)) {
		cout << arr[0];
		return;
	}
	else {
		cout << '-';
		solve(arr, len / 2);
		solve(arr + len / 2, len / 2);
	}	
}


int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> binaryArray[i];
		}
		solve(binaryArray, N);
		cout << endl;
	}
	
	return 0;
}