#ifndef LAB6_UI_H
#define LAB6_UI_H

#include "service.h"

class UI {
private:
    serviceProdus& service;
public:
    explicit UI(serviceProdus& service) :service{ service } {
    }

    void startUI();
    void meniuCos();
};

#endif //LAB6_UI_H
