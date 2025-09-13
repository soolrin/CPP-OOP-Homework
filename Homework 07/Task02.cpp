//2. Создайте класс Passport(паспорт), который будет содержать паспортную информацию
// о гражданине Украины.С помощью механизма наследования реализуйте
// класс Foreign Passport(загранпаспорт), производный от Passport.
// Загранпаспорт содержит, кроме паспортных данных, также данные о визах.
// Виза должна быть представлена отдельным классом.

#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

class Visa {
private:
    string country = "Неизвестная страна";
    string validUntil = "Неизвестный срок";
public:
    Visa() {}
    Visa(const string& c, const string& v) : country(c), validUntil(v) {}

    string getCountry() const { return country; }
    void setCountry(const string& c) { country = c; }

    string getValidUntil() const { return validUntil; }
    void setValidUntil(const string& v) { validUntil = v; }

    void Print() const {
        cout << "Страна: " << country << ", Действительна до: " << validUntil << "\n";
    }
};

class Passport {
protected:
    string fullName = "Неизвестно";
    string nationality = "Украина";
    string passportNumber = "000000000";
public:
    Passport() {}
    Passport(const string& n, const string& nat, const string& num)
        : fullName(n), nationality(nat), passportNumber(num) {}

    string getFullName() const { return fullName; }
    void setFullName(const string& n) { fullName = n; }

    string getNationality() const { return nationality; }
    void setNationality(const string& nat) { nationality = nat; }

    string getPassportNumber() const { return passportNumber; }
    void setPassportNumber(const string& num) { passportNumber = num; }

    void Print() const {
        cout << "ФИО: " << fullName
            << ", Гражданство: " << nationality
            << ", Номер паспорта: " << passportNumber << "\n";
    }
};

class ForeignPassport : public Passport {
private:
    vector<Visa> visas;
public:
    ForeignPassport() {}
    ForeignPassport(const string& n, const string& nat, const string& num)
        : Passport(n, nat, num) {}

    void addVisa(const Visa& v) {
        visas.push_back(v);
    }

    void Print() const {
        Passport::Print();
        if (visas.empty()) {
            cout << "Визы отсутствуют\n";
        }
        else {
            cout << "Визы:\n";
            for (const auto& v : visas) {
                v.Print();
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Passport p("Иван Иванов", "Украина", "AB123456");
    ForeignPassport fp("Петр Петров", "Украина", "ZP987654");

    fp.addVisa(Visa("Германия", "01.12.2025"));
    fp.addVisa(Visa("США", "15.06.2026"));

    cout << "--- Паспорт ---" << "\n";
    p.Print();

    cout << "\n--- Загранпаспорт ---" << "\n";
    fp.Print();

    return 0;
}