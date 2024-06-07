#include "Input.h"

std::string Input::inputName() {
    std::string name;

    std::cout<<"Введите название задачи:"<<std::endl;
    std::cin>>name;

    return name;
}

std::string Input::inputDescription() {
    std::string description;
    char ch;

    std::cout<<"Введите описание задачи (Обязательно введите точку в конце, пожалуйста):"<<std::endl;
    while (std::cin.get(ch) && ch != '.') {
        description += ch;
    }

    return description;
}

int Input::inputPriority() {
    int priority = -1;
    std::string strPriority;

    bool usl1 = strPriority == "Высокий", uls2 = strPriority == "Средний", usl3 = strPriority == "Низкий";

    while(!(strPriority == "Высокий" || strPriority == "Средний" || strPriority == "Низкий")) {
        bool usl1 = strPriority == "Высокий", uls2 = strPriority == "Средний", usl3 = strPriority == "Низкий";
        std::cout<<"Какой приоритет у этой задачи? "
                   "Выберите 'Высокий', 'Средний' или 'Низкий'."<<std::endl;
        std::cin >> strPriority;
    }

    (strPriority == "Высокий") ? priority = 2 : (strPriority == "Средний") ? priority = 1 :
            (strPriority == "Низкий") ? priority = 0 : priority;

    return priority;
}