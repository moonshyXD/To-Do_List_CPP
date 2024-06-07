#ifndef UNTITLED_OPERATIONS_H
#define UNTITLED_OPERATIONS_H

#include "ToDoList.h"
#include "Task.h"
#include "HighPriorityTask.h"
#include "Input.h"
#include <memory>

class Operations {
private:
    bool end = false;
    int choice = 0;

    void welcome();

    void handleEvents();

    void performingOperations(ToDoList &list);

    void addTask(ToDoList &list);

    void changeDescription(ToDoList &list);

    void changeStatus(ToDoList &list);

    void changePriority(ToDoList &list);

    void changeName(ToDoList &list);

    void deleteTask(ToDoList &list);

    void checkTasks(ToDoList &list);

    void setEnd();

public:
    void run();
};

#endif
