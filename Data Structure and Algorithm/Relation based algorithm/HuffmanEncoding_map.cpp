#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, char> mp;
int N;
string mData;

int main()
{

	cin >> N;
	char ch;
	string codes;
	for (int i = 0; i < N; i++) {
		cin >> ch >> codes;
		mp[codes] = ch;
	}
	cin >> mData;

	string tmp;
	for (int i = 0; i < mData.length(); i++) {
		tmp += mData[i];
		if (mp[tmp]) {
			cout << mp[tmp];
			tmp.clear();
		}
	}
	return 0;
}