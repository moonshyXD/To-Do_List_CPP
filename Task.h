#ifndef UNTITLED_TASK_H
#define UNTITLED_TASK_H

#include <vector>
#include <string>
#include <iostream>

class Task {
private:
    std::string name;
    std::string description;
    bool status;

    friend class ToDoList;

public:
    Task(const std::string &name, const std::string &description, bool status);

    std::string getName() const;

    std::string getDescription() const;

    bool getStatus() const;

    void setStatus(bool newStatus);

    virtual void setPriority(int priority) = 0;

    virtual int getPriority() const { return -1; }

    void setName(const std::string newName);

    void setDescription(const std::string newDescription);
};

#endif
