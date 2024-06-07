#ifndef UNTITLED_HIGHPRIORITYTASK_H
#define UNTITLED_HIGHPRIORITYTASK_H

#include "Task.h"
#include "ToDoList.h"
#include <memory>

class HighPriorityTask : public Task {
private:
    int priority;

    void setPriority(int newPriority);

    friend class ToDoList;

public:
    HighPriorityTask(const std::string &name, const std::string &description, bool status, int priority);

    int getPriority() const override;
};

#endif
