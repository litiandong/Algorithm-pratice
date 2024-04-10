#include <stdio.h>


int
main()
{
	int s = 0, f = 0, m = 0;
	for (; s <= 12; s ++) {
		f = 0;
		for (; f <= 60 ; f ++) {
			m = 0;
			for (; m <= 60; m ++) {
				if ((60 * s) == ((121 * f) - (294 * m)) ||
						(60 * s) == ((294 * m) - (121 * f))) {
					printf("%d %d %d\n", s, f, m);
				}
			}
		}
	}
}

