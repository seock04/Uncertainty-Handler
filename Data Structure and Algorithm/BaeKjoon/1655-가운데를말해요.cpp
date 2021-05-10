//타임아웃 왜!!!!

#include<iostream>
using namespace std;

#define MAX_HEAP 10000
int minHeap[MAX_HEAP];
int minSize = 0;

void minPush(int val)
{
	minHeap[minSize] = val;
	int current = minSize;
	while (current > 0 && minHeap[current] < minHeap[(current - 1) / 2]) {
		int temp = minHeap[(current - 1) / 2];
		minHeap[(current - 1) / 2] = minHeap[current];
		minHeap[current] = temp;
		current = (current - 1) / 2;
	}
	++minSize;
}

void minPop(int* val)
{
	*val = minHeap[0];
	--minSize;
	minHeap[0] = minHeap[minSize];

	int current = 0;
	while (current * 2 + 1 < minSize) {
		int child;
		if (current * 2 + 2 == minSize) {
			child = current * 2 + 1;
		}
		else
			child = minHeap[current * 2 + 1] < minHeap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;

		if (minHeap[current] < minHeap[child])break;

		int temp = minHeap[current];
		minHeap[current] = minHeap[child];
		minHeap[child] = temp;

		current = child;
	}
}

int maxHeap[MAX_HEAP];
int maxSize = 0;

void maxPush(int val)
{
	maxHeap[maxSize] = val;
	int current = maxSize;
	while (current > 0 && maxHeap[current] > maxHeap[(current - 1) / 2]) {
		int temp = maxHeap[(current - 1) / 2];
		maxHeap[(current - 1) / 2] = maxHeap[current];
		maxHeap[current] = temp;
		current = (current - 1) / 2;
	}
	++maxSize;
}

void maxPop(int* val)
{
	*val = maxHeap[0];
	--maxSize;
	maxHeap[0] = maxHeap[maxSize];

	int current = 0;
	while (current * 2 + 1 < maxSize) {
		int child;
		if (current * 2 + 2 == maxSize) {
			child = current * 2 + 1;
		}
		else
			child = maxHeap[current * 2 + 1] > maxHeap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;

		if (maxHeap[current] > maxHeap[child])break;

		int temp = maxHeap[current];
		maxHeap[current] = maxHeap[child];
		maxHeap[child] = temp;

		current = child;
	}
}


int main()
{
	int N, in;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> in;
		if (maxSize == 0 || maxHeap[0] <= in) {
			maxPush(in);
			int moved;
			if (maxSize > minSize+1) {
				minPush(maxHeap[0]);
				maxPop(&moved);
			}
		}
		else if (minSize == 0 || minHeap[0] >= in) {
			minPush(in);
			int moved;
			if (minSize > maxSize) {
				maxPush(minHeap[0]);
				minPop(&moved);
			}
		}
		/*
		else if (minSize <= maxSize) {
			minPush(in);
		}
		else if (minSize > maxSize) {
			maxPush(in);
		}
		*/
		if (minSize > 0 && maxSize > 0 && minHeap[0] < maxHeap[0]) {
			int t;
			int minRoot = minHeap[0];
			minPop(&t);

			int maxRoot = maxHeap[0];
			maxPop(&t);

			minPush(maxRoot);
			maxPush(minRoot);
		}

		cout << maxHeap[0] << '\n';
	}

}
