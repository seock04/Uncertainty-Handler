#include <iostream>
using namespace std;

#define MAX 201

#define NONE -1
#define RED 1
#define BLACK 2

int N, M;
int visited[MAX];
class Node
{
public:

	int v;
	Node* prev;
	Node* next;
};

Node BUFF[300];
int buff_cnt=0;

class HashTable 
{
public:
	Node* DBTable[MAX];
	
	void Add(int s, int e)
	{
		if (s > N) return;

		Node* n = &BUFF[buff_cnt++];

		if (n == NULL) return;

		n->v = e;
		n->prev = NULL;
		n->next = DBTable[s];

		if (DBTable[s] != NULL) {
			DBTable[s]->prev = n;
		}
		DBTable[s] = n;
	}

	bool IsOkToPaint(int v, int c)
	{
		Node* n = DBTable[v];

		bool can = true;
		for (Node* itr = n; itr != NULL; itr = itr->next) {
			if (visited[itr->v] == c)
				can = false;
		}

		return can;
	}


};

HashTable hTable;


void Paint(int v, int color)
{
	visited[v] = color;
	if (!hTable.IsOkToPaint(v, color)) {
		visited[v] = 0;
		return;
	}
	Node* n = hTable.DBTable[v];

	for (Node* itr = n; itr != NULL; itr = itr->next) {
		if (visited[itr->v] == 0) {
			Paint(itr->v, BLACK);
			Paint(itr->v, RED);
		}
	}
}

bool IsAllColored()
{
	bool ret = true;

	for (int i = 0; i < N; i++) {
		if (visited[i] == 0)
			ret = false;
	}

	return ret;
}

int main()
{
	cin >> N >> M;

	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		hTable.Add(s, e);
		hTable.Add(e, s);
	}

	Paint(0, BLACK);

	cout << IsAllColored() << endl;
}