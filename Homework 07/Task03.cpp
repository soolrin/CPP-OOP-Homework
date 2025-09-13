//3. Создайте базовый класс Транспорт и его дочерние классы 
// Автомобиль, Такси, Трамвай, Троллейбус, Маршрутка, Электросамокат, Поезд, Самолет, Велосипед.
//Создайте методы для расчета времени и стоимости поездки из Киева в Днепр.
// == Используется образный подсчет стоимости для упрощения логики. ==

#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

class Transport {
protected:
    string name = "Неизвестный транспорт";
    double speed = 0;       // км/ч
    double costPerKm = 0;   // стоимость за км

public:
    Transport() {};

    Transport(const string& n, double s, double c)
        : name(n), speed(s), costPerKm(c) {}

    double calculateTime(double distance) const {
        return distance / speed;
    }

    double calculateCost(double distance) const {
        return distance * costPerKm;
    }

    void printInfo(double distance) const {
        double time = calculateTime(distance);
        double cost = calculateCost(distance);

        cout << "Транспорт: " << name << "\n";
        cout << "Время в пути: " << fixed << setprecision(1) << time << " часов\n";
        cout << "Стоимость поездки: " << fixed << setprecision(2) << cost << " грн\n";
        cout << "----------------------------------------\n";
    }
};

class Car : public Transport {
public:
    Car() : Transport("Автомобиль", 90, 5.0) {}
};

class Taxi : public Transport {
public:
    Taxi() : Transport("Такси", 70, 8.0) {}
};

class Bus : public Transport {
public:
    Bus() : Transport("Маршрутка", 60, 4.0) {}
};

class Train : public Transport {
public:
    Train() : Transport("Поезд", 80, 3.0) {}
};

class Airplane : public Transport {
private:
    double airportTime; // дополнительное время на аэропорт (часы)
    double airportFee;  // дополнительный сбор (грн)

public:
    Airplane() : Transport("Самолёт", 500, 6.0), airportTime(2.5), airportFee(500) {}

    double calculateTime(double distance) const {
        return (distance / speed) + airportTime;
    }

    double calculateCost(double distance) const {
        return (distance * costPerKm) + airportFee;
    }

    void printInfo(double distance) const {
        double flightTime = distance / speed;
        double totalTime = calculateTime(distance);
        double flightCost = distance * costPerKm;
        double totalCost = calculateCost(distance);

        cout << "Транспорт: " << name << "\n";
        cout << "Время полета: " << fixed << setprecision(1) << flightTime << " часов\n";
        cout << "Доп. время (аэропорт): " << airportTime << " часов\n";
        cout << "Общее время: " << totalTime << " часов\n";
        cout << "Стоимость перелета: " << fixed << setprecision(2) << flightCost << " грн\n";
        cout << "Аэропортовый сбор: " << airportFee << " грн\n";
        cout << "Общая стоимость: " << totalCost << " грн\n";
        cout << "----------------------------------------\n";
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const double distance = 500; // расстояние Киев-Днепр в км

    Car car;
    Taxi taxi;
    Bus bus;
    Train train;
    Airplane plane;

    cout << "Расчет поездки из Киева в Днепр (500 км):\n";
    cout << "========================================\n\n";

    car.printInfo(distance);
    taxi.printInfo(distance);
    bus.printInfo(distance);
    train.printInfo(distance);
    plane.printInfo(distance);

    return 0;
}