#include <iostream>
#include <fstream>
#define INF 9999

using namespace std;
ifstream fin("bellman.in");
ofstream fout("bellman.out");

int n,grf[20][20],distante[20],parinte[20];

void citire_graf() {
	fin >> n;
	int x, y, z,i,j;
	while (fin >> x >> y>>z) {
		grf[x][y] = z;
	}
}

void relaxare(int j, int k) {
	if (distante[k] > distante[j] + grf[j][k]) {
		distante[k] = distante[j] + grf[j][k];
		parinte[k] = j;
	}
}

bool bellman(int nod_start) {
	int i,j,k;
	for (i = 1; i <= n; i++)
	{
		distante[i] = INF; // Presupunem ca toate distantele sunt infinit
		parinte[i] = -1; // Parinte null
	}
	distante[nod_start]= 0; // Distanta de la inceput la inceput e 0
	parinte[nod_start]= 0; // Parintele inceputului e 0

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			for (k = 1; k <= n; k++)
			{
				if (grf[j][k] != 0 ) { // Daca exista o muchie intre j si k
					relaxare(j, k); // Incercam sa verificam daca se merita sa ajungem la nodul k, trecand prin nodul j
				}
			}
	}
	for (j = 1; j <= n; j++)
		for (k = 1; k <= n; k++)
		{
			if (grf[j][k] != 0 && distante[k] > distante[j] + grf[j][k]) { // Daca mai exista o relaxare atunci inseamna ca avem ciclu infinit
				return false;
			}
		}
	return true;

}

int main() {
	citire_graf();

	int nod_start,i;
	cout << "Nodul de start este: ";
	cin >> nod_start;
	bool ok = bellman(nod_start);
	if (!ok) {
		fout << "Ciclu infinit!";
		return 0;
	}
	for (i = 1; i <= n; i++)
		fout << distante[i]<<' '<<parinte[i]<<endl;
	return 0;
}