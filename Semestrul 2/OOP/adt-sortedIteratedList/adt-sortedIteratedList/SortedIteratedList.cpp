#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>


// θ(n)
SortedIteratedList::SortedIteratedList(Relation r) {
    this->capacity = 10;
    this->length = 0;
    this->head = -1;
    this->tail = -1;
    this->r = r;
    this->elements = new TComp[this->capacity];
    this->next = new int[this->capacity];
    this->previous = new int[this->capacity];
    
    for(int index = 0; index < this->capacity; ++index) {
        this->next[index] = index + 1;
        this->previous[index] = index - 1;
    }
    
    this->next[this->capacity - 1] = -1;
    this->firstEmpty = 0;
}


// θ(1)
int SortedIteratedList::size() const {
    return this->length;
}


// θ(1)
bool SortedIteratedList::isEmpty() const {
    return this->size() == 0;
}


// θ(1)
ListIterator SortedIteratedList::first() const {
    ListIterator iterator = ListIterator(*this, this->head);
    return iterator;
}


// θ(1)
TComp SortedIteratedList::getElement(ListIterator pos) {
    if (pos.valid()) {
        return pos.getCurrent();
    }

    throw exception();
}

// θ(n)
void SortedIteratedList::resize() {
    int newCapacity = this->capacity * 2;
    auto* newElements = new TComp[newCapacity];
    int* newNextIndexes = new int[newCapacity];
    int* newPreviousIndexes = new int[newCapacity];

    for(int index = 0; index < newCapacity; ++index) {
        newNextIndexes[index] = index + 1;
        newPreviousIndexes[index] = index - 1;
    }
    newNextIndexes[newCapacity - 1] = -1;

    for (int index = 0; index < this->capacity; ++index) {
        newElements[index] = this->elements[index];
        newNextIndexes[index] = this->next[index];
        newPreviousIndexes[index] = this->previous[index];
    }

    delete[] this->elements;
    delete[] this->next;
    delete[] this->previous;

    this->elements = newElements;
    this->next = newNextIndexes;
    this->previous = newPreviousIndexes;

    int currentIndex = this->head;
    while (this->next[currentIndex] != -1) {
        currentIndex = this->next[currentIndex];
    }
    
    this->next[currentIndex] = -1;
    this->firstEmpty = this->capacity;
    this->capacity = newCapacity;
}


/*
 * best case: θ(1)
 * average case: θ(n)
 * worst case: θ(n)
 * overall: O(n)
 */
TComp SortedIteratedList::remove(ListIterator& pos) {
    if (!pos.valid())
        throw exception();

    int removePosition = pos.index;
    TComp oldValue = this->elements[removePosition];


    if (removePosition == this->head) {
        this->head = this->next[this->head];
    }

    if(removePosition == this->tail) {
        this->tail = this->previous[this->tail];
    }
    else {
        int prev = -1, currentIndex = this->head;

        while (currentIndex != -1 && currentIndex != removePosition) {
            prev = currentIndex;
            currentIndex = this->next[currentIndex];
        }
        if (currentIndex != -1) {
            this->next[prev] = this->next[currentIndex];
            this->previous[this->next[currentIndex]] = prev;
        }
    }

    pos.next();

    this->previous[this->firstEmpty] = removePosition;
    this->next[removePosition] = this->firstEmpty;
    this->firstEmpty = removePosition;
    this->length--;

    return oldValue;
}


/*
 * best case: θ(1)
 * average case: θ(n)
 * worst case: θ(n)
 * overall: O(n)
 */
void SortedIteratedList::add(TComp e) {
    if (this->length == this->capacity)
        resize();

    int newIndex = this->firstEmpty;
    this->elements[newIndex] = e;
    this->firstEmpty = next[this->firstEmpty];
    previous[this->firstEmpty] = -1;

    int prev = -1;
    int currentIndex = this->head;
    while (currentIndex != -1 && this->r(this->elements[currentIndex], e)) {
        prev = currentIndex;
        currentIndex = this->next[currentIndex];
    }

    if (prev == -1) {
        this->next[newIndex] = this->head;
        this->head = newIndex;
        this->tail = newIndex;
    } else {
        this->next[newIndex] = this->next[prev];
        this->next[prev] = newIndex;
    }

    this->length++;
}


/*
 * best case: θ(1)
 * average case: θ(n)
 * worst case: θ(n)
 * overall: O(n)
 */
ListIterator SortedIteratedList::search(TComp e) const {
    int currentIndex = this->head;
    while (currentIndex != -1) {
        if (this->elements[currentIndex] == e) {
            ListIterator iterator = ListIterator(*this, currentIndex);
            return iterator;
        }

        currentIndex = this->next[currentIndex];
    }

    ListIterator iterator = ListIterator(*this, -1);
    return iterator;
}


/*
 * best case: θ(1) - the given list is empty
 * average case: θ(n^2)
 * worst case: θ(n^2)
 * overall: O(n^2)
 */
void SortedIteratedList::deleteElements(const SortedIteratedList &list) {
    int listIndex = list.head;
    int currentIndex = this->head;
    int previousIndex = -1;
    while(listIndex != -1) {
        while(currentIndex != -1 && this->r(list.elements[listIndex], this->elements[currentIndex])) {
            if(list.elements[listIndex] == this->elements[currentIndex]) {
                if(currentIndex == this->head) {
                    this->head = this->next[this->head];
                    this->previous[this->head] = -1;
                }
                else if(currentIndex == this->tail){
                    this->tail = this->previous[this->tail];
                    this->next[this->tail] = -1;
                }

                if (currentIndex != -1) {
                    this->next[previousIndex] = this->next[currentIndex];
                    this->previous[this->next[currentIndex]] = previousIndex;
                }

                this->previous[this->firstEmpty] = currentIndex;
                this->next[currentIndex] = this->firstEmpty;
                this->firstEmpty = currentIndex;

                currentIndex = this->next[currentIndex];
                this->previous[currentIndex] = previousIndex;
                this->length--;
            }
            else {
                previousIndex = currentIndex;
                currentIndex = next[currentIndex];
            }
        }

        listIndex = list.next[listIndex];
    }
}


// θ(1)
SortedIteratedList::~SortedIteratedList() {
    delete[] this->elements;
    delete[] this->next;
    delete[] this->previous;
}