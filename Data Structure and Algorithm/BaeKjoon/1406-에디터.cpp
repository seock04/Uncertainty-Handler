#include<iostream>
using namespace std;

struct CH {
	char c;
	CH* prev;
	CH* next;
};
CH chpool[600010];
int chcnt = 0;

CH* head = nullptr;
CH* cur = nullptr;

CH* getNewCh(char ch)
{
	chpool[chcnt].c = ch;
	chpool[chcnt].prev = nullptr;
	chpool[chcnt].next = nullptr;

	return &chpool[chcnt++];
}
void Init()
{
	head = getNewCh('*');
	cur = head->next;
}

void AddToR(char c)
{
	CH* pc = getNewCh(c);
	if (!cur) {
		head->next = pc;
		pc->prev = head;
		cur = pc;
	}
	else {
		CH* left = cur->prev;
		CH* right = cur->next;

		if (right) {
			right->prev = pc;
			cur->next = pc;

			pc->prev = cur;
			pc->next = right;
		}
		else {
			cur->next = pc;
			pc->prev = cur;
		}
		cur = pc;
	}
}

void MoveL()
{
	if (cur->prev) cur = cur->prev;
}

void MoveR()
{
	if (cur->next) cur = cur->next;
}

void removeCh()
{
	CH* r;
	if (cur == head) return;

	if (cur) r = cur;
		

	CH* left = r->prev;
	CH* right = r->next;
	if (left) {
		left->next = right;
	}
	
	if (right) {
		right->prev = left;
	}
	r = nullptr;
	cur = left;
}

void AddToL(char c)
{
	CH* pc = getNewCh(c);
	if (cur == head) {
		CH* right = head->next;
		if (right) {
			CH* l = right->prev;
			
			l->next = pc;
			right->prev = pc;

			pc->prev = l;
			pc->next = right;
		}
		else {
			head->next = pc;
		}
		cur = pc;
	}
	else {
		CH* right = cur->next;

		if (right) {
			right->prev = pc;
			cur->next = pc;

			pc->prev = cur;
			pc->next = right;
		}
		else {
			cur->next = pc;
			pc->prev = cur;
		}
		cur = pc;		
	}
}

int main()
{
	Init();
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		AddToR(s[i]);
	}
	int N;
	cin >> N;

	char command;

	for (int i = 0; i < N; ++i) {
		cin >> command;
		if (command == 'L') {
			MoveL();
		}
		else if (command == 'D') {
			MoveR();
		}
		else if (command == 'B') {
			removeCh();
		}
		else if (command == 'P') {
			char cc;
			cin >> cc;
			AddToL(cc);
		}
	}

	for (CH* itr = head->next; itr != nullptr; itr = itr->next) {
		cout << itr->c;
	}
	return 0;
}
