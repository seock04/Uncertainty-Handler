#include <iostream>
#define MAX 1001
using namespace std;

int Teacher;
int Thief;
int skills[3];

int resultMin = 0x7fffffff;

class mQueue
{
public:
	int arr[MAX];
	int head;
	int tail;

	mQueue()
	{
		head = 0;
		tail = 0;
	}
	
	void push(int v)
	{
		if (!IsFull())
		{
			arr[tail++] = v;
		}
	}

	int front()
	{
		return arr[head];
	}

	int pop()
	{
		if (!IsEmpty()) {
			return arr[head++];
		}
	}

	bool IsFull()
	{
		return ((tail + 1)%MAX == head);
	}

	bool IsEmpty()
	{
		return tail == head;
	}
};

mQueue q;
int visited[MAX];

void solve()
{
	q.push(Teacher);

	while (!q.IsEmpty()) {
		int value = q.pop();
		if (value == Thief) {
			cout << visited[value] << endl;
		}
		else {
			for (int i = 0; i < 3; i++) {

				int tmp = value + skills[i];
				if (tmp <= Thief && !visited[tmp]) {
					q.push(tmp);
					visited[tmp] = visited[value] + 1;
				}

			}

		}
		
	}
}

int main()
{
	cin >> Teacher >> Thief;
	cin >> skills[0] >> skills[1] >> skills[2];

	solve();
	return 0;
}