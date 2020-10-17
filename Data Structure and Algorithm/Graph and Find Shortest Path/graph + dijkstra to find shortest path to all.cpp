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
	for (int i = 1; i <= N; i++) { //range of vertex 
		visited[i] = false;
	}
}

void Init()
{
	for (int i = 0; i < MAX; i++) {
		dist[i] = INF;
		parent[i] = i;
		for (int j = 0; j < MAX; j++) {
			map[i][j] = INF;
		}
	}

	resetVisited();
}

int getNearest()
{
	int minValue = INF;
	int minNode = 0;

	for (int i = 1; i <= N; i++) {
		if (!visited[i]
			&& (dist[i] < minValue)) {
			minValue = dist[i];
			minNode = i;
		}
	}
	return minNode;
}


void dijkstra()
{
	dist[src] = 0;

	for (int i = 1; i <= N; i++) {
		int nearest = getNearest();
		visited[nearest] = true;

		for (int adj = 1; adj <= N; adj++) {
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

	for (int i = 1; i <= N; i++) {

		cout << src << " to " << i << "\n";
		cout << "distance: " << dist[i] << '\n';

		int parentNode = parent[i];
		while (parentNode != src) {
			cout << parentNode << " <- ";
			parentNode = parent[parentNode];
		}
		cout << "\n----------------------------\n";
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

	src = 1;
	dijkstra();
	printShortestPath();

	return 0;
}
