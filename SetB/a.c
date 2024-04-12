#include <stdio.h>

int
main()
{
	int X = 2020, Y = 2021;
	int index = 1;
	for (;; X++) {
		int k = (X * X);
		for (Y = 2021; Y <= 2021 + (index * 100); Y++) {
			if (k - (2019 * 2019) == (Y * Y) - k) {
				// printf("%d %d %d\n", (2019 * 2019), k, (Y * Y));
				printf("%d %d\n", X, Y);
				return 0;
			}
		}
		index ++;
	}

}

