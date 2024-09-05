#ifndef LAB6_OBSERVER_H
#define LAB6_OBSERVER_H

#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void update() = 0;
};

class Observable {
private:
    std::vector<Observer*> observers;
public:
    void addObserver(Observer* o) {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) {
        observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
    }

    void notify() {
        for(auto o : observers) {
            o->update();
        }
    }
};

#endif //LAB6_OBSERVER_H
