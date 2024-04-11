#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int N;	// 节点个数
int M;	// 边个数

#define MAX 1000

extern void Dijkstra(int n, int s, int G[][MAX], int E[][MAX], int S[], int* p, int* d);

int Graph[MAX][MAX];
int E[MAX][MAX];
int n[MAX];
int d[MAX];
int S[MAX];
int p[MAX];
int
main()
{
	scanf("%d %d", &N, &M);
	int i = 0;
	int s, e, t;
	for (; i < M; i++) {
		scanf("%d %d %d", &s, &e, &t);
		Graph[s][e] = t;
		E[s][n[s] ++] = e;
		printf("E[%d][%d] = %d\n", s, n[s] - 1, e);
	}
	printf("input over\n");

	Dijkstra(N, 1, Graph, E, S, p, d);
	for (i = 2; i <= N; i++) {
		printf("s -> %d: %d\n", i, d[i]);
	}
	return 0;
}

