//
// Created by vivemeno on 10/6/19.
//
#include<ucontext.h>
#include "q.h"
#include<stdlib.h>

struct TCB_t *Curr_Thread, *ReadyQ;
int  thread_count = 1;

void start_thread(void (*function)(int))
{ // begin pseudo code
    //allocate a stack (via malloc) of a certain size (choose 8192)
    int stackSize = 8192;
    void *stackP = malloc(stackSize);
    struct TCB_t *tcb = malloc(sizeof(struct TCB_t));
    tcb->thread_id = thread_count++;
    init_TCB(tcb, function, stackP, stackSize);
    AddQueue(&ReadyQ, tcb);
    //end pseudo code
}


void run()

{   // real code
    Curr_Thread = DelQueue(&ReadyQ);
    ucontext_t parent;     // get a place to store the main context, for faking
    getcontext(&parent);   // magic sauce
    swapcontext(&parent, &(Curr_Thread->context));  // start the first thread
}

void yield() // similar to run
{
    struct TCB_t* Prev_Thread;
    AddQueue(&ReadyQ, Curr_Thread);
    Prev_Thread = Curr_Thread;
    Curr_Thread = DelQueue(&ReadyQ);
    swapcontext(&Prev_Thread->context, &Curr_Thread->context);
}
