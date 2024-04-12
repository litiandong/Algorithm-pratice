#include <stdio.h>
#include <string.h>

// KMP算法相似

#define MAX 1000

char S[MAX];
char T[MAX];
int lens;
int lent;
// IT[i] -> 第(i + 1)个字符匹配失败后T字符串指针后移IT[i]个单位
int IT[MAX];

int 
getAns(int begin)
{
	int i;
	int j;
	IT[begin] = begin;
	// 语义: 第i个字符匹配失败后T的指针跳到i - IT[i]上
	IT[begin + 1] = begin;
	for (i = (begin + 1); (i + 1) < lent; i++) {
		for (j = IT[i]; j < lent; j++) {
			if (T[i] != T[j]) {
				break;
			}
		}
		IT[i + 1] = j;
	}
	for (i = begin; i < lent; i++) {
		printf("%d ", IT[i]);
	}
	printf("\n");
	// i -> S指针
	// j -> T指针
	int max = 0;
	i = begin;
	j = begin;
	int k = 0;
	while (i <= (lens - (lent - begin))) {
		for (; j < lent; j++) {
			if (T[j] == S[i]) {
				i ++;
			} else {
				k = (j - begin);
				j = IT[j];
				max = k > max ? k : max;
				i += (IT[j] == begin) ? 1 : 0;
				break;
			}
		}
		if (j == lent)
			break;
	}
	return max;
}

int
main()
{
	scanf("%s", S);
	scanf("%s", T);
	
	lens = strlen(S);
	lent = strlen(T);

	int i = 0, ans = 0, max = 0;
	for (; i < lent; i++) {
		if (max >= (lent - i))
			break;
		int ret = getAns(i);
		max = max > ret ? max : ret;
	}
	ans = lent - max;
	printf("%d\n", ans);


}

