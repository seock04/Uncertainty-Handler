#include <iostream>
using namespace std;

#define MAX 10
#define MAX_CANDIDATE 2000

int N;
int numbers[MAX];
int len=0;

int candidates[MAX_CANDIDATE];
int cnt = 0;

int before=0;

extern void IntToArray(int n, int numbers[], int &len);
extern bool IsPrime(int x);
extern void SWAP(int& a, int& b);
extern void quicksort(int arr[], int left, int right);

void sequencing(int k)
{
	if (k == len) {
		int ret = 0;
		for (int i = k-1; i >= 0; --i) {
			ret = ret * 10 + numbers[i];
		}
		candidates[cnt++] = ret;
		return;
	}
	
	for (int i = k; i < len; i++) {
		SWAP(numbers[k], numbers[i]);

		sequencing(k + 1);

		SWAP(numbers[k], numbers[i]);
	}

}


int main()
{
	cin >> N;
	IntToArray(N, numbers, len);
	
	sequencing(0);
	quicksort(candidates, 0, cnt-1);
	int ret = 0;
	for (int i = 0; i < cnt; i++) {
		if (IsPrime(candidates[i]) && before != candidates[i]) {
			++ret;
			before = candidates[i];
			cout << before << " ";
		}
	}
	if (ret == 0) cout << 0;
	return 0;
}