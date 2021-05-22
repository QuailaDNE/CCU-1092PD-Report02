#include "basic.h"

struct lnode {
	int num;
	struct lnode *next;
};

struct lnode *L_insert(struct lnode *L, int num)
{
	struct lnode *p = (struct lnode *)malloc(sizeof(struct lnode));
	p -> num = num;
	p -> next = L;
	return p;
}

struct lnode *L_find(struct lnode *L, int num)
{
	struct lnode *p = L;
	while(p) {
		if(p -> num == num) {
			//printf("find %d!\n", p -> num);
			return p;
		}
		p = p -> next;
	}
	return NULL;
}

void LinkedList(int *data, int *target, int d, int q) {
	struct lnode *ll = NULL;
	int i, tmp;

	double build_time;
	double search_time;

	gettimeofday(&start, NULL);
	for(i = 0; i < d; i ++){
		ll = L_insert(ll, data[i]);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	build_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	gettimeofday(&start, NULL);
	for(i = 0; i < q; i ++){
		L_find(ll, target[i]);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	search_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	printf("ll:\n");
	printf("building time: %f sec\n", build_time);
	printf("query time: %f sec\n", search_time);
}