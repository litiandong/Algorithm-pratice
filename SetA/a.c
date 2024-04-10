// 2022拆分为10个不同正整数只和，求拆分方法

#include <stdio.h>

long long dp[4000][20]; // dp[i][j] 代表 i拆分为j个整数和的方法数

int
main()
{
	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	long long i = 1;
	long long j = 1;
	for (; i <= 2022; i ++) {
		j = 2;
		dp[i][1] = 1;
		for (; j <= 11 && j < i; j++) {
			long long sum = 0;
			long long k = 1;
			for (; k <= (long long)(i / j); k++) {
				sum += dp[i - k][j - 1];
			}
			dp[i][j] = sum;
		}
	}
	printf("%lld\n", dp[10][3]);
	printf("%lld\n", dp[2022][10]);
}

