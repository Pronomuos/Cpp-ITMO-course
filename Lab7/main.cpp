#include <iostream>
#include "circular_buffer.h"

int main() {

    try {
        circular_buffer<int> buffer(5);
        buffer.push_back(10);
        buffer.push_back(20);
        buffer.push_back(30);
        buffer.push_front(-1);
        buffer.push_front(-2);
        buffer.push_front(-3);
        buffer.insert(buffer.begin(), 100);
        std::replace(buffer.begin(), buffer.end(), -1, 5);
        buffer.resize(10);
        int size = buffer.size();
        for (auto i = buffer.end() - 1; i != buffer.begin() - 1; i--) {
            std::cout << *i << " ";
        }
        std::cout << "\n";

        buffer.resize(3);
        std::sort(buffer.begin(), buffer.end());
        size = buffer.size();
        for (int i = 0; i < size; i++) {
            std::cout << buffer.front() << " ";
            buffer.pop_front();
        }
        std::cout << "\n";
    } catch (std::exception &ex) {
        std::cerr << ex.what();
    }

    return 0;
}
