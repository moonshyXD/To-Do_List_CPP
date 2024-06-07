#include "Operations.h"

void Operations::welcome() {
    std::cout << "Здравствуйте! Вас приветствует список задач (ToDoList). Сюда вы можете добавлять свои задания, "
                 "изменять их описание, статус. Так же вы можете добавить специальные задачи с приоритетом. Приятного пользования!"
              << std::endl;
}

void Operations::handleEvents() {
    choice = 0;
    while (!(choice >= 1 && choice <= 8)) {
        std::cout << "Что вы хотите сделать?" << std::endl <<
                  "1 - Добавить задачу." << std::endl <<
                  "2 - Изменить описание задачи." << std::endl <<
                  "3 - Изменить статус задачи." << std::endl <<
                  "4 - Изменить приоритет задачи." << std::endl <<
                  "5 - Изменить название задачи." << std::endl <<
                  "6 - Удалить задачу." << std::endl <<
                  "7 - Показать все задачи." << std::endl <<
                  "8 - Завершить работу." << std::endl;
        std::cin >> choice;
    }
}

void Operations::addTask(ToDoList &list) {
    std::string name, description;
    bool status = false;
    int priority;

    name = Input::inputName();
    description = Input::inputDescription();
    priority = Input::inputPriority();

    auto task = std::make_shared<HighPriorityTask>(name, description, status, priority);
    list.addTask(task);
}

void Operations::changeDescription(ToDoList &list) {
    std::string name, newDescription;
    name = Input::inputName();

    std::cout << "Введите новое описание этой задачи: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, newDescription);

    list.changeDescription(name, newDescription);
}

void Operations::changeStatus(ToDoList &list) {
    std::string name;
    std::string strNewStatus;
    bool newStatus;

    name = Input::inputName();
    std::cout << "Какой статус вы хотите дать задаче? Введите 'Выполнено' или 'Невыполнено'." << std::endl;
    std::cin >> strNewStatus;

    newStatus = (strNewStatus == "Выполнено");
    list.changeStatus(name, newStatus);
}

void Operations::changePriority(ToDoList &list) {
    std::string name;
    std::string strPriority;
    int newPriority = -1;

    name = Input::inputName();
    while (strPriority != "Высокий" && strPriority != "Средний" && strPriority != "Низкий") {
        std::cout << "Какой приоритет вы хотите поставить задаче " << name << " ?" << std::endl <<
                  "Выберите 'Высокий', 'Средний' или 'Низкий'";
        std::cin >> strPriority;
    }

    if (strPriority == "Высокий") newPriority = 2;
    else if (strPriority == "Средний") newPriority = 1;
    else if (strPriority == "Низкий") newPriority = 0;

    list.changePriority(name, newPriority);
}

void Operations::changeName(ToDoList &list) {
    std::string name = Input::inputName();
    std::string newName;

    std::cout << "Какое новое имя вы хотите дать этой задаче?" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, newName);

    list.changeName(name, newName);
}

void Operations::deleteTask(ToDoList &list) {
    std::string name;
    name = Input::inputName();

    list.deleteTask(name);
}

void Operations::checkTasks(ToDoList &list) {
    list.checkTasks();
}

void Operations::setEnd() {
    end = true;
    std::cout << "Процесс работы списка задач (To-Do List) завершён." << std::endl;
}

void Operations::performingOperations(ToDoList &list) {
    switch (choice) {
        case 1:
            addTask(list);
            break;
        case 2:
            changeDescription(list);
            break;
        case 3:
            changeStatus(list);
            break;
        case 4:
            changePriority(list);
            break;
        case 5:
            changeName(list);
            break;
        case 6:
            deleteTask(list);
            break;
        case 7:
            checkTasks(list);
            break;
        case 8:
            setEnd();
            break;
    }
}

void Operations::run() {
    ToDoList list;
    welcome();
    while (!end) {
        handleEvents();
        performingOperations(list);
    }
}
