#ifndef VECTORDINAMICCPP_VECTORDINAMICTEMPLATE_H
#define VECTORDINAMICCPP_VECTORDINAMICTEMPLATE_H

template <typename ElemenT>
class IteratorVectorT;

template <typename ElemenT>
class VectDinNewDeleteT {
private:
    int dimensiune;
    int capacitate;
    ElemenT* elemente;
public:
    VectDinNewDeleteT();                                   //Constructor
    VectDinNewDeleteT(const VectDinNewDeleteT& obiect);               //Constructor copiere
    ~VectDinNewDeleteT();                                  //Destructor
    VectDinNewDeleteT& operator=(const VectDinNewDeleteT& obiect);    //Constructor de mutare

    VectDinNewDeleteT(VectDinNewDeleteT&& obiect);
    VectDinNewDeleteT& operator=(VectDinNewDeleteT&& obiect) noexcept ;

    void add(const ElemenT& element);
    void redimensionare();
    ElemenT& get(int poz);

    int size();
    void erase(int poz);
    ElemenT& operator[](int index);

    friend class IteratorVectorT<ElemenT>;
    IteratorVectorT<ElemenT> begin();
    IteratorVectorT<ElemenT> end();
};

template <typename ElemenT>
class IteratorVectorT {
private:
    VectDinNewDeleteT<ElemenT>& vector;
    int poz = 0;
public:
    IteratorVectorT(VectDinNewDeleteT<ElemenT>& vector);
    IteratorVectorT(VectDinNewDeleteT<ElemenT>& vector, int poz);
    ElemenT& element();
    void urmator();
    ElemenT& operator*();
    IteratorVectorT& operator++();
    bool operator==(IteratorVectorT& obiect);
    bool operator!=(IteratorVectorT& obiect);
};

template <typename ElemenT>
VectDinNewDeleteT<ElemenT>::VectDinNewDeleteT(): elemente{new ElemenT[10]}, capacitate{10}, dimensiune{0} {
}

template <typename ElemenT>
VectDinNewDeleteT<ElemenT>::VectDinNewDeleteT(const VectDinNewDeleteT& obiect) {
    elemente = new ElemenT[obiect.capacitate];
    for(int i=0;i<obiect.dimensiune;i++) {
        elemente[i] = obiect.elemente[i];
    }
    dimensiune = obiect.dimensiune;
    capacitate = obiect.capacitate;
}

template <typename ElemenT>
VectDinNewDeleteT<ElemenT>::~VectDinNewDeleteT() {
    delete[] elemente;
}

template <typename ElemenT>
VectDinNewDeleteT<ElemenT> &VectDinNewDeleteT<ElemenT>::operator=(const VectDinNewDeleteT<ElemenT> &obiect) {
    if(this == &obiect){
        return *this;
    }
    delete[] elemente;
    elemente = new ElemenT[obiect.capacitate];
    for(int i=0;i<obiect.dimensiune;i++) {
        elemente[i] = obiect.elemente[i];
    }
    dimensiune = obiect.dimensiune;
    capacitate = obiect.capacitate;
    return *this;
}

template <typename ElemenT>
VectDinNewDeleteT<ElemenT>::VectDinNewDeleteT(VectDinNewDeleteT&& obiect) {
    elemente = obiect.elemente;
    capacitate = obiect.capacitate;
    dimensiune = obiect.dimensiune;

    obiect.elemente = nullptr;
    obiect.dimensiune = 0;
    obiect.capacitate = 0;
}

template <typename ElemenT>
VectDinNewDeleteT<ElemenT>& VectDinNewDeleteT<ElemenT>::operator=(VectDinNewDeleteT<ElemenT> &&obiect)  noexcept {
    if(this == &obiect) {
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

template <typename ElemenT>
void VectDinNewDeleteT<ElemenT>::redimensionare() {
    if(dimensiune < capacitate) {
        return;
    }
    capacitate = capacitate * 2;
    ElemenT* aux = new ElemenT[capacitate];
    for(int i=0;i<dimensiune;i++) {
        aux[i] = elemente[i];
    }
    delete[] elemente;
    elemente = aux;
}

template <typename ElemenT>
void VectDinNewDeleteT<ElemenT>::add(const ElemenT &element) {
    redimensionare();
    elemente[dimensiune++] = element;
}

template<typename ElemenT>
ElemenT &VectDinNewDeleteT<ElemenT>::operator[](int index) {
    return elemente[index];
}

template <typename ElemenT>
ElemenT& VectDinNewDeleteT<ElemenT>::get(int poz) {
    return elemente[poz];
}

template <typename ElemenT>
int  VectDinNewDeleteT<ElemenT>::size() {
    return dimensiune;
}

template <typename ElemenT>
void VectDinNewDeleteT<ElemenT>::erase(int poz) {
    if(poz < 0 || poz >= dimensiune) return;
    for(int i=poz;i<dimensiune;i++) {
        elemente[i] = elemente[i+1];
    }
    dimensiune--;
}

template <typename ElemenT>
IteratorVectorT<ElemenT> VectDinNewDeleteT<ElemenT>::begin() {
    return IteratorVectorT<ElemenT>(*this);
}

template <typename ElemenT>
IteratorVectorT<ElemenT> VectDinNewDeleteT<ElemenT>::end() {
    return IteratorVectorT<ElemenT>(*this, dimensiune);
}


template <typename ElemenT>
IteratorVectorT<ElemenT>::IteratorVectorT(VectDinNewDeleteT<ElemenT> &vector) : vector{vector } {
}

template <typename ElemenT>
IteratorVectorT<ElemenT>::IteratorVectorT(VectDinNewDeleteT<ElemenT> &vector, int poz) : vector{vector }, poz{poz} {
}

template<typename ElemenT>
ElemenT &IteratorVectorT<ElemenT>::element() {
    return vector.elemente[poz];
}

template<typename ElemenT>
void IteratorVectorT<ElemenT>::urmator() {
    poz++;
}

template<typename ElemenT>
ElemenT &IteratorVectorT<ElemenT>::operator*() {
    return element();
}

template<typename ElemenT>
IteratorVectorT<ElemenT>& IteratorVectorT<ElemenT>::operator++() {
    urmator();
    return *this;
}

template<typename ElemenT>
bool IteratorVectorT<ElemenT>::operator!=(IteratorVectorT &obiect) {
    return !(*this == obiect);
}

template<typename ElemenT>
bool IteratorVectorT<ElemenT>::operator==(IteratorVectorT &obiect) {
    return poz == obiect.poz;
}


#endif