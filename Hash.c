#include "basic.h"

struct dnode {
	char key[DEFMAXHASH];
	int cnt;
	struct dnode *next;
};

struct dnode *l_insert(struct dnode *l, char *key) {
	struct dnode *p;
	p = (struct dnode *)malloc(sizeof(struct dnode));
	strcpy(p -> key, key);
	p -> cnt = 1;
	p -> next = l;
	return p;	
}

struct dnode *l_find(struct dnode *l, char *key) {
	struct dnode *p;
	if(l == NULL) return NULL;

	p = l;
	while(p) {
		if(strcmp(p -> key, key) == 0)
			//printf("find %s!\n", p -> key);
			return p;
		p = p -> next;
	}

	return NULL;
}

int32 hash65(char *key) {
	int32 hv;
	char *ptr;
	ptr = key;
	hv = 0;
	while(*ptr) {
		hv = hv * 65 + *ptr + 1;
		ptr ++;
	}
	return hv;
}

void hash_insert(struct dnode **hTab, int maxHash, char *key) {
	int32 hv;
	struct dnode *dptr;
	hv = hash65(key) % maxHash;
	dptr = hTab[hv];
	hTab[hv] = l_insert(dptr, key);
}

struct dnode *hash_find(struct dnode **hTab, int maxHash, char *key) {
	int32 hv;
	struct dnode *dptr;
	hv = hash65(key) % maxHash;
	dptr = hTab[hv];

	return l_find(dptr, key);
}

void Hash(int *data, int *target, int d, int q) {
	srand(time(NULL));
	double build_time;
	double search_time;

	struct dnode **hTab;
	struct dnode *dptr;
	int maxHash, i, tmp;
	char *str = malloc(sizeof(char) * DEFMAXHASH);

	// initialize hash table
	maxHash = DEFMAXHASH;
	hTab = (struct dnode **)malloc(sizeof(struct dnode *) * maxHash);

	for(int i = 0; i < maxHash; i ++) {
		hTab[i] = NULL;
	}

	gettimeofday(&start, NULL);
	for(i = 0;i < d; i ++) {
		sprintf(str, "%d", data[i]);
		hash_insert(hTab, maxHash, str);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	build_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	gettimeofday(&start, NULL);
	for(i = 0;i < q; i ++){
		sprintf(str, "%d", target[i]);
		hash_find(hTab, maxHash, str);
	}
	gettimeofday(&end, NULL);
	timersub(&end, &start, &diff);
	search_time = diff.tv_sec + (double)diff.tv_usec/1000000.0;

	printf("hash:\n");
	printf("building time: %f sec\n", build_time);
	printf("query time: %f sec\n", search_time);
}