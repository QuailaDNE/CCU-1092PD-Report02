#include "basic.h"
#include "BST.h"
#include "BinarySearch.h"
#include "Array.h"
#include "LinkedList.h"
#include "Hash.h"

int scinum(char *n);

/*------ Main ------*/
void main(int argc, char* argv[]) {
	int i, j, d, q;
	int *data, *target;
	srand(time(NULL));

	// Read the command line argument
	for(i = 1; i < argc; i ++) {

		// Generate data
		if(strcmp(argv[i], "-d") == 0){
			i ++;
			if(strcmp(argv[i], "1e4") != 0 && strcmp(argv[i], "1e5") != 0 && strcmp(argv[i], "1e6") != 0) {
				exit(1);
			}

			d = scinum(argv[i]);
			data = malloc(sizeof(int) * d);
			for(j = 0; j < d; j ++) {
				data[j] = rand();
			}
			continue;
		}
		else if(strcmp(argv[i], "-q") == 0){
			i ++;
			if(strcmp(argv[i], "1e3") != 0 && strcmp(argv[i], "1e4") != 0 && strcmp(argv[i], "1e5") != 0) {
				exit(1);
			}

			q = scinum(argv[i]);
			target = malloc(sizeof(int) * q);
			for(j = 0; j < q; j ++) {
				target[j] = rand();
			}
			continue;
		}

		// Build and Search
		else if(strcmp(argv[i], "-bst") == 0){
			BST(data, target, d, q);
			continue;
		}
		else if(strcmp(argv[i], "-bs") == 0){
			BinarySearchArray(data, target, d, q);
			continue;
		}
		else if(strcmp(argv[i], "-arr") == 0){
			Array(data, target, d, q);
			continue;
		}
		else if(strcmp(argv[i], "-ll") == 0){
			LinkedList(data, target, d, q);
			continue;
		}
		else if(strcmp(argv[i], "-hash") == 0){
			Hash(data, target, d, q);
			continue;
		}
	}

	free(data);
	free(target);
}

/*------ Functions ------*/
int scinum(char *n) {
	if(strcmp(n, "1e3") == 0) {
		return 1000;
	}
	else if(strcmp(n, "1e4") == 0) {
		return 10000;
	}
	else if(strcmp(n, "1e5") == 0) {
		return 100000;
	}
	else if(strcmp(n, "1e6") == 0) {
		return 1000000;
	}
	else {
		exit(1);
	}
}