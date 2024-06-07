#include "HighPriorityTask.h"

HighPriorityTask::HighPriorityTask(const std::string &name, const std::string &description, bool status, int priority)
        : Task(name, description, status), priority(priority) {}

int HighPriorityTask::getPriority() const {
    return priority;
}

void HighPriorityTask::setPriority(int newPriority) {
    priority = newPriority;
}
