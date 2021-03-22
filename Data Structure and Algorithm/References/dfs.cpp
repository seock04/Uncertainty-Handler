/*
1 //number of test cases
8 1 // number of Vertices, Starting Vertex
1 2 // 1 2 means one can move from 1 to 2
1 3
2 4
2 5
4 8
5 8
3 6
3 7
6 8
7 8
-1 -1 // end
*/

#include <stdio.h>

#define MAX_VERTEX 30

int vertex;
int map[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];

void depthFirstSearch(int v)
{
	int i;
	visit[v] = 1;
	for (i = 1; i <= vertex; i++)
	{
		if (map[v][i] == 1 && !visit[i]) 
		{
			printf("%d ", i);
			depthFirstSearch(i);
		}
	}
}

int main(void)
{
	int T;
	int test_case;
	int i,j;
	int start;
	int v1;
	int v2;

	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)
	{
		for (i = 0; i < MAX_VERTEX; i++)
		{
			for (j = 0; j < MAX_VERTEX; j++)
			{
				map[i][j] = 0;
			}
			visit[i] = 0;
		}

		scanf("%d %d", &vertex, &start);

		while (true)
		{
			scanf("%d %d", &v1, &v2);
			if (v1 == -1 && v2 == -1)
			{
				break;
			}
			map[v1][v2] = map[v2][v1] = 1;
		}

		printf("#%d ", test_case);
		printf("%d ", start);
		depthFirstSearch(start);
		printf("\n");
	}

	return 0;
}
