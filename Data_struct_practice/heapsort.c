#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//heapsort
//힙정렬 - 최대 힙 또는 최소 힙을 만들어 헤드값을 힙 트리의 크기가 0이 될때까지 뽑아낸다.

void heapify(long long arr[], long long arr_size, long long i) {
	long long largest = i;
	long long left = 2 * i + 1;
	long long right = 2 * i + 2;

	if (left < arr_size && arr[largest] < arr[left]) {//부모 노드 찾기
		largest = left;
	}
	if (right < arr_size && arr[largest] < arr[right]) {
		largest = right;
	}

	if (largest != i) { //부모와 바꾼 후 부모를 힙화
		long long temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		heapify(arr, arr_size, largest);
	}
}

void heapsort(long long arr[], long long arr_size) {
	for (long long i = arr_size/2-1; i >= 0; i--) {//배열을 힙화 (arr_size/2 이후의 노드들은 자식이 없음 그래서 힙화 안해도 됨)
		heapify(arr, arr_size, i);
	}
	for (long long i = arr_size - 1; i > 0; i--) {//힙을 정렬
		long long temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}

int main() {
	int TIME = 0;

	long long input;
	srand(time(NULL));
	scanf("%lld", &input);
	/* Timer on */
	clock_t start = clock();
	long long* arr = (long long*)malloc(sizeof(long long) * input);
	for (long long i = 0; i < input; i++) {
		arr[i] = rand() % (input*2);
	}
	heapsort(arr, input);
	for (long long i = 0; i < input; i++) {
		printf("%d ", arr[i]);
		if (i!= 0 && i % 20 == 0) {
			printf("\n");
		}
	}
	/* Timer off */
	TIME += ((int)clock() - start) / (CLOCKS_PER_SEC / 1000);

	printf("TIME : %d ms\n", TIME); /* ms 단위로 출력 */

}