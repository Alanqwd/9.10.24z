#include <iostream>
#include <string>
#include <Windows.h>

class Person {
protected:
    int age;

public:

    std::string name;//  с поля протектед убрал потому что выводит ошибка в функции  void handleComplaint

    Person(const std::string& name, int age) : name(name), age(age) {}

    void displayInfo() const {
        std::cout << "Имя: " << name << ", Возраст: " << age << "\n";
    }
};


class Resident : public Person {
private:
    std::string apartmentNumber;

public:
    Resident(const std::string& name, int age, const std::string& apartmentNumber)
        : Person(name, age), apartmentNumber(apartmentNumber) {}

    void displayInfo() const {
        Person::displayInfo();
        std::cout << "Номер квартиры: " << apartmentNumber << "\n";
    }


    void registerComplaint(const std::string& complaint) const {
        std::cout << name << " зарегистрировал жалобу: " << complaint << "\n";
    }
};


class Manager : public Person {
public:
    Manager(const std::string& name, int age) : Person(name, age) {}

    void displayInfo() const {
        Person::displayInfo();
        std::cout << "Роль: Управляющий домом" << "\n";
    }


    void handleComplaint(const Resident& resident, const std::string& complaint) const {
        std::cout << name << " обрабатывает жалобу от " << resident.name << ": " << complaint << "\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Resident resident("Алексей", 30, "12A");
    Manager manager("Игорь", 45);


    resident.displayInfo();
    manager.displayInfo();

    resident.registerComplaint("Отсутствие горячей воды");

    manager.handleComplaint(resident, "Отсутствие горячей воды");

    return 0;
}