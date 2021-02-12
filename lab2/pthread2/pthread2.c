// pthread2.c
// This programme will create two threads, each print its own
// message onto the screen

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g_var1 = 0;

void *inc_gv() {
    int i, j;
    for (i=0;i<10;i++) {
        g_var1++;
        for (j=0;j<5000000;j++);
        printf(" %d", g_var1);
        fflush(stdout);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int T1ret, T2ret;

    /* Create two threads*/
    T1ret = pthread_create(&thread1, NULL, inc_gv(), NULL);
    T2ret = pthread_create(&thread2, NULL, inc_gv(), NULL);

    /* main() thread now waits for both threads to finish */
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\n pthread2 completed \n");
    return 0;
}