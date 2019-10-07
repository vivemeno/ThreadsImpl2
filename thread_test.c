//Vivek Sankara Menon (1215099119), Akhil Jayaraj(1215160609)
#include<stdio.h>
#include "threads.h"

int glob_x = 10;

void func1(int threadId) {
    int local_x = 7;
    while(1) {
        printf("This is thread %d\n", threadId);
        printf("Incrementing glob_x in func1\n");
        glob_x += 1;    //Incrementing glob_x in func 1
        printf("Local x in func 1  = %d\n\n", local_x++);
        yield();
    }
}

void func2(int threadId) {
    while(1) {
        printf("This is thread %d\n", threadId);
        printf("Reading glob_x in func2\n");
        printf("glob_x = %d\n\n", glob_x);
        yield();
    }
}

int main() {
    printf("Hello, World!\n");
    start_thread(func1);
    start_thread(func2);
    run();
    return 0;
}



