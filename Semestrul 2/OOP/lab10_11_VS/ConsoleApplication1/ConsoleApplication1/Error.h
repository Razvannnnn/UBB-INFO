#pragma once

#include <string>
#include <utility>

using namespace std;

class Exceptie {
    string msg;
public:
    explicit Exceptie(string m) : msg{ std::move(std::move(m)) } {
    }

    string getMsg() {
        return msg;
    }
};
