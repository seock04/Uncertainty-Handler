#include <iostream>

#define MAX_M 11

using namespace std;

int N, M;

class Node
{
public: 
	int mTo;
	int mWeight;
	bool visited;

	Node * prev;
	Node * next;
};

class NodeManager
{
public:
	Node* hTable[MAX_M];
	int mSMValue;
	bool greedy_chk[1001];

	NodeManager()
	{
		mSMValue = 0x7fffffff;
	}
	void Add(int from, int to, int v)
	{
		Node* n = new Node();
		if (n == NULL) return;

		n->mTo = to;
		n->mWeight = v;
		n->prev = NULL;
		n->next = hTable[from];

		if (hTable[from] != NULL) {
			n->prev = hTable[from]->prev;
		}
		hTable[from] = n;
	} 

	void GetShortestPathGreedy(int to)
	{
		Node* first = hTable[to];
		int greedy_solution = 0;
		greedy_chk[to] = true;

		Node* nodeNext = NULL;
		while (to != N) {
			int min = 0x7fffffff;
			for (Node* itr = hTable[to]; itr != NULL; itr = itr->next) {
				if (itr->mTo && greedy_chk[itr->mTo] == false && itr->mWeight < min) {
					min = itr->mWeight;
					nodeNext = itr;
				}
			}
			greedy_solution += min;
			greedy_chk[nodeNext->mTo] = true;
			to = nodeNext->mTo;
		}
		mSMValue = greedy_solution;

	}

	void GetShortestPathValue(int to, int value)
	{
		if (mSMValue < value) return;
		if (to == N) {
			if (mSMValue > value) {
				mSMValue = value;
			}
			return;
		}

		for (Node* itr = hTable[to]; itr != NULL; itr = itr->next) {
			if (itr->visited == false) {
				itr->visited = true;
				GetShortestPathValue(itr->mTo, itr->mWeight + value);
				itr->visited = false;
			}
		}

		return;
	}
};

NodeManager nm;

int main()
{

	cin >> N >> M;


	int from, to, weight;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> weight;
		nm.Add(from, to, weight);
		nm.Add(to, from, weight);
	}

	nm.GetShortestPathGreedy(1);
	nm.GetShortestPathValue(1, 0);
	cout << nm.mSMValue;

	return 0;
}