#ifndef PRACTICMELODII2_OBSERVER_H
#define PRACTICMELODII2_OBSERVER_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Observer {
public:
    virtual void doUpdate() = 0;
};

class Observable {
private:
    vector<Observer*> observers;
public:
    void addObserver(Observer* o) {
        observers.push_back(o);
    }
    void removeObserver(Observer* o) {
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notify() {
        for(auto& o:observers) {
            o->doUpdate();
        }
    }
};

#endif //PRACTICMELODII2_OBSERVER_H
