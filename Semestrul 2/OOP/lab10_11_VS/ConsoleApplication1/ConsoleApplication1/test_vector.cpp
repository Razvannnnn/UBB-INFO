//
// Created by razva on 09.04.2024.
//

#include "vector.h"
#include <iostream>

int main() {
    Vector<int>v;
    v.push_back(2);
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
    }
    return 0;
}