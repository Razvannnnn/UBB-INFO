#include <iostream>
#include <fstream>
#define INF 9999

using namespace std;

ifstream fin("floyd.in");
ofstream fout("floyd.out");

int grf[20][20],n,distante[20][20];

void citire_graf() {
	fin >> n;
	int x, y;
	while (fin >> x >> y) {
		grf[x][y] = 1;
	}
}

void floyd() {
    int i, j, k;

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= n; ++j)
            if (grf[i][j] == 0)
            {
                distante[i][j] = INF; // Initializam orice distanta de la i la j cu infinit daca nu exista un arc intre ele
            }
            else
                distante[i][j] = 1; // Daca exista muchie, distanta este 1 (nu avem costuri)
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (distante[i][j] > (distante[i][k] + distante[k][j]) ) // Daca intre nodul i si nodul j, este mai eficient sa trecem prin k
                    distante[i][j] = distante[i][k] + distante[k][j]; // Daca se merita actualizam
            }
        }
    }
}

int main() {

	citire_graf();
	floyd();

    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (distante[i][j] != INF)fout << distante[i][j] << ' ';
            else fout << "- "; // "-" inseamna ca intre cele doua nu exista nici un drum
        fout << '\n';
    }

	return 0;
}