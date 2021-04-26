// [H2024] 가족 구성원 찾기
//	 The below commented functions are for your reference. If you want 
//	 to use it, uncomment these functions.
/**/
int mstrcmp(const char a[], const char b[])
{
	int i;
	for (i = 0; a[i] != '\0'; ++i) if (a[i] != b[i]) return a[i] - b[i];
	return a[i] - b[i];
}

void mstrcpy(char dest[], const char src[])
{
	int i = 0;
	while (src[i] != '\0') { dest[i] = src[i]; i++; }
	dest[i] = src[i];
}

int mstrlen(const char a[])
{
	int i;
	for (i = 0; a[i] != '\0'; ++i);
	return i;
}

int dist[200][200];

struct Node {
	int index;
	int sex;
	char name[21];
	int spouse;
	int p[2];
	int child[200];
	int ch_cnt;
};
Node nodes[201];
int mcount;

int Que[201], Front, Rear;


int travelChild(int index, int cur, int distance, bool visited[], int targetDistance)
{
	int count = 0;
	for (int i = 0; i < 2; ++i) {
		if (nodes[cur].p[i] == -1 or visited[nodes[cur].p[i]] == true) continue;
		visited[nodes[cur].p[i]] = true;
		Que[++Rear] = nodes[cur].p[i];
		dist[index][cur] = distance;
		if (distance == targetDistance) count++;
	}

	for (int i = 0; i < nodes[cur].ch_cnt; ++i) {
		if (nodes[cur].child[i] == -1 or visited[nodes[cur].child[i]] == true) continue;

		visited[nodes[cur].child[i]] = true;
		Que[++Rear] = nodes[cur].child[i];
		dist[index][cur] = distance;
		if (distance == targetDistance) count++;
	}

	return count;
}

int bfs(int index, int targetDistance)
{
	bool visited[200] = { false };
	Front = Rear = -1;
	visited[index] = true;
	Que[++Rear] = index;
	int d = 0;
	dist[index][index] = d;

	int count = 0;
	while (Front != Rear) {
		int cur = Que[++Front];
		++d;
		count += travelChild(index, cur, d, visited, targetDistance);

		if (nodes[cur].spouse != -1) {
			int sp_index = nodes[cur].spouse;
			count += travelChild(index, sp_index, d, visited, targetDistance);
		}
	}

	return count;
}

int mHash(char name[])
{
	for (int i = 0; i < mcount; ++i) {
		if (mstrcmp(nodes[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}

int newNode(char name[], int sex)
{
	nodes[mcount].index = mcount;
	nodes[mcount].sex = sex;
	mstrcpy(nodes[mcount].name, name);
	
	nodes[mcount].spouse = -1;
	nodes[mcount].p[0] = -1;
	nodes[mcount].p[1] = -1;

	for (int i = 0; i < 200; ++i) {
		nodes[mcount].child[i] = -1;
	}
	nodes[mcount].ch_cnt = 0;
	
	return mcount++;
}

void init(char initialMemberName[], int initialMemberSex)
{
	newNode(initialMemberName, initialMemberSex);
}
bool isParentCandidate(int newMemberSex, int index)
{
	if (nodes[index].p[0] == -1) return true;
	if (nodes[index].p[1] != -1) return false;
	if (nodes[index].p[0] != -1 and nodes[nodes[index].p[0]].sex != newMemberSex) return true;

	return false;
}
bool isSpouseCandidate(int newMemberSex, int index)
{
	if (nodes[index].spouse != -1) return false;
	if (nodes[index].sex == newMemberSex) return false;
	 
	return true;
}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[])
{
	int index = mHash(existingMemberName);
	int newIndex = -1;
	if (relationship == 2) { // add child to existing
		newIndex = newNode(newMemberName, newMemberSex); 
		nodes[index].child[nodes[index].ch_cnt++] = newIndex; 

		int sp_index  = -1;
		if (nodes[index].spouse != -1) {
			sp_index = nodes[index].spouse;
			nodes[sp_index].child[nodes[sp_index].ch_cnt++] = newIndex;
		}

		nodes[newIndex].p[0] = index;
		nodes[newIndex].p[1] = sp_index;
	}
	else if (relationship == 1) { // add parent to existing
		if (!isParentCandidate(newMemberSex, index)) return false;
		
		newIndex = newNode(newMemberName, newMemberSex);
		int p_index = nodes[index].p[0] == -1 ? 0 : 1;
		
		if (p_index == 0) {
			nodes[index].p[p_index] = newIndex;
			nodes[newIndex].child[nodes[newIndex].ch_cnt++] = index;
		}
		else if(p_index == 1) {
			int ex_p_index = nodes[index].p[0];
			if (ex_p_index != -1 and nodes[ex_p_index].sex != nodes[newIndex].sex) {
				nodes[ex_p_index].spouse = newIndex;
				nodes[newIndex].spouse = ex_p_index;

				for (int i = 0; i < nodes[ex_p_index].ch_cnt; ++i) {
					nodes[newIndex].child[nodes[newIndex].ch_cnt++] = nodes[ex_p_index].child[i];
				}

				for (int i = 0; i < nodes[ex_p_index].ch_cnt; ++i) {
					int ch_index = nodes[ex_p_index].child[i];
					nodes[ch_index].p[1] = newIndex;
				}
			}
		}
		
	}
	else if (relationship == 0) { // add spouse to existing
		if (!isSpouseCandidate(newMemberSex, index)) return false;
		newIndex = newNode(newMemberName, newMemberSex);
		nodes[index].spouse = newIndex;
		nodes[newIndex].spouse = index;

		for (int i = 0; i < nodes[index].ch_cnt; ++i) {
			nodes[newIndex].child[nodes[newIndex].ch_cnt++] = nodes[index].child[i];
		}

		for (int i = 0; i < nodes[index].ch_cnt; ++i) {
			int ch_index = nodes[index].child[i];
			int p_index = nodes[ch_index].p[0] == -1 ? 0 : 1; // 불필요?
			nodes[ch_index].p[p_index] = newIndex;
		}
	}
	else {
		// error
	}

	if (newIndex == -1) return false;
	for (int i = 0; i < mcount; ++i) {
		bfs(i, 0);
	}
	
	return true;
}

int getDistance(char nameA[], char nameB[])
{
	int a_index = mHash(nameA);
	int b_index = mHash(nameB);

	return dist[a_index][b_index];
}

int countMember(char name[], int dist)
{
	int index = mHash(name);

	return bfs(index, dist);
}
