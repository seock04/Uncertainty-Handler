#include<iostream>
using namespace std;

#define MAX_NAME 11
typedef unsigned long long ll;

struct ELEMENT {
	int id;
	ll lname;
	char name[MAX_NAME];
};

const unsigned int MAX_HEAP = 100001;

ELEMENT elements_pool[MAX_HEAP];
ELEMENT* mheap[MAX_HEAP];

unsigned int item_count;
unsigned int heap_size;

int id_to_pos[MAX_HEAP];

ll strToNum(char name[]) 
{
	register int i = 0;

	ll ret = 0;

	while (name[i]) {
		ret = (ret << 5) + (name[i] - 'a' + 1);
		i++;
	}

	for (; i < 10; i++) {
		ret = (ret << 5);
	}

	return ret;
}

void mystrcpy(char src[], char dest[])
{
	int i = 0;
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	src[i] = 0;
}

ELEMENT* newItem(int id, char name[])
{
	ELEMENT* n = &elements_pool[item_count++];
	n->id = id;
	n->lname = strToNum(name);
	mystrcpy(name, n->name);

	return n;
}

void init()
{
	item_count = 0;
	heap_size = 0;
}

void clear() {
	init();
}

bool needSwap(ELEMENT* parent, ELEMENT* child)
{
	if (parent->lname < child->lname) return true;
	else if (parent->lname == child->lname and parent->id > child->id) {
		return true;
	}
	return false;
}

void update(int pos)
{
	register unsigned int parent;
	register unsigned int child = pos;
	register ELEMENT* tmp;

	while (child > 1) {
		parent = child / 2;
		if (parent < 1) break;
		if (needSwap(mheap[parent], mheap[child]) == true) {
			tmp = mheap[child];
			mheap[child] = mheap[parent];
			mheap[parent] = tmp;

			id_to_pos[mheap[child]->id] = child;
			id_to_pos[mheap[parent]->id] = parent;
		}
		child = parent;
	}
}

void downdate(int pos)
{
	register unsigned int parent = pos;
	register unsigned int child;
	register ELEMENT* tmp;

	while (parent <= heap_size) {
		child = parent * 2;
		if (child > heap_size) break;
		if (child + 1 <= heap_size and needSwap(mheap[child], mheap[child + 1]) == true) {
			child = child + 1;
		}
		if (needSwap(mheap[parent], mheap[child]) == false) break;
		
		tmp = mheap[child];
		mheap[child] = mheap[parent];
		mheap[parent] = tmp;

		id_to_pos[mheap[child]->id] = child;
		id_to_pos[mheap[parent]->id] = parent;
		
		parent = child;
	}
}

void push(int idx, char name[])
{
	ELEMENT* n = newItem(idx, name);
	int pos = ++heap_size;
	mheap[pos] = n;

	update(pos);
}

int pop()
{
	int ret = mheap[1]->id;

	mheap[1] = mheap[heap_size];
	id_to_pos[mheap[1]->id] = 1;
	heap_size--;

	downdate(1);

	return ret;
}

void mod(int idx, char name[])
{
	int pos = id_to_pos[idx];
	mheap[pos]->lname = strToNum(name);
	mystrcpy(name, mheap[pos]->name);
	update(pos);
	downdate(pos);
}
