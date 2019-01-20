//
// Created by avshalom on 1/22/18.
//

#include "Task.h"
#include "ThreadPool.h"
#include <iostream>
#include <unistd.h>
using namespace std;
#define THREADS_NUM 3
#define TASKS_NUM 5

void* print(void *taskId);

int main() {
    ThreadPool pool(THREADS_NUM);
    Task *tasks[TASKS_NUM];
    for (int i = 0; i < TASKS_NUM; i++) {
        tasks[i] = new Task(print, (void *)i);
        pool.addTask(tasks[i]);
    }
    char ch;
    cout << "Type a char to exit" << endl;
    cin >> ch;
    pool.terminate();
    for (int i = 0; i < TASKS_NUM; i++) {
        delete tasks[i];
    }
    cout << "End of main" << endl;
}

void* print(void *taskId) {
    long id = (long)taskId;
    for (int i = 1; i <= 3; i++) {
        cout << "Task " << id << " prints: " << i << endl;
        sleep(1);
    }
    return NULL;
}


