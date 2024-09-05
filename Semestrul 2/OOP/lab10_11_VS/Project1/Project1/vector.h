#pragma once

template <typename Elem>
class IteratorVector;

template <typename Elem>
class Vector {
private:
    int dimensiune; //nr elemente
    int capacitate; //capacitatea
    Elem* elemente; //elementele
public:
    //Constructor
    Vector();

    //Constructor copiere
    Vector(const Vector& obiect);

    //Destructor
    ~Vector();

    /*
      Operator assgnment
      elibereaza ce era in obiectul curent obiect
      aloca spatiu pentru elemente
      copieaza elementele din ot in this
     */
    Vector& operator=(const Vector& obiect);

    /*
     Move constructor
     Obiectul obiect nu se mai foloseste astfel se poate refolosi interiorul lui
    */
    Vector(Vector&& obiect);

    //Move assignment
    Vector& operator=(Vector&& obiect) noexcept;

    //Adaugare
    void push_back(const Elem& element);
    //Redimensionare in cazul in care lista este plina
    void redimensionare();
    Elem& get(int poz);
    //Returneaza dimensiunea
    int size();
    //Stergere
    void erase(int poz);
    Elem& operator[](int index);

    friend class IteratorVector<Elem>;
    //Functii care creeaza iteratori
    IteratorVector<Elem> begin();
    IteratorVector<Elem> end();
};

template <typename Elem>
class IteratorVector {
private:
    Vector<Elem>& vector;
    int poz = 0;
public:
    //Constructori
    IteratorVector(Vector<Elem>& vector);
    IteratorVector(Vector<Elem>& vector, int poz);

    //Returneaza referinta la elementul curent
    Elem& element();

    //Muta iteratorul la urmatorul element
    void urmator();

    //Suprascrie operatorul *
    Elem& operator*();

    //Suprascrie operatorul ++
    IteratorVector& operator++();

    //Suprascrie operatul ==
    bool operator==(IteratorVector& obiect);

    //Suprascrie operatorul !=
    bool operator!=(IteratorVector& obiect);
};

template <typename Elem>
Vector<Elem>::Vector() : elemente{ new Elem[10] }, capacitate{ 10 }, dimensiune{ 0 } {
}

template <typename Elem>
Vector<Elem>::Vector(const Vector& obiect) {
    elemente = new Elem[obiect.capacitate];
    for (int i = 0; i < obiect.dimensiune; i++) {
        elemente[i] = obiect.elemente[i];
    }
    dimensiune = obiect.dimensiune;
    capacitate = obiect.capacitate;
}

template <typename Elem>
Vector<Elem>::~Vector() {
    delete[] elemente;
}

template <typename Elem>
Vector<Elem>& Vector<Elem>::operator=(const Vector<Elem>& obiect) {
    if (this == &obiect) return *this;
    delete[] elemente;
    elemente = new Elem[obiect.capacitate];
    for (int i = 0; i < obiect.dimensiune; i++) {
        elemente[i] = obiect.elemente[i];
    }
    dimensiune = obiect.dimensiune;
    capacitate = obiect.capacitate;
    return *this;
}

template <typename Elem>
Vector<Elem>::Vector(Vector&& obiect) {
    elemente = obiect.elemente;
    capacitate = obiect.capacitate;
    dimensiune = obiect.dimensiune;

    obiect.elemente = nullptr;
    obiect.dimensiune = 0;
    obiect.capacitate = 0;
}

template <typename Elem>
Vector<Elem>& Vector<Elem>::operator=(Vector<Elem>&& obiect)  noexcept {
    if (this == &obiect) {
        return *this;
    }
    delete[] elemente;

    elemente = obiect.elemente;
    capacitate = obiect.capacitate;
    dimensiune = obiect.dimensiune;

    obiect.elemente = nullptr;
    obiect.dimensiune = 0;
    obiect.capacitate = 0;
    return *this;
}

template <typename Elem>
void Vector<Elem>::redimensionare() {
    if (dimensiune < capacitate) {
        return;
    }
    capacitate = capacitate * 2;
    Elem* aux = new Elem[capacitate];
    for (int i = 0; i < dimensiune; i++) {
        aux[i] = elemente[i];
    }
    delete[] elemente;
    elemente = aux;
}

template <typename Elem>
void Vector<Elem>::push_back(const Elem& element) {
    redimensionare();
    elemente[dimensiune++] = element;
}

template<typename Elem>
Elem& Vector<Elem>::operator[](int index) {
    return elemente[index];
}

template <typename Elem>
Elem& Vector<Elem>::get(int poz) {
    return elemente[poz];
}

template <typename Elem>
int  Vector<Elem>::size() {
    return dimensiune;
}

template <typename Elem>
void Vector<Elem>::erase(int poz) {
    if (poz < 0 || poz >= dimensiune) return;
    for (int i = poz; i < dimensiune; i++) {
        elemente[i] = elemente[i + 1];
    }
    dimensiune--;
}

template <typename Elem>
IteratorVector<Elem> Vector<Elem>::begin() {
    return IteratorVector<Elem>(*this);
}

template <typename Elem>
IteratorVector<Elem> Vector<Elem>::end() {
    return IteratorVector<Elem>(*this, dimensiune);
}


template <typename Elem>
IteratorVector<Elem>::IteratorVector(Vector<Elem>& vector) : vector{ vector } {
}

template <typename Elem>
IteratorVector<Elem>::IteratorVector(Vector<Elem>& vector, int poz) : vector{ vector }, poz{ poz } {
}

template<typename Elem>
Elem& IteratorVector<Elem>::element() {
    return vector.elemente[poz];
}

template<typename Elem>
void IteratorVector<Elem>::urmator() {
    poz++;
}

template<typename Elem>
Elem& IteratorVector<Elem>::operator*() {
    return element();
}

template<typename Elem>
IteratorVector<Elem>& IteratorVector<Elem>::operator++() {
    urmator();
    return *this;
}

template<typename Elem>
bool IteratorVector<Elem>::operator!=(IteratorVector& obiect) {
    return !(*this == obiect);
}

template<typename Elem>
bool IteratorVector<Elem>::operator==(IteratorVector& obiect) {
    return poz == obiect.poz;
}
