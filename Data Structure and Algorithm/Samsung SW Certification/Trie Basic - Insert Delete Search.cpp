#include<iostream>
using namespace std;

#define ALPHABETS 26
#define MAX_TRIE_CHAR 1000000

class TrieNode {
public:
	char ch;
	TrieNode* children[ALPHABETS];
	int prefix_cnt;
	int termination_cnt;
};

TrieNode nodePool[MAX_TRIE_CHAR];
int poolCnt;

TrieNode* root;

void Init()
{
	root = &nodePool[poolCnt++];
	root->ch = '*';
	for (int i = 0; i < ALPHABETS; ++i) {
		root->children[i] = NULL;
	}
	root->prefix_cnt = 0;
	root->termination_cnt = 0;
}

TrieNode* createNode(char c)
{
	nodePool[poolCnt].ch = c;
	for (int i = 0; i < ALPHABETS; ++i) {
		nodePool[poolCnt].children[i] = NULL;
	}
	nodePool[poolCnt].prefix_cnt = 0;
	nodePool[poolCnt].termination_cnt = 0;

	return &nodePool[poolCnt++];
}

void TrieNodeInsert(const char str[])
{
	TrieNode* cur = root;
	int index;
	for (int i = 0; str[i] != '\0'; ++i) {
		index = str[i] - 'a';
		if (cur->children[index] == NULL) {
			cur->children[index] = createNode(str[i]);
		}
		cur->children[index]->prefix_cnt += 1;
		cur = cur->children[index];
	}
	cur->termination_cnt += 1;
}

int TrieNodeSearch(const char str[])
{
	TrieNode* cur = root;
	int index;
	for (int i = 0; str[i] != '\0'; ++i) {
		index = str[i] - 'a';
		if (cur->children[index] == NULL || cur->children[index]->prefix_cnt == 0) {
			return false;
		}
		cur = cur->children[index];
	}
	return cur->termination_cnt;
}

int PrefixCount(const char str[])
{
	TrieNode* cur = root;
	int index;
	for (int i = 0; str[i] != '\0'; ++i) {
		index = str[i] - 'a';
		if (cur->children[index] == NULL || cur->children[index]->prefix_cnt == 0) {
			return 0;
		}
		cur = cur->children[index];
	}
	return cur->prefix_cnt;
}

bool Remove(const char str[])
{
	if (TrieNodeSearch(str)) {
		TrieNode* cur = root;
		int index;
		for (int i = 0; str[i] != '\0'; ++i) {
			index = str[i] - 'a';
			cur->children[index]->prefix_cnt -= 1;
			cur = cur->children[index];
		}

		if (cur->termination_cnt > 0) {
			cur->termination_cnt -= 1;
			return true;
		}
	}

	return false;
}


int main()
{
	Init();

	TrieNodeInsert("abc");
	TrieNodeInsert("abc");
	TrieNodeInsert("abc");
	TrieNodeInsert("abcdd");
	TrieNodeInsert("ack");
	TrieNodeInsert("kkk");
	TrieNodeInsert("bbbc");
	TrieNodeInsert("bbbce");

	if (TrieNodeSearch("bbbc")) {
		cout << "found!" << "\n";
	}

	return 0;
}