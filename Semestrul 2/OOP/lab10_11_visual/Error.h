#ifndef LAB6_ERROR_H
#define LAB6_ERROR_H

#include <string>
#include <utility>

using namespace std;

class Exceptie {
    string msg;
public:
    explicit Exceptie(string m) : msg{std::move(std::move(m))} {
    }

    string getMsg() {
        return msg;
    }
};

#endif //LAB6_ERROR_H
