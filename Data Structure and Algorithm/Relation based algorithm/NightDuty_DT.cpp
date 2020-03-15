#include<iostream>
#define MAX 1001

using namespace std;

extern int min(int a, int b);

int Teacher;
int Thief;
int skills[3];
int DT[MAX];

void solve()
{
	if (Teacher == Thief) {
		cout << 0; 
		return;
	}

	for (int i = Teacher; i <= Thief; i++) {
		DT[i] = 123456789;
	}

	DT[Teacher] = 0;

	for (int i = Teacher + 1; i <= Thief; i++) {
		int tmp = 123456789;
		for (int k = 0; k < 3; k++) {
			if (i - skills[k] >= Teacher) {
				tmp = min(tmp, DT[i - skills[k]] + 1);
			}
		}
		DT[i] = tmp;
	}

	if (DT[Thief] != 123456789) {
		cout << DT[Thief] << endl;
	}
	else
		cout << -1;

}

int main()
{
	cin >> Teacher >> Thief;
	cin >> skills[0] >> skills[1] >> skills[2];

	solve();
	return 0;
}