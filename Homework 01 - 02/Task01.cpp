#include <iostream>
#include <windows.h>
using namespace std;

class Phone {

    string brand;
    string model;
    double screenSize;
    int chargeLevel;
    bool display;

public:

    void SetPhone(string b, string m, double size, int battery, bool disp = false) {
        brand = b;
        model = m;
        screenSize = size;
        chargeLevel = battery;
        display = disp;
    }

    void TurnOn() {
        if (!display) {
            display = true;
            cout << "Телефон включен\n";
        }
        else {
            cout << "Телефон уже был включен\n";
        }
    }

    void TurnOff() {
        if (display) {
            display = false;
            cout << "Телефон выключен\n";
        }
        else {
            cout << "Телефон уже был выключен\n";
        }
    }

    void Charge(int amount) {
        chargeLevel += amount;
        if (chargeLevel > 100) chargeLevel = 100;
        cout << "Телефон заряжен. Текущий заряд: " << chargeLevel << "%\n";
    }

    void Call(string number) {
        if (display && chargeLevel > 0) {
            cout << "Звоним на номер: " << number << "\n";
            chargeLevel -= 5;
            if (chargeLevel < 0) chargeLevel = 0;
        }
        else {
            cout << "Нельзя позвонить: телефон выключен или разряжен.\n";
        }
    }

    void PrintInfo() {
        cout << "Телефон: " << brand << " " << model << "\n";
        cout << "Размер экрана: " << screenSize << " дюймов\n";
        cout << "Заряд: " << chargeLevel << "%\n";
        cout << "Состояние: " << (display ? "Включен" : "Выключен") << "\n";
    }
};

class Lamp {

    string type;
    int power;
    int brightness;
    string color;
    bool state;

public:

    void SetLamp(string t, int p, string c, int b = 50, bool on = false) {
        type = t;
        power = p;
        color = c;
        brightness = b;
        state = on;
    }

    void TurnOn() {
        if (!state) {
            state = true;
            cout << "Лампа включена\n";
        }
        else {
            cout << "Лампа уже была включена\n";
        }
    }

    void TurnOff() {
        if (state) {
            state = false;
            cout << "Лампа выключена\n";
        }
        else {
            cout << "Лампа уже была выключена\n";
        }
    }

    void SetBrightness(int b) {
        if (b < 0) b = 0;
        if (b > 100) b = 100;
        brightness = b;
        cout << "Яркость установлена на " << brightness << "%\n";
    }

    void ChangeColor(string c) {
        color = c;
        cout << "Цвет света изменён на " << color << "\n";
    }

    void PrintInfo() {
        cout << "Тип: " << type << "\n";
        cout << "Мощность: " << power << " Вт\n";
        cout << "Яркость: " << brightness << "%\n";
        cout << "Цвет света: " << color << "\n";
        cout << "Состояние: " << (state ? "Включена" : "Выключена") << "\n";
    }
};

class Aquarium {

    int volume;
    int fishCount;
    double temperature;
    bool filterState;
    bool lightState;

public:

    void SetAquarium(int v, int fCount, double temp, bool fState = false, bool lState = false) {
        volume = v;
        fishCount = fCount;
        temperature = temp;
        filterState = fState;
        lightState = lState;
    }

    void TurnOnFilter() {
        if (!filterState) {
            filterState = true;
            cout << "Фильтр включён\n";
        }
        else {
            cout << "Фильтр уже был включён\n";
        }
    }

    void TurnOffFilter() {
        if (filterState) {
            filterState = false;
            cout << "Фильтр выключен\n";
        }
        else {
            cout << "Фильтр уже был выключен\n";
        }
    }

    void TurnOnLight() {
        if (!lightState) {
            lightState = true;
            cout << "Освещение включено\n";
        }
        else {
            cout << "Освещение уже было включено\n";
        }
    }

    void TurnOffLight() {
        if (lightState) {
            lightState = false;
            cout << "Освещение выключено\n";
        }
        else {
            cout << "Освещение уже было выключено\n";
        }
    }

    void FeedFish(int n) {
        fishCount += n;
        cout << "Покормлено " << n << " рыбок. Теперь их " << fishCount << "\n";
    }

    void PrintInfo() {
        cout << "Объём аквариума: " << volume << " л\n";
        cout << "Количество рыбок: " << fishCount << "\n";
        cout << "Температура воды: " << temperature << " °C\n";
        cout << "Фильтр: " << (filterState ? "Включён" : "Выключен") << "\n";
        cout << "Освещение: " << (lightState ? "Включено" : "Выключено") << "\n";
    }
};

class Treadmill {

    double speed;
    double incline;
    double distanceRun;
    string mode;
    bool state;

public:

    void SetTreadmill(double spd = 0, double inc = 0, double dist = 0, string m = "Кардио", bool on = false) {
        speed = spd;
        incline = inc;
        distanceRun = dist;
        mode = m;
        state = on;
    }

    void TurnOn() {
        if (!state) {
            state = true;
            cout << "Беговая дорожка включена\n";
        }
        else {
            cout << "Беговая дорожка уже была включена\n";
        }
    }

