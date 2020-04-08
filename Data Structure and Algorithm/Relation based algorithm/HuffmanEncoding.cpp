#include <iostream>
using namespace std;

int N;
char mTree[1500000];
char mData[251];

int main()
{
	cin >> N;

	char chr;
	char chValue[21];

	for (int i = 0; i < N; i++) {
		cin >> chr >> chValue;

		int idx=1;
		for (int j = 0; chValue[j] != '\0'; j++) {
			if (chValue[j] == '0') idx = idx * 2;
			else
				idx = idx * 2 + 1;
		}
		mTree[idx] = chr;
	}

	cin >> mData;

	int idx=1;
	for (int i = 0; mData[i] != '\0'; i++) {
		if (mData[i] == '0') idx = idx * 2;
		else
			idx = idx * 2 + 1;
		if (mTree[idx] != 0) {
			cout << mTree[idx];
			idx = 1;
		}
	}

	return 0;
}