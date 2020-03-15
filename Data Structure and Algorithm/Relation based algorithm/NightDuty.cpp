#include <iostream>

using namespace std;

int Teacher;
int Thief;
int skills[3];

int resultMin=0x7fffffff;

void solve(int k, int cnt)
{
	if (k > Thief) return;
	if (k == Thief) {
		if (cnt < resultMin) resultMin = cnt;
	}
	else {
		for (int i = 0; i < 3; i++) {
			solve(k + skills[i], cnt + 1);
		}
	}
}

int main()
{
	cin >> Teacher >> Thief;
	cin >> skills[0] >> skills[1] >> skills[2];

	solve(Teacher, 0);
	cout << resultMin << endl;

	return 0;
}