    void TurnOff() {
        if (state) {
            state = false;
            cout << "Беговая дорожка выключена\n";
        }
        else {
            cout << "Беговая дорожка уже была выключена\n";
        }
    }

    void SetSpeed(double spd) {
        if (spd < 0) spd = 0;
        if (spd > 20) spd = 20;
        speed = spd;
        cout << "Скорость установлена на " << speed << " км/ч\n";
    }

    void SetIncline(double inc) {
        if (inc < 0) inc = 0;
        if (inc > 15) inc = 15;
        incline = inc;
        cout << "Наклон установлен на " << incline << " градусов\n";
    }

    void Run(double time) {
        if (state && speed > 0) {
            distanceRun += speed * time / 60.0; // время в минутах
            cout << "Вы пробежали " << speed * time / 60.0 << " км за " << time << " минут\n";
        }
        else {
            cout << "Нельзя бежать: дорожка выключена или скорость 0\n";
        }
    }

    void PrintInfo() {
        cout << "Состояние: " << (state ? "Включена" : "Выключена") << "\n";
        cout << "Скорость: " << speed << " км/ч\n";
        cout << "Наклон: " << incline << " градусов\n";
        cout << "Пройдено расстояние: " << distanceRun << " км\n";
        cout << "Режим: " << mode << "\n";
    }
};

class Person {

    string name;
    int age;
    double height;
    double weight;
    double money;

public:

    void SetPerson(string n, int a, double h, double w, double cash = 0) {
        name = n;
        age = a;
        height = h;
        weight = w;
        money = cash;
    }

    void Eat(double cost, double foodWeight) {
        if (money >= cost) {
            cout << name << " поел(а), потратил(а) " << cost << " грн.\n";
            money -= cost;
            weight += foodWeight * 0.001;         // Условный набор веса ))
        }
        else {
            cout << name << " не может поесть, недостаточно денег!\n";
        }
    }

    void Work(int hours, double hourlyWage) {
        double earned = hours * hourlyWage;
        money += earned;
        cout << name << " поработал(а) " << hours
            << " ч. и заработал(а) " << earned << " грн.\n";
        weight -= hours * 0.05;                 // Условный сброс веса
        if (weight < 40) weight = 40;
    }

    void Sleep(int hours) {
        cout << name << " поспал(а) " << hours << " часов.\n";
    }

    void PrintInfo() {
        cout << "Имя: " << name << "\n";
        cout << "Возраст: " << age << " лет\n";
        cout << "Рост: " << height << " см\n";
        cout << "Вес: " << weight << " кг\n";
        cout << "Деньги: " << money << " грн.\n";
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Phone phone;

    phone.SetPhone("Apple", "iPhone 16 Pro Max", 6.9, 15);

    cout << "\n";
    phone.PrintInfo();
    cout << "\n";
    phone.TurnOn();
    phone.Call("0683800310");
    cout << "\n";
    phone.Charge(30);
    cout << "\n";
    phone.PrintInfo();
    cout << "\n";
    phone.TurnOff();

    cout << "\n\n" << string(55, '=') << "\n\n";

    Lamp lamp;

    lamp.SetLamp("Настольная", 60, "Тёплый белый");

    cout << "\n";
    lamp.PrintInfo();
    cout << "\n";
    lamp.TurnOn();
    lamp.SetBrightness(80);
    lamp.ChangeColor("Холодный белый");
    cout << "\n";
    lamp.PrintInfo();
    cout << "\n";
    lamp.TurnOff();

    cout << "\n\n" << string(55, '=') << "\n";

    Aquarium aqua;

    aqua.SetAquarium(50, 5, 25.0);

    cout << "\n";
    aqua.PrintInfo();
    cout << "\n";

    aqua.TurnOnFilter();
    aqua.TurnOnLight();
    aqua.FeedFish(3);
    cout << "\n";

    aqua.PrintInfo();
    cout << "\n";

    aqua.TurnOffFilter();
    aqua.TurnOffLight();

    cout << "\n\n" << string(55, '=') << "\n";

    Treadmill tm;

    tm.SetTreadmill();
    cout << "\n";
    tm.PrintInfo();
    cout << "\n";

    tm.TurnOn();
    tm.SetSpeed(10);
    tm.SetIncline(5);
    tm.Run(30);         // В минутах 
    cout << "\n";

    tm.PrintInfo();
    cout << "\n";

    tm.TurnOff();

    cout << "\n\n" << string(55, '=') << "\n";

    Person person;

    person.SetPerson("Мила", 25, 160, 48, 500);

    cout << "\n";
    person.PrintInfo();
    cout << "\n";

    person.Eat(200, 500);   // стоимость еды, вес еды (г)
    cout << "\n";
    person.PrintInfo();
    cout << "\n";

    person.Work(6, 150);    // Время, зп в час
    cout << "\n";
    person.PrintInfo();
    cout << "\n";

    person.Sleep(8);        // часов сна 
    cout << "\n";
    person.PrintInfo();
    cout << "\n\n" << string(55, '=') << "\n";
}