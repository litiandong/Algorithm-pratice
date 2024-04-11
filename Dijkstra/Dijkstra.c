#include <stdio.h>
#include <stdbool.h>

#define INF	((1 << 30) - 1)

#define MAX 1000
// v.d => 最短距离的估计值
// v.p => 最短路径的前驱点

/*
 * v => 进行松弛操作的结点
 * u => 假设更短路径的前驱
 * p, d => 前驱结点数组，假设最短路径数组
 * w => (u -> v) 的权重
 */


void relax(int v, int u, int* d, int* p, int w);
// 最小优先队列
void Min_Heap_Init();
// 把以e为终点的边加入到最小优先队列中
void Min_Heap_push(int e, int w);
// 弹出队列中权重最小的边的终点
int Min_Heap_pop();
// 队列中的成员是否耗尽了
bool Min_Heap_IsEmpty();

void
Dijkstra(int n, int s, int G[][MAX], int E[][MAX], int S[], int* p, int* d)
{
	/*
	 * n -> 顶点个数
	 * s -> 源
	 * G -> 图的二维数组表示
	 * E -> 顶点的相关边
	 * S -> 顶点是否已经找到最短路径
	 * p -> 前驱结点数组
	 * d -> s到结点i的猜想最短距离
	 */
	
	// initialize vertex
	int i;
	for (i = 0; i <= n; i++) {
		d[i] = INF;
	}
	d[s] = 0;
	i = 1;

	// 最小优先队列
	Min_Heap_Init();

	int u;
	
	for (i = 0; E[s][i] > 0; i ++) {
		u = E[s][i];
		Min_Heap_push(u, G[s][u]);
		d[u] = G[s][u];
	}
	int v;
	while (!Min_Heap_IsEmpty()) {
		u = Min_Heap_pop();
		printf("%d\n", u);
		S[u] = 1;
		for (i = 0; E[u][i] != 0; i++) {
			v = E[u][i];
			printf("-> %d [%d]\n", v, G[u][v]);
			Min_Heap_push(v, G[u][v]);
			relax(v, u, d, p, G[u][v]);
		}
	}
}

void
relax(int v, int u, int* d, int* p, int w)
{
	if (d[v] > (d[u] + w)) {
		p[v] = u;
		d[v] = d[u] + w;
	}
}

int V[MAX];
int W[MAX];
int len;

#define LEFT(i)		(2 * i)
#define RIGHT(i)	((2 * i) + 1)
#define PARENT(i)	(i / 2)

void 
Min_Heap_Init()
{
	len = 0;
}

void
Heap_ify()
{
	if (Min_Heap_IsEmpty())
		return;
	int i;
	int victor;
	for (i = PARENT(len); i >= 1; i--) {
		victor = i;
		do {
			i = victor;
			if (W[i] > W[LEFT(i)]) {
				victor = LEFT(i);
			}
			if (RIGHT(i) <= len && W[victor] > W[RIGHT(i)]) {
				victor = RIGHT(i);
			}
			if (victor != i) {
				int _w = W[i], _v = V[i];
				W[i] = W[victor];
				V[i] = V[victor];
				W[victor] = _w;
				V[victor] = _v;
			}
		} while (victor != i && LEFT(victor) <= len);
	}
}

void
Min_Heap_push(int u, int w)
{
	// 忽略len大于MAX的情况
	len += 1;
	V[len] = u;
	W[len] = w;
}

// 每次弹出前，要维护最小堆的性质(Heap_Ify)
int
Min_Heap_pop()
{
	Heap_ify();
	int ret = V[1];
	W[1] = W[len];
	V[1] = V[len];
	len --;
	return ret;
}

bool
Min_Heap_IsEmpty()
{
	return len == 0;
}


