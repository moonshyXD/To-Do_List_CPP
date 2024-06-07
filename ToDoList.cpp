#include "ToDoList.h"

void ToDoList::addTask(const std::shared_ptr<Task> &task) {
    tasks.push_back(task);
    std::cout << "Задача успешно добавлена в список задач." << std::endl;
}

void ToDoList::deleteTask(const std::string &name) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if ((*it)->getName() == name) {
            tasks.erase(it);
            std::cout << "Задача удалена." << std::endl;
            return;
        }
    }
    std::cout << "Задача не найдена." << std::endl;
}

void ToDoList::changeName(const std::string &name, const std::string &newName) {
    for (const auto &task: tasks) {
        if (task->getName() == name) {
            task->setName(newName);
            std::cout << "Имя успешно изменено." << std::endl;
            return;
        }
    }
    std::cout << "Задача не найдена." << std::endl;
}

void ToDoList::changeDescription(const std::string &name, const std::string &newDescription) {
    for (const auto &task: tasks) {
        if (task->getName() == name) {
            task->setDescription(newDescription);
            std::cout << "Описание успешно изменено." << std::endl;
            return;
        }
    }
    std::cout << "Задача не найдена." << std::endl;
}

void ToDoList::changeStatus(const std::string &name, bool newStatus) {
    for (const auto &task: tasks) {
        if (task->getName() == name) {
            task->setStatus(newStatus);
            std::cout << "Статус успешно изменён." << std::endl;
            return;
        }
    }
    std::cout << "Задача не найдена." << std::endl;
}

void ToDoList::changePriority(const std::string &name, int newPriority) {
    for (const auto &task: tasks) {
        if (task->getName() == name) {
            auto highPriorityTask = std::dynamic_pointer_cast<HighPriorityTask>(task);
            if (highPriorityTask) {
                highPriorityTask->setPriority(newPriority);
                std::cout << "Приоритет задачи успешно изменён." << std::endl;
                return;
            }
        }
    }
    std::cout << "Задача не найдена или не является задачей с высоким приоритетом." << std::endl;
}

void ToDoList::checkTasks() const {
    std::cout << "Все задачи из списка задач: " << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        const auto &task = tasks[i];
        std::string status;
        (task->getStatus()) ? status = "Выполнено" : status = "Невыполнено";
        std::cout << i << ". Название задачи: " << task->getName() << std::endl
                  << "Описание задачи: " << task->getDescription() << std::endl
                  << "Статус задачи: " << status << std::endl;
        auto highPriorityTask = std::dynamic_pointer_cast<HighPriorityTask>(task);
        if (highPriorityTask) {
            std::string priority = "0";
            (highPriorityTask->getPriority() == 2) ? priority = "Высокий" : (highPriorityTask->getPriority() == 1)
                                                                            ? priority = "Средний" :
                                                                            (highPriorityTask->getPriority() == 0)
                                                                            ? priority = "Низкий" : priority;
            std::cout << "Приоритет задачи: " << priority << std::endl;
        } else {
            std::cout << "Приоритет задачи: Нет" << std::endl;
        }
    }
}
