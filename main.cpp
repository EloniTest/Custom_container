#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
#include <stack>
#include <queue>
#include  <deque>
#include <format>
#include <sstream>
#include <list>
#include <map>
#include <memory>
#include <utility>

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <utility>

#include "myList.h"
#include "myContainer.h"



void bin_search(const std::vector<int>& v,int value ) {
    int low = 0;
    int high = v.size()-1;
    while (low <= high) {
        int mid = (low+high)/2;
        if (value == v[mid]) {
            std::cout << "Your value founded! " << mid << '\n';
            break;
        }
        else if (value > v[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
}

void bubble_sort(std::vector<int>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

void show_vector(const std::vector<int>& v) {
    for (int num : v) {
        std::cout << num << ' ';
    }
}

template <typename T>
bool is_palindrom(const T& arg) {
    int left = 0;
    int right = arg.size() - 1;
    while (left < right) {
        if (arg[left] != arg[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

template <typename T>
bool is_palindrom(myList<T> & arg) {
    int left = 0;
    int right = arg.list_size() - 1;
    while (left < right) {
        if (arg[left] != arg[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}


int main() {
    // std::vector<int> v = {-1,12,25,1,2,3,405,5,-2,-64,-12};
    // std::string text = "hello";
    // std::vector<int> v0 = {1,2,3,2,1};
    // show_vector(v);
    // std::cout << '\n';
    // bubble_sort(v);
    // show_vector(v);
    // std::cout << '\n';
    // bin_search(v,12);
    // std::cout << '\n';

    myContainer<int> vec;
    for (int i = 0; i < 15; i++) {
        vec.push_back(i);
        std::cout << vec.cont_size() << '|' << vec.show_capacity() << '\n';
    }
}