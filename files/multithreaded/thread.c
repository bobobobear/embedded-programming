#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int main(int argc, char *argv[]) {
	if (fork()==0) {
		printf("child\n");
	} else {
		printf("parent\n");
		wait(NULL);
		printf("child ended\n");
	}
	return 0;
}
