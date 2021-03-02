/* 컴퓨터 시스템에 그래프는 연결되어 있는 객체간의 관계를 표현할 수 있는 자료구조다. 방향성이 없는 그래프의 V개의 정점과 E개의 간선 정보가 주어진다. 첫째 줄에는 V와 E의 갯수, 정점의 정보를 묻는 쿼리의 갯수가 주어지고 둘째 줄부터 간선의 정보(연결된 정점의 번호쌍)가 주어진다. 그 다음 줄에는 정점의 인접정점들이 무엇인지 묻는 쿼리가 정점번호로 주어진다. 정점의 번호는 0~V-1까지 이며, 간선정보는 오름차순으로 나열되어 주어진다. 또한 중복 간선은 존재하지 않는다. 입력으로 주어지는 쿼리의 정점에 인접한 정점들을 각 줄에 출력하라. (2<=V<=100, 1<=E<=1000) */

/* 2 6 7 3 // 정점갯수, 간선갯수 쿼리(질문)갯수 0 1 // 간선정보 0 - 1 0 2 0 3 1 2 1 4 3 4 4 5 0 // 쿼리(질문): 정점 번호 2 4 9 10 3 0 1 0 2 0 6 1 3 1 4 1 7 2 4 4 5 6 7 7 8 0 1 7 */

#include <stdio.h>
#include <malloc.h>

typedef struct adjlistNode
{
	int vertex;
	adjlistNode *next;
} AdjlistNode;

typedef struct
{
	int num_members;
	AdjlistNode *head;
	AdjlistNode *tail;
} AdjList;

typedef struct
{
	int num_vertices;
	AdjList * adjListArr;
} Graph;

AdjlistNode * createNode(int v)
{
	AdjlistNode * newNode = (AdjlistNode *)malloc(sizeof(AdjlistNode));

	newNode->vertex = v;
	newNode->next = NULL;

	return newNode;
}

Graph * createGraph(int n)
{

	Graph * graph = (Graph *)malloc(sizeof(Graph));
	graph->num_vertices = n;

	graph->adjListArr = (AdjList *)malloc(n * sizeof(AdjList));

	for (int i = 0; i < n; i++)
	{
		graph->adjListArr[i].head = graph->adjListArr[i].tail = NULL;
		graph->adjListArr[i].num_members = 0;
	}

	return graph;
}

void destroyGraph(Graph * graph)
{
	if (graph)
	{
		if (graph->adjListArr)
		{
			for (int v = 0; v < graph->num_vertices; v++)
			{
				AdjlistNode * adjListPtr = graph->adjListArr[v].head;
				while (adjListPtr)
				{
					AdjlistNode * tmp = adjListPtr;
					adjListPtr = adjListPtr->next;
					free(tmp);
				}
			}
			free(graph->adjListArr);
		}
		free(graph);
	}
}

void addEdge(Graph *graph, int src, int dest)
{
	AdjlistNode * newNode = createNode(dest);
	if (graph->adjListArr[src].tail != NULL) 
	{
		graph->adjListArr[src].tail->next = newNode;
		graph->adjListArr[src].tail = newNode;
	}
	else
	{
		graph->adjListArr[src].head = graph->adjListArr[src].tail = newNode;
	}
	graph->adjListArr[src].num_members++;

	newNode = createNode(src);
	if (graph->adjListArr[dest].tail != NULL) 
	{
		graph->adjListArr[dest].tail->next = newNode;
		graph->adjListArr[dest].tail = newNode;
	}
	else
	{
		graph->adjListArr[dest].head = graph->adjListArr[dest].tail = newNode;
	}
	graph->adjListArr[dest].num_members++;
}

void displayGraph(Graph * graph, int i)
{

	AdjlistNode * adjListPtr = graph->adjListArr[i].head;
	while (adjListPtr)
	{
		printf("%d ", adjListPtr->vertex);
		adjListPtr = adjListPtr->next;
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	int T, V, E, Q, sv, ev;

	scanf("%d", &T);
	
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d %d %d", &V, &E, &Q);

		Graph * graph = createGraph(V);

		for (int i = 0; i < E; i++)
		{
			scanf("%d %d", &sv, &ev);
			addEdge(graph, sv, ev);
		}
		printf("#%d\n", test_case);

		for (int i = 0; i < Q; i++)
		{
			scanf("%d", &sv);
			displayGraph(graph, sv);
		}
	}

	return 0;
}
