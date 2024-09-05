#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

//o alta lista ca argument si toate elementele trebuie sterse


// θ(1)
ListIterator::ListIterator(const SortedIteratedList& list, int startPosition) : list(list){
    this->index = startPosition;
}


// θ(1)
void ListIterator::first(){
    this->index = this->list.head;
}


// θ(1)
void ListIterator::next(){
    if (valid()) {
        this->index = this->list.next[index];
        return ;
    }

    throw exception();
}


// θ(1)
bool ListIterator::valid() const{
    return this->index != -1;
}


// θ(1)
TComp ListIterator::getCurrent() const {
    if(this->valid()) {
        return this->list.elements[index];
    }

    throw exception();
}