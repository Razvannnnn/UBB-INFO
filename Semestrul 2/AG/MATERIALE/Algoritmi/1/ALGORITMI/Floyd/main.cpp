//FLOYD
#include <iostream>
#include <fstream>
#define INF 9999
using namespace std;

ifstream fin("floyd.in");

int graf[20][20],n,distante[20][20];

void citire_graf() {
	fin >> n;
	int x,y;
	while(fin>>x>>y) {
		graf[x][y] = 1;
	}
}

void floyd() {
    int i, j, k;
    for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
        if (graf[i][j] == 0) distante[i][j] = INF;
        else    distante[i][j] = 1;
    for (k = 1; k <= n; k++)
    for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
       if (distante[i][j] > (distante[i][k] + distante[k][j]) )
                    distante[i][j] = distante[i][k] + distante[k][j];
}

int main() {
	citire_graf();
	floyd();
    int i, j;

    for (i = 1; i <= n; i++)
    {for (j = 1; j <= n; j++)
            if (distante[i][j] != INF)  cout<<distante[i][j]<< ' ';
            else cout << "- ";
    cout << '\n';
    }

	return 0;
}
