#pragma once

template <typename T>
class myContainer {
private:
    int size = 0;
    uint64_t capacity = 5;

    T* container;

    void realloc_mem() {
        uint64_t new_capacity = capacity * 2;

        T* new_container = new T[new_capacity];

        for (int i = 0; i < size; i++) {
            new_container[i] = std::move(container[i]);
        }
        delete[] container;
        container = new_container;
        capacity = new_capacity;
    }

public:
    myContainer() {
        container = new T[capacity];
    }

    void push_back(const T& element) {
        if (size >= capacity) {
            realloc_mem();
        }
        container[size] = std::move(element);
        size++;
    }
    void pop_back() {
        if (size == 0) {
            std::cout << "Container is empty" << std::endl;
            return;
        }
        container[size-1].~T();
        size--;
    }

    void pop_all() {
        if (size == 0) {
            return;
        }
        while (size != 0) {
            pop_back();
        }
    }

    void show_container() {
        std::cout << "[";
        for (int i = 0; i < size; i++) {
            std::cout << container[i];
            if (i != size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    void find_by_index(const int& index) {
        for (int i = 0; i < size;i++) {
            if (container[index]) {
                std::cout << "Value under index [" << index << "] is exist, value: " << container[index];
                return;
            }
            else {
                std::cout << "Index out of bounds or size of array <= 0";
                return;
            }
        }
    }

    void erase_at(int&& index) {
        container[index].~T();
        for (int i = index; i < size;i++) {
            container[i] = std::move(container[i+1]);
        }
        size--;
    }

    int cont_size() {
        return size;
    }

    void operator[](const int& index) {
        return container[index];
    }

    bool is_empty() {
        return size == 0;
    }

    uint64_t show_capacity() {
        return capacity;
    }

    ~myContainer() {
        delete[] container;
        std::cout << "container deleted" << std::endl;
    }

};