// start at 11:40

// 应该使用Dijkstra算法求最短路径
// 复习: Dijkstra算法
// 	有一个源、终点、最小优先队列
// 	首先将与源连接的路径放入队列
// 	不断弹出最小路径
// 	每到达一个节点，把节点相关的路径放入队列

#include <stdio.h>

#define MAXN 1010
#define MAXP 10010

typedef unsigned long long ULL;

ULL C[MAXN];	// 隔离天数
ULL P[MAXN][MAXN];	// P[i][j] ==> i -> j耗时P[i][j]时间
ULL I[MAXN];		// I[i] ==> 输入时的指针
ULL E[MAXN][MAXN]; 	// E[i][j] ==> 与i相关的边i -> E[i][j]
ULL T[MAXN];		// T[i] ==> s -> i 的最小时间

struct PQ;	// 最小优先队列	应该包含起点s、终点e、时间t
void push(struct* PQ, ULL s, ULL e, ULL t);
void pop(struct* PQ, ULL* s, ULL* e, ULL* t);
bool isEmpty(struct* PQ);

ULL N, M;

int
main()
{
	scanf("%llu %llu", &N, &M);
	
	int i = 0;
	for (; i < N; i++) {
		scanf("%llu", &C[i]);
	}
	i = 0;
	ULL ta, tb, tt;
	for (; i < M; i++) {
		scanf("%llu %llu %llu", &ta, &tb, &tt);
		P[ta][tb] = tt;
		E[ta][I[ta]++] = tb;
	}
	
	struct PQ pq;
	i = 0;
	for (; i < I[1]; i++) {
		ULL e = E[1][i];
		push(&pq, 1, e, P[1][e]);
	}
	
	ULL s, e, t;
	while (!isEmpty(pq)) {
		pop(&pq, &s, &e, &t);
		
		if (T[e] == 0) {
			// 第一次到达该节点
			T[e] = t + T[s];
			// 把与节点有关的边插入队列
			i = 0;
			ULL ee;
			for (; i < I[e]; i++) {
				ee = E[e][i];
				push(&pq, e, ee, P[e][ee] + C[e]);
			}
		} else if (T[e] > (t + T[s])) {
			// 得出s -> e更短的路径
			// 更新T表
			T[e] = t + T[s];
			// 更新队列中的相关边
			i = 0;
			ULL ee;
			for (; i < I[e]; i++) {
				ee = E[e][i];
				if (T[ee] == 0 || T[ee] > (T[e] + 
			}
		}
	}

}

