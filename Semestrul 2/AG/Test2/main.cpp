#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

// Structura pentru un nod din arborele Huffman
struct Nod {
    char chr;
    int frecv;
    Nod* stanga;
    Nod* dreapta;

    Nod(char c, int f) : chr(c), frecv(f), stanga(nullptr), dreapta(nullptr) {}
};

// Comparator pentru coada de priorități
struct Compara {
    bool operator()(Nod* a, Nod* b) {
        return a->frecv > b->frecv || (a->frecv == b->frecv && a->chr < b->chr);
    }
};

// Comparator lexicografic pentru sortarea perechilor
bool comparaLexicografic(const pair<char, int>& a, const pair<char, int>& b) {
    return a.first < b.first;
}

// Funcție pentru construirea arborelui Huffman
Nod* constrArboreHuffman(const vector<pair<char, int>>& frecvente) {
    priority_queue<Nod*, vector<Nod*>, Compara> minHeap;   //coada de prioritati

    for (const auto& pereche : frecvente) {   //adaugam perechile caracter, frecv
        minHeap.push(new Nod(pereche.first, pereche.second));
    }

    while (minHeap.size() > 1) {    //construim arborele combinand nodurile cu cele mai mici frecv
        Nod* stanga = minHeap.top();
        minHeap.pop();
        Nod* dreapta = minHeap.top();
        minHeap.pop();

        Nod* parinte = new Nod('\0', stanga->frecv + dreapta->frecv); //parinte cu frecv insumata
        parinte->stanga = stanga;
        parinte->dreapta = dreapta;

        minHeap.push(parinte);   //adaugam in heap
    }

    return minHeap.top();   //radacina arborelui
}

// Funcție pentru generarea codurilor Huffman
void genCoduriHuffman(Nod* radacina, unordered_map<char, string>& coduri, const string& cod) {
    if (!radacina) {
        return;
    }

    if (!radacina->stanga && !radacina->dreapta) {   //daca e frunza adaugam codul
        coduri[radacina->chr] = cod;
    }

    genCoduriHuffman(radacina->stanga, coduri, cod + "0");
    genCoduriHuffman(radacina->dreapta, coduri, cod + "1");
}

// Funcție pentru codificarea textului folosind codurile Huffman
string codifica(const string& text, const unordered_map<char, string>& coduri) {
    string textCodificat;
    for (char c : text) {
        textCodificat += coduri.at(c);
    }
    return textCodificat;
}

// Funcție pentru decodificarea textului codificat folosind arborele Huffman
string decodifica(Nod* radacina, const string& textCodificat) {
    string textDecodificat;
    Nod* curent = radacina;

    for (char bit : textCodificat) {
        if (bit == '0') {
            curent = curent->stanga;
        } else {
            curent = curent->dreapta;
        }
        if (!curent->stanga && !curent->dreapta) {
            textDecodificat += curent->chr;
            curent = radacina;
        }
    }

    return textDecodificat;
}


int main(int argc, char** argv) {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    string text;
    getline(fin, text);
    unordered_map<char, int> frecventa;

    for (char c : text) { //calculam frecventa caracterelor
        frecventa[c]++;
    }

    vector<pair<char, int>> vectorFrecventa(frecventa.begin(), frecventa.end());
    sort(vectorFrecventa.begin(), vectorFrecventa.end(), comparaLexicografic);

    //Construirea arborelui HUFFMAN
    Nod* radacina = constrArboreHuffman(vectorFrecventa);
    unordered_map<char, string> coduri;
    genCoduriHuffman(radacina, coduri, "");  //generam codurile

    string textCodificat = codifica(text, coduri);   //codificare textul
    for (const auto& pereche : vectorFrecventa) {
        fout << pereche.first << ": " << pereche.second << "\n";
    }

    fout << "\nCoduri:\n";
    for (const auto& pereche : coduri) {
        fout << pereche.first << ": " << pereche.second << "\n";
    }

    fout << "\nText codificat:\n" << textCodificat << "\n";

    string textDecodificat = decodifica(radacina, textCodificat);

    fout << "\nText decodificat:\n" << textDecodificat << "\n";
    fin.close();
    fout.close();

    return 0;
}
