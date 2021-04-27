
// 왜 right 의 초기값은 10e18 인가? 10e9가 아니고...
// 왜 mid를 그대로 사용하면 문제가 fail이고 ans를 쓰면 괜찮은걸까?
#include<iostream>
using namespace std;

typedef unsigned long long ll;


int N, M;
int lines[100001];

ll binarySearch(ll start, ll end)
{
	ll mid = -1;
	ll s = start;
	ll e = end;
	ll ans = 0;
	while (s <= e) {
		mid = s + (e - s)/2;
		ll total = 0;
		for (int i = 0; i < N; ++i) {
			total += mid/lines[i];
		}

		if (total < M) {
			s = mid + 1;
		}
		else {
			e = mid - 1;
			ans = mid;
		}
	}
	return ans;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> lines[i];
	}

	cout << binarySearch(1, 10e18);
	return 0;
}
