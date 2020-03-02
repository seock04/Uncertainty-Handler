#include <iostream>

using namespace std;
#define MAX 200

class mQueue
{
public:
	char arr[MAX];
	int front;
	int rear;

	void push(char v)
	{
		if (isFull()) return;

		arr[rear++] = v;
	}


	char pop()
	{
		if (!isEmpty()) {
			return arr[front++];
		}

		return -1;
	}
	 
	//char mfront()
	//{
	//	return arr[front];
	//}

private:
	bool isFull()
	{
		if ((rear + 1) % MAX == front)
			return true;
		else
			return false;
	}

	bool isEmpty()
	{
		return rear == front;
	}
};


int n;

mQueue mData;
char encrypted[1 << 18];
char decrypted[1 << 18];


void decrypt(int s, int len, char k)
{
	if (k == '1' || k == '0') {
		for (int i = s; i < s+len; i++) {
			decrypted[i] = k;
		}
	}
	else if(k == '-'){
		decrypt(s, len / 2, mData.pop());
		decrypt(s + (len / 2), len / 2, mData.pop());
	}

}

void init()
{
	mData.front = 0;
	mData.rear = 0;
	for (int i = 0; i < MAX; i++) {
		decrypted[i] = '\0';
		encrypted[i] = '\0';
	}
}

int main()
{
	int tc;
	cin >> tc;
	char c;


	while (tc--) {
		cin >> n;
		cin >> encrypted;
		for (int i = 0; encrypted[i] != '\0'; i++) {
			mData.push(encrypted[i]);
		}
		decrypt(0, n, mData.pop());

		cout << decrypted << endl;

		init();
	}

	return 0;
}