#include <stdio.h>
#include <stdbool.h>

#define NUM 2019

bool
isPrime(int i)
{
	int k = 2;
	for (; k < i; k++) {
		if (0 == (i % k)) {
			break;
		}
	}
	// printf("%d %d\n", k, i);
	return (k == i);
}

int
main()
{
	int i = 0;
	int n;
	int ans = 0;
	for (i = 2; i < (NUM / 2); i++) {
		n = NUM - i;
		if (isPrime(i) && isPrime(n)) {
			// printf("%d + %d = %d\n", i, n, NUM);
			ans ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

