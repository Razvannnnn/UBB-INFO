#include<iostream>
#include<fstream>
#include <queue>
#define INF 9999

using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
int D[20],grf[20][20],n;
bool in_coada[20],ok[20];

struct compara {
	bool operator()(int x, int y) {	//Suprascriem operatorul "(int,int)" pentru aceasta structura. Acum se comporta ca o functie
		return D[x] < D[y];
	}
};

priority_queue<int, vector<int>, compara>coada;

void citire_graf() {
	fin >> n;
	int i,x,y,z;
	while (fin >> x >> y >> z) {
		grf[x][y] = z;
	}
}

void dijkstra(int nod_start) {
	coada.push(nod_start);
	ok[nod_start] = 1;
	int i;
	for (i = 1; i <= n; i++)
		D[i] = INF;
	D[nod_start] = 0; // Distanta pana la nodul de inceput este 0
	in_coada[nod_start] = 1;
	while (!coada.empty()) {
		int nod_current = coada.top(); // Nodul pentru care costul de la start este minim
		int cost_current = D[nod_current]; // Costul aferent
		coada.pop(); // Eliminam elentul din coada
		in_coada[nod_current] = 0; // Acum nu mai e in coada
		for(i=1;i<=n;i++) //Parcurgem vecinii
			if (grf[nod_current][i] != 0) {
				int vecin = i, cost = grf[nod_current][i];
				if (cost_current + cost < D[vecin]) { //Daca descoperim un drum de cost mai mic
					D[vecin] = cost_current + cost; // Actualizam costul
					if (!in_coada[vecin]) { //Daca nu e deja in coada
						coada.push(vecin); // S-ar putea sa gasim in continuare cost mai mic pentru anumite noduri
						in_coada[vecin] = 1; //Acum este in coada
					}
				}
			}
	}
}

int main() {
	int nod_start, nod_final,i;
	citire_graf();
	cout << "Nodul de inceput va fi: ";
	cin >> nod_start;
	dijkstra(nod_start);
	for (i = 1; i <= n; i++)
	{
		cout << D[i] << ' '; // Scriem toate distantele de la nodul de inceput pana la nodul i
	}
	return 0;
}