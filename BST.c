#include "basic.h"

struct tnode
{
	int num;
	struct tnode *LChild;
	struct tnode *RChild;
};

struct tnode *BST_insert(struct tnode *T, int num) {
	if(T == NULL) {
		struct tnode *p = (struct tnode *)malloc(sizeof(struct tnode));
		p -> num = num;
		p -> LChild = NULL;
		p -> RChild = NULL;

		return p;
	}

	if(num < T -> num) {
		T -> LChild = BST_insert(T -> LChild, num);
	}
	else {
		T -> RChild = BST_insert(T -> RChild, num);
	}

	return T;
}

struct tnode *BST_find(struct tnode *T, int num) {
	struct tnode *p = T;
	while(p) {
		if(num == p -> num) {
			//printf("find %d!\n", p -> num);
			return p;
		}
		else if(num < p -> num) {
			p = p -> LChild;
		}
		else {
			p = p -> RChild;
		}
	}

	return NULL;
}

void BST(int *data, int *target, int d, int q) {
	struct tnode *bst = NULL;
	int tmp, i;

	double build_time;
	double search_time;

	gettimeofday(&start, NULL);
	for(i = 0; i < d; i ++) {
		bst = BST_insert(bst, data[i]);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	build_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	gettimeofday(&start, NULL);
	for(i = 0; i < q; i ++){
		BST_find(bst, target[i]);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	search_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	printf("bst:\n");
	printf("building time: %f sec\n", build_time);
	printf("query time: %f sec\n", search_time);
}