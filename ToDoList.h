#ifndef UNTITLED_TODOLIST_H
#define UNTITLED_TODOLIST_H

#include "Task.h"
#include "HighPriorityTask.h"
#include <memory>
#include <vector>

class ToDoList {
private:
    std::vector<std::shared_ptr<Task>> tasks;

public:
    void addTask(const std::shared_ptr<Task> &task);

    void deleteTask(const std::string &name);

    void changeName(const std::string &name, const std::string &newName);

    void changeDescription(const std::string &name, const std::string &description);

    void changeStatus(const std::string &name, bool newStatus);

    void changePriority(const std::string &name, int newPriority);

    void checkTasks() const;
};

#endif
