//1. С помощью механизма наследования реализуйте класс Aspirant,
// производный от Student(аспирант - это студент, который готовится
// к защите кандидатской работы).Тема кандидатской работы - обычное поле типа string.
//Убедитесь в наличии 1 - 2 конструкторов и всех необходимых геттеров / сеттеров в каждом из двух классов.
//Применяйте вызов конструктора базового класса, а также для вызова 1 - 2 других методов(например, Print).

#include <iostream>
#include <windows.h>

using namespace std;

class Person {
protected:
    string name = "Неизвестно";
    int age = 0;
public:
    Person() {}
    Person(const string& n, int a) : name(n), age(a) {}

    string getName() const { return name; }
    void setName(const string& n) { name = n; }

    int getAge() const {
        return age;
    }
    void setAge(int a) {
        age = a;
    }

    void Print() const {
        cout << "Имя: " << name << ", Возраст: " << age << "\n";
    }
};


class Student : public Person {
protected:
    string university = "Неизвестный университет";
public:
    Student() {}
    Student(const string& n, int a, const string& uni)
        : Person(n, a), university(uni) {}

    string getUniversity() const {
        return university;
    }
    void setUniversity(const string& uni) {
        university = uni;
    }

    void Print() const {
        Person::Print();
        cout << "Университет: " << university << "\n";
    }
};

class Aspirant : public Student {
private:
    string thesisTopic = "Нет темы";
public:
    Aspirant() {}
    Aspirant(const string& n, int a, const string& uni, const string& topic)
        : Student(n, a, uni), thesisTopic(topic) {}

    string getThesisTopic() const {
        return thesisTopic;
    }
    void setThesisTopic(const string& topic) {
        thesisTopic = topic;
    }

    void Print() const {
        Student::Print();
        cout << "Тема диссертации: " << thesisTopic << "\n";
    }
};

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Person p("Иван Иванов", 40);
    Student s("Петр Петров", 20, "ДНУ");
    Aspirant a("Алексей Алексеев", 25, "ДНУ", "ООП Программирование на С++");
    Aspirant aa;

    cout << "--- Человек ---" << "\n";
    p.Print();

    cout << "\n--- Студент ---" << "\n";
    s.Print();

    cout << "\n--- Аспирант ---" << "\n";
    a.Print();

    cout << "\n--- Аспирант ---" << "\n";
    aa.Print();

    return 0;
}