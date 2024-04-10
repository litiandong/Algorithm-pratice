#include <stdio.h>

#define MAX 10000

void quick_sort(int* arr, int len);

int arr[MAX];
int N;

int
main()
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	quick_sort(arr, N);
	return 0;
}


