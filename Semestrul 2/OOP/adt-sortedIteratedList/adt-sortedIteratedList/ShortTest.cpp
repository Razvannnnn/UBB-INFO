#include <assert.h>
#include "iostream"

#include "SortedIteratedList.h"
#include "ListIterator.h"

#include <exception>
using namespace std;

bool relation1(TComp e1, TComp e2) {
	if (e1 <= e2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedIteratedList list = SortedIteratedList(relation1);
	assert(list.size() == 0);
	assert(list.isEmpty());
    list.add(1);
    assert(list.size() == 1);
    assert(!list.isEmpty());
    ListIterator it = list.search(1);
    assert(it.valid());
    assert(it.getCurrent() == 1);
    it.next();
    assert(!it.valid());
    it.first();
    assert(it.valid());
    ListIterator itFirst = list.first();
    assert(itFirst.valid());
    assert(itFirst.getCurrent() == 1);
    assert(list.remove(it) == 1);
    assert(list.size() == 0);
    assert(list.isEmpty());
}

