#include <iostream>
using namespace std;

extern bool IsPrime(int v);


int N, cnt = 0;

void f(int num, int len)
{
	if (len == N)
	{
		int tmp = num;
		while (tmp) {
			if (!IsPrime(tmp)) return;
			tmp /= 10;
		}
		cnt++;
		cout << num << endl;
	}
	else {
		//for (int i = 1; i < 10; i++) {
		//	f(num * 10 + i, len + 1);
		//}

		f(num * 10 + 1, len + 1);
		f(num * 10 + 3, len + 1);
		f(num * 10 + 7, len + 1);
		f(num * 10 + 9, len + 1);
	}
}

int main()
{
	cin >> N;
	//f(0, 0);
	f(2, 1);
	f(3, 1);
	f(5, 1);
	f(7, 1);
	cout << cnt << endl;

	//for (int i = 1; i < 100; i++) {
	//	if (!IsPrime(i)) cout << i << "is not Prime" << endl;
	//}
	
	return 0;
}