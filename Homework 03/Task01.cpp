#include <iostream>
#include <windows.h>
using namespace std;

class Phone {

    string brand;
    string model;
    double screenSize;
    int chargeLevel;
    bool display;

    string* os; 

public:

    Phone() : Phone("Нет бренда", "Нет модели", 5.0, 50, false, "Нет ОС") {}

    Phone(string brand, string model, double screenSize, int chargeLevel, bool display, string osName) {
        this->brand = brand;
        this->model = model;
        SetScreenSize(screenSize);
        SetChargeLevel(chargeLevel);
        this->display = display;

        os = new string(osName);
    }

    Phone(const Phone& original) {
        brand = original.brand;
        model = original.model;
        screenSize = original.screenSize;
        chargeLevel = original.chargeLevel;
        display = original.display;

        os = new string(*original.os);
    }

    ~Phone() {
        delete os;
    }


    void SetBrand(string newBrand) {
        brand = newBrand; 
    }
    void SetModel(string newModel) {
        model = newModel; 
    }
    void SetScreenSize(double newScreenSize) {
        if (newScreenSize < 3.5) newScreenSize = 3.5;
        if (newScreenSize > 7.5) newScreenSize = 7.5;
        screenSize = newScreenSize;
    }
    void SetChargeLevel(int newChargeLevel) {
        if (newChargeLevel < 0) newChargeLevel = 0;
        if (newChargeLevel > 100) newChargeLevel = 100;
        chargeLevel = newChargeLevel;
    }
    void SetDisplay(bool newDisplay) {
        display = newDisplay; 
    }
    void SetOS(string newOS) {
        *os = newOS; 
    }

    string GetBrand() const {
        return brand; 
    }
    string GetModel() const {
        return model; 
    }
    double GetScreenSize() const {
        return screenSize; 
    }
    int GetChargeLevel() const {
        return chargeLevel; 
    }
    bool GetDisplay() const {
        return display; 
    }
    string GetOS() const {
        return *os; 
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
        cout << "ОС: " << *os << "\n";
        cout << "Размер экрана: " << screenSize << " дюймов\n";
        cout << "Заряд: " << chargeLevel << "%\n";
        cout << "Состояние: " << (display ? "Включен" : "Выключен") << "\n";
    }
};

class Person {

    string name;
    int age;
    double height;
    double weight;
    double money;

    string* hobby;
    double* iq;

public:

    Person() : Person("Нет Имя", 0, 170, 60, 0.0, "Нет Хобби", 0) {}

    Person(string name, int age, double height, double weight, double money, string hobby, double iq) {
        this->name = name;
        SetAge(age);
        SetHeight(height);
        SetWeight(weight);
        SetMoney(money);

        this->hobby = new string(hobby);
        this->iq = new double(iq);
    }

    Person(const Person& original) {
        name = original.name;
        age = original.age;
        height = original.height;
        weight = original.weight;
        money = original.money;

        hobby = new string(*original.hobby);
        iq = new double(*original.iq);
    }

    ~Person() {
        delete hobby;
        delete iq;
    }

    void SetName(string newName) {
        name = newName;
    }
    void SetAge(int newAge) {
        if (newAge < 0) newAge = 0;
        if (newAge > 120) newAge = 120;
        age = newAge;
    }
    void SetHeight(double newHeight) {
        if (newHeight < 30) newHeight = 30;
        if (newHeight > 250) newHeight = 250;
        height = newHeight;
    }
    void SetWeight(double newWeight) {
        if (newWeight < 1) newWeight = 1;
        if (newWeight > 200) newWeight = 200;
        weight = newWeight;
    }
    void SetMoney(double newMoney) {
        if (newMoney < 0) newMoney = 0;
        money = newMoney;
    }
    void SetHobby(string newHobby) {
        *hobby = newHobby;
    }
    void SetIQ(double newIQ) {
        if (newIQ < 0) newIQ = 0;
        if (newIQ > 300) newIQ = 300;
        *iq = newIQ;
    }

    string GetName() const {
        return name;
    }
    int GetAge() const {
        return age;
    }
    double GetHeight() const {
        return height;
    }
    double GetWeight() const {
        return weight;
    }
    double GetMoney() const {
        return money;
    }
    string GetHobby() const {
        return *hobby; 
    }
    double GetIQ() const {
        return *iq; 
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
        cout << "Хобби: " << *hobby << "\n";
        cout << "IQ: " << *iq << "\n";
    }
};

class Lamp {

    string type;
    int power;
    int brightness;
    string color;
    bool state;

public:

