#include <string>


struct Node {
    std::string key = "";
    int value;
};

class hashmap {
private:

    Node* elements;
    int capacity = 32;
    int size = 0;

    void realloc() {
        if (size == capacity) {
            elements = new Node[capacity * 2];
        }
    }


public:
    hashmap() {
        elements = new Node[capacity];
    }

    int hash(std::string key) {
        int sum =0;
        for (int i = 0; i < key.length(); i++) {
            sum = sum + key[i] * (i+1);
        }
        return sum;
    }

    void add(std::string key, int value) {
        realloc();
        int hashed = hash(key); // get hash of key
        if (elements[hashed].key != "") {
            int temp = hashed + 1; // next elem
            while (elements[temp].key != "") {
                temp++;
            }
            elements[temp].key = key;
            elements[temp].value = value;
        }
        else {
            elements[hashed].key = key;
            elements[hashed].value = value;
        }
        size++;
    }
    int get(std::string key) {
        int hash_key = hash(key); // get hash of key
        if (elements[hash_key].key == key) {
            return elements[hash_key].value;
        }
        else {
            for (int i = hash_key + 1; i < hash_key + capacity; i++) {
                if (i == hash_key) break;
                if (elements[i].key == key) {
                    return elements[i].value;
                }
            }
            return -1;
        }
    }
    ~hashmap() {
        delete[] elements;
    }
};