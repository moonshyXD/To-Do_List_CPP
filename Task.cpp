#include "Task.h"

Task::Task(const std::string &name, const std::string &description, bool status) : name(name), description(description),
                                                                                   status(status) {}

std::string Task::getName() const {
    return name;
}

std::string Task::getDescription() const {
    return description;
}

bool Task::getStatus() const {
    return status;
}

void Task::setName(const std::string newName) {
    name = newName;
}

void Task::setDescription(const std::string newDescription) {
    description = newDescription;
}

void Task::setStatus(bool newStatus) {
    status = newStatus;
}
