#include <stdio.h>

void heap_sort(int* arr, int len, int begin);

#define MAX 10000

int N;
int arr[MAX];

int
main()
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 1; i <= N; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	heap_sort(arr, N, 1);
	return 0;
}

#define LEFT(i) (2 * i)
#define RIGHT(i)	(2 * i + 1)
#define PARENT(i)	(i / 2)

void
make_heap(int* arr, int len, int begin)
{
	int victor = begin;
	int i = begin;
	do {
		i = victor;
		if (arr[i] > arr[LEFT(i)]) {
			victor = LEFT(i);
		}
		if (arr[victor] > arr[RIGHT(i)] && RIGHT(i) <= len) {
			victor = RIGHT(i);
		}
		if (victor != i) {
			int t = arr[i];
			arr[i] = arr[victor];
			arr[victor] = t;
		}
	} while (victor != i && LEFT(victor) <= len);
}

void
heap_sort(int* arr, int len, int begin)
{
	int capacity = len;
	int i;
	while (len > 0) {
		for (i = (len / 2); i >= 1; i--) {
			make_heap(arr, len, i);
		}
		int t = arr[1];
		arr[1] = arr[len];
		arr[len] = t;
		len -= 1;
	}
	for (i = 1; i <= capacity; i++) {
		printf("%d\n", arr[i]);
	}
}

