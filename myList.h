
#pragma once

//С0 Создайте класс MyList (список) с такими полями, как начальный размер элементов
//по умолчанию = 10), массив элементов.
//Реализуйте методы:
//1. добавления элемента в список - (есть);
//2. поиск элемента по индексу - .find() - да(rvalue и lvalue)
//3. удаление всех элементов; - (есть);
//4. удаление конкретного элемента; - (есть)(pop_back);
//5. обновление элемента по индексу ([]) - (есть);
//6. получение элемента по индексу; ([]) - (есть)
//7. добавление нового списка в существующий - (на джаве);
//8. проверка на пустоту - (есть);
//9. метод вывода всех элементов в консоль - (есть).
//Предусмотрите приватный метод автоматического расширения внутреннего массива (есть) и
//удалению элемента по индексу(есть). Список может хранить конкретный тип данных, а может
//и все сразу (Object)(на джаве). Решите задачу палиндрома из предыдущей лабораторной, используя
//этот класс.(есть)
//* Создайте методы сортировки списка (учесть, что сортировка может быть не только
//чисел), обрезки (указать первую позицию и последнюю, это будет промежуток который
//будет удален из списка) и метод, который определяет существует ли элемент в списке
//или нет.

template <typename T>
class myList {
private:
    int capacity = 10;

    // массив для хранения
    T* elements;

    // начальная позиция в массиве
    int size = 0;

    void expand() {
        const int new_capacity = capacity * 1.5;

        T* new_elements = new T[new_capacity];

        for (int i = 0;i < size;i++) {
            new_elements[i] = std::move(elements[i]);
        }

        delete[] elements;

        elements = new_elements;
        capacity = new_capacity;


    }


public:
    myList() {
        elements = new T[capacity];
    }
    // 1. добавления элемента в список
    void add(const T& element) {
        if (size >= capacity) {
            expand();
        }
        elements[size] = std::move(element);
        size++;
    }

    //2. поиск элемента по индексу - .find() - да(rvalue и lvalue)
    void find_by_index(const T& index) {
        if(size > 0 && elements[index]) {
            std::cout << "Value under index [" << index << "] is exist, value: " << elements[index];
        }
        else {
            std::cout << "Index out of bounds or size of array <= 0";
        }
    }

    //4. удаление конкретного элемента; - (есть)
    void pop_back() {
        if(size == 0 ) {
            return;
        }
        // удаление самого элемента но не ячейки памяти(важно), вызов деструктора здесь удаление значение и возвращает память
        elements[size - 1].~T();
        size--;
    }

    void erase_at(const T& index) {
        if (index < 0 || index > size - 1 ) {
            return;
        }

        elements[index].~T();

        for (int i = index; i + 1 < size; i++) {
            elements[i] = std::move(elements[i+1]);
        }
        --size;

    }
    //3. удаление всех элементов; - (есть);
    void pop_all() {
        while(size > 0) {
            pop_back();
        }
    }
    //6. получение элемента по индексу; ([])
    T& operator[](int index) {
        return elements[index];
    }

    // 9. метод вывода всех элементов в консоль
    void show_list() {
        if(size == 0) {
            std::cout << "List is empty\n";
            return;
        }
        std::cout << "[";
        for (int i = 0; i < size ; i++) {
            std::cout << elements[i];
            if (i != size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    //8. проверка на пустоту;
    bool is_empty() {
        return size == 0;
    }

    int list_size() {
        return size;
    }


    ~myList() {
        delete[] elements;
    }
};