#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int N;	// 节点个数
int M;	// 边个数

#define MAX 1000

extern void Dijkstra(int n, int s, int G[][MAX], bool* vis, int* d);

int Graph[MAX][MAX];
int d[MAX];
bool vis[MAX];
int
main()
{
	scanf("%d %d", &N, &M);

	printf("create arr over\n");
	memset(Graph, MAX * MAX, -1);
	int i = 0;
	int s, e, t;
	for (; i < M; i++) {
		scanf("%d %d %d", &s, &e, &t);
		Graph[s][e] = t;
	}
	printf("input over\n");
	i = 0;
	for (; i < N; i++) {
		vis[i] = false;
	}
	Dijkstra(N, 1, Graph, vis, d);
	i = 1;
	for (; i < N; i++) {
		printf("s -> %d: %d", i, d[i]);
	}
	return 0;
}

#define INF	((1 << 30) - 1)

void
Dijkstra(int n, int s, int G[][MAX], bool* vis, int* d)
{
	/*
	 * n -> 顶点个数
	 * s -> 源
	 * G -> 图的邻接矩阵
	 * vis -> 标记顶点是否被访问	vis[i] -> ture[i节点已被访问]
	 * d -> 存储源到其它顶点的最短距离	d[i] -> [s -> i 的最短距离]
	 */
	
	int i = 0;
	for (; i <= n; i++) {
		d[i] = INF;
	}
	d[s] = 0;
	i = 1;
	for (; i < n; i++) {
		int u = -1;
		int MIN = INF;
		int j = s;
		for (; j < n; j++) {
			// 直接用遍历去寻找最短路径节点
			if (vis[j] == false && G[i][j] > 0 && G[i][j] < MIN) {
				u = j;
				MIN = G[i][j];
			}
		}
		if (u == -1) {
			fprintf(stderr, "other vertex is not connectioned with S");
			return;
		}
		vis[u] = true;
		int v = 0;
		for (; v < n; v++) {
			if (vis[v] == false && d[u] + G[u][v] < d[v]) {
				d[v] = d[u] + G[u][v];
			}
		}
	}
}


