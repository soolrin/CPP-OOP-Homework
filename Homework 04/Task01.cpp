#include <iostream>
#include <windows.h>
#include <algorithm>
#include <ctime>

using namespace std;

class Vector {
    unsigned int capacity = 10;
    int* data = new int[capacity];
    unsigned int length = 0;

public:
    Vector() {}

    void AddToBack(int value) {
        if (length < capacity)
            data[length] = value;
        else {
            capacity *= 1.5;
            int* temp = new int[capacity];

            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }

            temp[length] = value;
            delete[] data;
            data = temp;
        }
        length++;
    }

    void AddToFront(int value) {
        if (length < capacity) {
            for (int i = length - 1; i >= 0; i--) {
                data[i + 1] = data[i];
            }
            data[0] = value;
        }
        else {
            capacity *= 1.5;
            int* temp = new int[capacity];

            for (int i = 0; i < length; i++) {
                temp[i + 1] = data[i];
            }

            temp[0] = value;
            delete[] data;
            data = temp;
        }
        length++;
    }

    void RemoveFromBack() {
        if (length == 0) {
            cout << "Массив пуст\n";
            return;
        }
        length--;
    }

    void RemoveFromFront() {
        if (length == 0) {
            cout << "Массив пуст\n";
            return;
        }

        for (int i = 0; i < length - 1; i++)
            data[i] = data[i + 1];

        length--;
    }

    void Insert(int value, unsigned int index) {

        if (index < 0 || index >= length) {
            cout << "Ошибка: индекс вне диапазона\n";
            return;
        }

        if (length < capacity) {

            for (int i = length - 1; i >= index; i--)
                data[i + 1] = data[i];

            data[index] = value;
        }
        else {
            capacity *= 1.5;
            int* temp = new int[capacity];

            for (int i = 0; i < index; i++)
                temp[i] = data[i];

            temp[index] = value;

            for (int i = index; i < length; i++)
                temp[i + 1] = data[i];

            delete[] data;
            data = temp;
        }
        length++;
    }

    void RemoveByIndex(int index) {

        if (index < 0 || index >= length) {
            cout << "Ошибка: индекс вне диапазона\n";
            return;
        }

        for (unsigned int i = index; i < length - 1; i++)
            data[i] = data[i + 1];

        length--;
    }

    void RemoveByValue(int value) {

        for (int i = 0; i < length; i++) {
            if (data[i] == value) {
                for (int j = i; j < length - 1; j++)
                    data[j] = data[j + 1];

                length--;
            }
        }
    }

    void Sort() {
        sort(data, data + length);  // На паре было сказано использовать уже готовый sort
    }

    void Reverse() {
        for (int i = 0; i < length / 2; i++)
            swap(data[i], data[length - 1 - i]);
    }

    void Shuffle() {
        if (length <= 1) return;

        for (int i = length - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            swap(data[i], data[j]);
        }
    }

    int& operator [] (unsigned int index) {

        if (index < 0 || index >= length) {
            cout << "Ошибка: индекс вне диапазона!" << "\n";
            throw "Индекс вне диапазона!";
        }

        return data[index];
    }

    // Friend здесь стоит для перегрузки оператора <<,
    // чтобы функция, хоть и не являясь методом класса,
    // имела доступ к приватным полям
    friend ostream& operator << (ostream& cout, const Vector& arr) {
        for (int i = 0; i < arr.length; i++) cout << arr.data[i] << " ";
        return cout;
    }


    friend istream& operator >> (istream& cin, Vector& arr) {
        cout << "\nВсего элементов: " << arr.length;
        for (int i = 0; i < arr.length; i++) {
            cout << "\ni" << i << " = ";
            cin >> arr.data[i];
        }
        return cin;
    }

    void Print() const {
        if (length == 0) {
            cout << "Массив пуст\n";
        }
        else {
            cout << "Емкость массива: " << capacity << "\n";
            cout << "Элементы массива: ";
            for (int i = 0; i < length; i++)
            {
                cout << data[i] << " ";
            }
            cout << "\n";
        }
    }

    ~Vector() {
        if (data != nullptr) {
            delete[] data;
        }
    }

    unsigned int getLength() {
        return length;
    }

    Vector(const Vector& original) {
        this->length = original.length;
        this->capacity = original.capacity;
        this->data = new int[capacity];
        for (int i = 0; i < length; i++)
            this->data[i] = original.data[i];
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    Vector arr;

    arr.AddToBack(10);
    arr.AddToBack(100);
    arr.AddToBack(1000);
    arr.AddToFront(10);
    arr.AddToFront(100);
    arr.AddToFront(1000);
    arr.RemoveFromBack();
    arr.AddToBack(12000);
    arr.RemoveFromFront();
    arr.Insert(50, 2);
    arr.RemoveByValue(10);
    arr.Sort();
    arr.Reverse();
    arr.Shuffle();

    cout << arr[0] << " " << arr[1] << '\n';
    cout << arr;
    cout << "\n";
    cin >> arr;

    cout << "\n\n\n";

    arr.Print();

    cout << "\n" << string(55, '=') << "\n";
}