    void SetType(string newType) {
        type = newType;
    }
    void SetPower(int newPower) {
        if (newPower < 1) newPower = 1;
        if (newPower > 200) newPower = 200;
        power = newPower;
    }
    void SetBrightness(int newBrightness) {
        if (newBrightness < 0) newBrightness = 0;
        if (newBrightness > 100) newBrightness = 100;
        brightness = newBrightness;
    }
    void SetColor(string newColor) {
        color = newColor;
    }
    void SetState(bool newState = false) {
        state = newState;
    }

    string GetType() const {
        return type;
    }
    int GetPower() const {
        return power;
    }
    int GetBrightness() const {
        return brightness;
    }
    string GetColor() const {
        return color;
    }
    bool GetState() const {
        return state;
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

    void ChangeBrightness(int newBrightness) {
        if (newBrightness < 0) newBrightness = 0;
        if (newBrightness > 100) newBrightness = 100;
        brightness = newBrightness;
        cout << "Яркость установлена на " << brightness << "%\n";
    }

    void ChangeColor(string newColor) {
        color = newColor;
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

    void SetVolume(int v) {
        if (v < 1) v = 1;
        if (v > 1000) v = 1000;
        volume = v;
    }
    void SetFishCount(int сount) {
        if (сount < 0) сount = 0;
        fishCount = сount;
    }
    void SetTemperature(double t) {
        if (t < 10.0) t = 10.0;
        if (t > 35.0) t = 35.0;
        temperature = t;
    }
    void SetFilterState(bool state = false) {
        filterState = state;
    }
    void SetLightState(bool state = false) {
        lightState = state;
    }

    int GetVolume() const {
        return volume;
    }
    int GetFishCount() const {
        return fishCount;
    }
    double GetTemperature() const {
        return temperature;
    }
    bool GetFilterState() const {
        return filterState;
    }
    bool GetLightState() const {
        return lightState;
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

    void SetSpeed(double spd = 0) {
        if (spd < 0) spd = 0;
        if (spd > 20) spd = 20;
        speed = spd;
    }
    void SetIncline(double inc = 0) {
        if (inc < 0) inc = 0;
        if (inc > 15) inc = 15;
        incline = inc;
    }
    void SetDistance(double dist = 0) {
        if (dist < 0) dist = 0;
        distanceRun = dist;
    }
    void SetMode(string m = "Авто") {
        mode = m;
    }
    void SetState(bool s = false) {
        state = s;
    }

    double GetSpeed() const {
        return speed;
    }
    double GetIncline() const {
        return incline;
    }
    double GetDistance() const {
        return distanceRun;
    }
    string GetMode() const {
        return mode;
    }
    bool GetState() const {
        return state;
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

    void ChangeSpeed(double spd) {
        if (spd < 0) spd = 0;
        if (spd > 20) spd = 20;
        speed = spd;
        cout << "Скорость установлена на " << speed << " км/ч\n";
    }

    void ChangeIncline(double inc) {
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


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Phone phone("Apple", "iPhone 16 Pro Max", 6.9, 33, false, "iOS 18");

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

    cout << "\n" << string(55, '=') << "\n\n";

    Phone copyPhone(phone);
    copyPhone.PrintInfo();

    cout << "\n" << string(55, '=') << "\n";

    Lamp lamp;

    lamp.SetType("Настольная");
    lamp.SetPower(60);
    lamp.SetColor("Тёплый белый");
    lamp.SetBrightness(70);

    cout << "\n";
    lamp.PrintInfo();
    cout << "\n";
    lamp.TurnOn();
    lamp.ChangeBrightness(80);
    lamp.ChangeColor("Холодный белый");
    cout << "\n";
    lamp.PrintInfo();
    cout << "\n";
    lamp.TurnOff();

    cout << "\n" << string(55, '=') << "\n";

    Aquarium aqua;

    aqua.SetVolume(50);
    aqua.SetFishCount(5);
    aqua.SetTemperature(25.0);
    aqua.SetFilterState();

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

    cout << "\n" << string(55, '=') << "\n";

    Treadmill tm;

    tm.SetSpeed(10);
    tm.SetIncline(5);
    tm.SetMode("Кардио");
    tm.SetDistance();
    tm.SetState();

    cout << "\n";
    tm.PrintInfo();
    cout << "\n";

    tm.TurnOn();
    tm.ChangeSpeed(8);
    tm.ChangeIncline(10);
    tm.Run(120);             // В минутах 
    cout << "\n";

    tm.PrintInfo();
    cout << "\n";

    tm.TurnOff();

    cout << "\n" << string(55, '=') << "\n";

    Person person("Мила", 25, 160, 48, 500, "Плавать", 140);

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

    cout << "\n" << string(55, '=') << "\n\n";

    Person copyPerson(person);
    copyPerson.PrintInfo();

    cout << "\n" << string(55, '=') << "\n";
}