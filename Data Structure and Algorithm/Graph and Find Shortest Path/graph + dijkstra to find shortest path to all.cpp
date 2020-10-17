#include<iostream>
using namespace std;

#define MAX 200

#define INF 9999

int N;
int map[MAX][MAX];
int dist[MAX];
int parent[MAX];
bool visited[MAX];

int src;

void resetVisited()
{
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
}

void Init()
{
	for (int i = 0; i < N; i++) {
		dist[i] = INF;
		parent[i] = i;
		for (int j = 0; j < N; j++) {
			map[i][j] = INF;
		}
	}

	resetVisited();
}

int getNearest()
{
	int minValue = INF;
	int minNode = 0;

	for (int i = 0; i < N; i++) {
		if (!visited[i]
			&& (dist[i]< minValue)) {
			minValue = dist[i];
			minNode = i;
		}
	}
	return minNode;
}


void dijkstra()
{
	dist[src] = 0;
	
	for (int i = 0; i < N; i++) {
		int nearest = getNearest();
		visited[nearest] = true;

		for (int adj = 0; adj < N; adj++) {
			if (map[nearest][adj] != INF
				&& dist[adj] > dist[nearest] + map[nearest][adj]) {
				dist[adj] = dist[nearest] + map[nearest][adj];
				parent[adj] = nearest;
			}
		}
	}
}

void printShortestPath()
{
	cout << "=======================";
	cout << "\n";
	cout << src << " to " << i << "\n";
	cout << "distance: " << dist[i] << '\n';
	cout << "Path to " << i;
	for (int i = 0; i < N; i++) {
		int parentNode = parent[i];
		while (parentNode != src) {
			cout << parentNode << " <- ";
			parentNode = parent[parentNode];
		}
		cout << "----------------------------\n";
	}
}

int main()
{
	cin >> N;
	
	int edges;
	cin >> edges;

	int s, e, v;
	Init();
	for (int i = 0; i < edges; i++) {
		cin >> s >> e >> v;
		map[s][e] = v;
		map[e][s] = v;
	}

	src = 0;
	dijkstra();
	printShortestPath();

}
