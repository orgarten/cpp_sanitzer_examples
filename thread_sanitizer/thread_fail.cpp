//
// Created by orell on 7/12/23.
//

#include <pthread.h>

int Global;

void *Thread1(void *x) {
    Global = 42;
    return x;
}

int main() {
    pthread_t t;
    pthread_create(&t, NULL, Thread1, NULL);
    // this write happens at the same time as the one in the thread
    Global = 43;
    pthread_join(t, NULL);
    return Global;
}