#include <iostream>
using namespace std;

#define MAX_NAME 10
#define MAX_SUBJECT 5
#define MAX_BUFF 50000
#define MAX_HASH 100
#define MAX_BUCKET 100

unsigned int mHash(char * r)
{
	unsigned int hash = 5381;

	char c;
	while (c = *(r)++) {
		hash = (((hash << 5) + hash) + c) % MAX_HASH;
	}

	return hash%MAX_HASH;
}

int mstrcmp(char* a, char* b)
{
	int idx = 0;
	while (b[idx] != '\0') {
		if (a[idx] != b[idx]) return -1;
		++idx;
	}
	return 0;
}
void mstrcpy(char* t, char* s)
{
	int idx = 0;
	while (s[idx] != '\0') {
		t[idx] = s[idx];
		++idx;
	}
	t[idx] = '\0';
}

class SS {
public:
	int score;
	SS* prev;
	SS* next;
};

class Bucket
{
public:
	int count;
	SS* head;
};

Bucket Buckets[MAX_SUBJECT][MAX_BUCKET];

SS Items[MAX_BUFF];
int itemIndex;

SS* NewItem()
{
	return &Items[itemIndex++];
}

void DeleteItem(SS* n, int index, int key)
{
	if (n == NULL) return;
	n->score = 0;
	n->prev = NULL;
	n->next = NULL;

	if (n == Buckets[index][key].head) {
		Buckets[index][key].count =0;
		Buckets[index][key].head = NULL;
		n = NULL;
	}
}

unsigned int mBucket(int v)
{
	if (v < 0 || v>50000) return 999999;
	return (unsigned int)v / 100;
}

void initBucket()
{
	itemIndex = 0;
	for (int i = 0; i < MAX_SUBJECT; i++) {
		for (int j = 0; j < MAX_BUCKET; j++) {
			Buckets[i][j].count = 0;
			Buckets[i][j].head = NULL;
		}
	}
}

void AddtoBucket(int v, int index)
{
	SS* n = NewItem();
	n->score = v;
	n->prev = NULL;

	unsigned int key = mBucket(v);

	n->next = Buckets[index][key].head;

	if (Buckets[index][key].head != NULL) {
		Buckets[index][key].head->prev = n;
	}
	Buckets[index][key].head = n;
	Buckets[index][key].count += 1;
}

SS* FindItem(int v, int index)
{
	unsigned int key = mBucket(v);
	for (SS* itr = Buckets[index][key].head; itr != NULL; itr = itr->next) {
		if (itr->score == v) return itr;
	}

	return NULL;
}

void RemoveItem(int v, int index)
{
	unsigned int key = mBucket(v);

	SS* n = FindItem(v, index);
	if (n == NULL) return;

	if (n->prev != NULL && n->next != NULL) {
		(n->next)->prev = n->prev;
		(n->prev)->next = n->next;
	}
	else if (n->prev != NULL && n->next == NULL) {
		(n->prev)->next = NULL;
	}
	else if (n->prev == NULL && n->next != NULL) {
		Buckets[index][key].head = n->next;
	}

	if (Buckets[index][key].count > 0) {
		Buckets[index][key].count -= 1;
	}	
	DeleteItem(n, index, key);
}

class Node
{
public:
	char name[MAX_NAME];
	int subjects[MAX_SUBJECT];
	int index;
	Node* prev;
	Node* next;
};

Node* mHashTable[MAX_HASH];

Node mBuff[MAX_BUFF];
int mIndex;

int sBuff[MAX_BUFF];
int mTop;

int mPop()
{
	if (mTop <= 0) {
		if (mIndex < MAX_BUFF) {
			return ++mIndex;
		}
		else
		{
			return -1;
		}
	}
	return --mTop;
}

void mPush(int idx)
{
	if (mTop < MAX_BUFF) {
		sBuff[mTop++] = idx;
	}
}

Node* mNew()
{
	int index = mPop();
	if (index == -1) return NULL;

	mBuff[index].name[0] = '\0';
	mBuff[index].index = index;
	for (int i = 0; i < MAX_SUBJECT; i++) {
		mBuff[index].subjects[i] = 0;
	}
	mBuff[index].prev = NULL;
	mBuff[index].next = NULL;

	return &mBuff[index];
}

void mDelete(Node* n, int key)
{
	mPush(n->index);

	n->name[0] = '\0';
	n->index = -1;
	for (int i = 0; i < MAX_SUBJECT; i++) {
		n->subjects[i] = 0;
	}
	n->prev = NULL;
	n->next = NULL;

	if (n == mHashTable[key]) {
		mHashTable[key] = NULL;
		n = NULL;
	}
}

Node* InsertNode(char * name, int * subjects)
{
	unsigned int key = mHash(name);

	Node* n = mNew();
	mstrcpy(n->name, name);
	for (int i = 0; i < MAX_SUBJECT; i++) {
		n->subjects[i] = subjects[i];
	}
	n->prev = NULL;
	n->next = mHashTable[key];

	if (mHashTable[key] != NULL) {
		mHashTable[key]->prev = n;
	}

	mHashTable[key] = n;

	return n;
}

Node* FindNode(char* str)
{
	unsigned int key = mHash(str);

	if (key == -1) return NULL;

	for (Node* itr = mHashTable[key]; itr != NULL; itr = itr->next) {
		if (0 == mstrcmp(itr->name, str)) {
			return itr;
		}
	}

	return NULL;
}

void DeleteNode(char* str)
{
	unsigned int key = mHash(str);
	if (key == -1) return;

	Node* n = FindNode(str);
	
	if (n->prev != NULL && n->next != NULL) {
		(n->next)->prev = n->prev;
		(n->prev)->next = n->next;
	}
	else if (n->prev != NULL && n->next == NULL) {
		(n->prev)->next = NULL;
	}
	else if (n->prev == NULL && n->next != NULL) {
		mHashTable[key] = n->next;
	}

	mDelete(n, key);
}

int main()
{
	return 0;
}