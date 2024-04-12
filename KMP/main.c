#include <stdio.h>
#include <string.h>

#define MAX 1000

char T[MAX];
char S[MAX];

int IT[MAX];

int lent, lens;

int
main()
{
	scanf("%s", S);
	scanf("%s", T);

	lent = strlen(T);
	lens = strlen(S);

	int i;
	int j;
	IT[0] = 0;
	// 语义: 第i个字符匹配失败后T的指针跳到i - IT[i]上
	IT[1] = 0;
	for (i = 1; (i + 1) < lent; i++) {
		for (j = IT[i]; j < lent; j++) {
			if (T[i] != T[j]) {
				break;
			}
		}
		IT[i + 1] = j;
	}
	for (i = 0; i < lent; i++) {
		printf("%d ", IT[i]);
	}
	printf("\n");
	// i -> S指针
	// j -> T指针
	int max = 0;
	i = 0;
	j = 0;
	int k = 0;
	while (i < lens) {
		for (; j < lent; j++) {
			if (T[j] == S[i]) {
				i ++;
			} else {
				j = IT[j];
				k = j + 1;
				max = k > max ? k : max;
				i += (IT[j] == 0) ? 1 : 0;
				break;
			}
		}
		if (j == lent) {
			printf("parent right at %d\n", i);
			break;
		}
	}
	printf("over\n");
	return 0;
}

