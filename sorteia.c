#include <stdlib.h>

int sorteia(int k) {
	return (int)(1 + (rand()/(RAND_MAX+1.0))*k);
}