#include <iostream>
#include <string>
#include <Windows.h>

class Person {
protected:
    int age;

public:

    std::string name;//  � ���� ��������� ����� ������ ��� ������� ������ � �������  void handleComplaint

    Person(const std::string& name, int age) : name(name), age(age) {}

    void displayInfo() const {
        std::cout << "���: " << name << ", �������: " << age << "\n";
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
        std::cout << "����� ��������: " << apartmentNumber << "\n";
    }


    void registerComplaint(const std::string& complaint) const {
        std::cout << name << " ��������������� ������: " << complaint << "\n";
    }
};


class Manager : public Person {
public:
    Manager(const std::string& name, int age) : Person(name, age) {}

    void displayInfo() const {
        Person::displayInfo();
        std::cout << "����: ����������� �����" << "\n";
    }


    void handleComplaint(const Resident& resident, const std::string& complaint) const {
        std::cout << name << " ������������ ������ �� " << resident.name << ": " << complaint << "\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Resident resident("�������", 30, "12A");
    Manager manager("�����", 45);


    resident.displayInfo();
    manager.displayInfo();

    resident.registerComplaint("���������� ������� ����");

    manager.handleComplaint(resident, "���������� ������� ����");

    return 0;
}