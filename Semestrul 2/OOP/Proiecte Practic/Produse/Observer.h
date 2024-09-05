o#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>
#include <algorithm>

using namespace std;

class Observer{
public:
    virtual void doUpdate() = 0;
};

class Observable{
private:
    vector<Observer*> observers;
public:
    void addObserver(Observer* o){
        observers.push_back(o);
    }
    void removeObserver(Observer* o){
        observers.erase(remove(observers.begin(),observers.end(),o),observers.end());
    }
    void notify(){
        for(auto& x : observers){
            x->doUpdate();
        }
    }
};

#endif // OBSERVER_H
