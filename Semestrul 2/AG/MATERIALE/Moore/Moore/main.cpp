#include <iostream>
#include <queue>
#include <fstream>
#define INF 9999

using namespace std;
ifstream fin("moore.in");
ofstream fout("moore.out");

bool ok[20],grf[20][20];
int parinte[20],distanta[20],n;
queue<int>coada;

void moore(int nod_start) {
	int i;
	for (i = 1; i <= n; i++)
		distanta[i] = INF; // Distanta pana la nodul i este infinit
	distanta[nod_start] = 0; // Distanta de la start pana la start este 0
	ok[nod_start] = 1;
	coada.push(nod_start);
	while (!coada.empty()) {
		int current = coada.front();
		coada.pop();
		for (i = 1; i <= n; i++) { // Parcurgem vecinii nodului curent
			if (grf[current][i] && !ok[i]) { // Daca exista un drum de la curent la i si daca nu a mai fost parcurs nodul i
				coada.push(i);
				ok[i] = 1; // Nodul a fost parcurs
				parinte[i] = current;
				distanta[i] = distanta[current] + 1;
			}
		}
	}
}

void citeste_graf() {
	fin >> n;
	int x, y;
	while (fin >> x >> y) {
		grf[x][y] = 1;
	}
}

int main() {
	citeste_graf();
	int nod_start;
	cout << "Nodul de inceput este: ";
	cin >> nod_start;
	moore(nod_start);
	for (int i = 1; i <= n; i++) {
		if (distanta[i] != INF)fout << distanta[i] << ' ';
		else fout << "- ";
	}
	return 0;
}