#include "basic.h"

void Array(int *data, int *target, int d, int q) {
	int *dataA = malloc(sizeof(int) * d);

	int i = 0, j = 0;
	double build_time;
	double search_time;

	gettimeofday(&start, NULL);
	for(i = 0; i < d; i ++){
		dataA[i] = data[i];
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	build_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	gettimeofday(&start, NULL);
	for(i = 0; i < q; i ++) {
		for(j = 0; j < d; j ++) {
			if(target[i] == data[j]) {
				//printf("find %d !\n", data[j]);
				break;
			}
		}
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	search_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	printf("arr:\n");
	printf("building time: %f sec\n", build_time);
	printf("query time: %f sec\n", search_time);

	free(dataA);
}