#pragma once


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
