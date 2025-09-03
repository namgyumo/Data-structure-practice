#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(long long arr[], long long left, long long mid, long long right) {//병합하기
	long long min = left, max = mid+1,i = 0;
	long long* bupper = (long long*)malloc(sizeof(long long) * (right - left + 1));
	while (min <= mid && max <= right) {
		if (arr[min] <= arr[max]) {
			bupper[i++] = arr[min++];
		}
		else {
			bupper[i++] = arr[max++];
		}
	}
	while (min <= mid) {//남은 원소 넣기
		bupper[i] = arr[min];
		min++;
		i++;
	}
	while (max <= right) {
		bupper[i] = arr[max];
		max++;
		i++;
	}
	for (long long i = 0,j = left; i < right - left + 1; i++,j++) {//원본에 삽입
		arr[j] = bupper[i];
	}
	free(bupper);
}

void merge_sort(long long arr[], long long left,long long right) {//분할하기
	if (left >= right)return;
	long long mid = (left + right) / 2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid + 1, right);
	merge(arr, left, mid, right);
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
		arr[i] = rand() % (input * 2);
	}
	merge_sort(arr, 0, input - 1);
	/*for (long long i = 0; i < input; i++) {
		printf("%d ", arr[i]);
		if (i != 0 && i % 20 == 0) {
			printf("\n");
		}
	}*/
	/* Timer off */
	TIME += ((int)clock() - start) / (CLOCKS_PER_SEC / 1000);

	printf("TIME : %d ms\n", TIME); /* ms 단위로 출력 */

}