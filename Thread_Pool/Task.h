//
// Created by avshalom on 1/22/18.
//

#ifndef THREAD_POOL_REC13_TASK_H
#define THREAD_POOL_REC13_TASK_H


class Task {
public:
    Task(void * (*func)(void *arg), void* arg) :
            func(func), arg(arg) {}
    void execute() {
        func(arg);
    }
    virtual ~Task() {}
private:
    void * (*func)(void *arg);
    void *arg;
};


#endif //THREAD_POOL_REC13_TASK_H
