#include <iostream>

#include "TestScurt.h"
#include "TestExtins.h"
#include "LO.h"
#include "Iterator.h"
#include <assert.h>
bool cresc2(TElement c1, TElement c2) {
    if (c1 <= c2) {
        return true;
    } else {
        return false;
    }
}
int main(){
    testAll();
    testAllExtins();
    std::cout<<"Started LI Tests!"<<std::endl;
    LO lo = LO(cresc2);
    lo.adauga(1);
    lo.adauga(2);
    assert(lo.dim() == 2);
    std::cout<<"Finished LI Tests!"<<std::endl;

}