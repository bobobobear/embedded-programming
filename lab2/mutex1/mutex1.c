// mutex1.c
// This programme demonstrate mutex
// message onto the screen

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g_var1 = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *inc_gv() {
    int i, j;
    for (i=0;i<10;i++) {
        pthread_mutex_lock(&mutex1);
        g_var1++;
        for (j=0;j<5000000;j++);
        printf(" %d", g_var1);
        fflush(stdout);
        pthread_mutex_unlock(&mutex1);
    }
    return NULL;
}

int main() {
    pthread_t TA, TB;
    int rTA, rTB;

    /* Create two threads*/
    if((rTA = pthread_create(&TA, NULL, inc_gv, NULL)))
        printf("Thread creation fail: %d\n", rTA);
    if((rTB = pthread_create(&TB, NULL, inc_gv, NULL)))
        printf("Thread creation fail: %d\n", rTB);

    /* main() thread now waits for both threads to finish */
    pthread_join(TA, NULL);
    pthread_join(TB, NULL);
    pthread_mutex_destroy(&mutex1);
    printf("\n pthread2 completed \n");
    return 0;
}
