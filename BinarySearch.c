#include "basic.h"

void binarySearch(int target, int *data, int dataCnt) {
	int lower, upper, mid;
	lower = 0;
	upper = dataCnt - 1;

	int i = 0;
	while(lower <= upper && (i < dataCnt)) {
		mid = (lower + upper) / 2;
		if(target == data[mid]) {
			//printf("find %d!\n", data[mid]);
			break;
		}
		else if(target < data[mid]) {
			upper = mid;
		}
		else if(target > data[mid]) {
			lower = mid;
		}
		i ++;
	}
}

int cmpnum(void const *a, void const *b) { 
    return (*(int *)a - *(int *)b);
}

void BinarySearchArray(int *data, int *target, int d, int q) {
	int i = 0, j = 0, tmp;
	double build_time;
	double search_time;

	int *dataA = malloc(sizeof(int) * d);

	gettimeofday(&start, NULL);
	for(i = 0; i < d; i ++){
		dataA[i] = data[i];
	}
	qsort(dataA, d, sizeof(int), cmpnum);
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	build_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	gettimeofday(&start, NULL);
	for(i = 0; i < q; i ++) {
		binarySearch(target[i], data, d);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	search_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	printf("bs:\n");
	printf("building time: %f sec\n", build_time);
	printf("query time: %f sec\n", search_time);
}