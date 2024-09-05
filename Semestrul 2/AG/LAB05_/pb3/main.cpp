#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, x, y, p = 0;
int adiac[151][151];
int viz[251];

void Euler(int k)
{
    for(int i=0; i<n; i++)
        if(adiac[k][i])
        {
            adiac[k][i] = 0;
            adiac[i][k] = 0;
            Euler(i);
        }
    viz[++p] = k;
}

int main() {
    fin>>n>>m;
    for(int i=0; i<m; i++) {
        fin>>x>>y;
        adiac[x][y] = 1;
        adiac[y][x] = 1;
    }
    Euler(0);
    for(int i=1; i<p; i++) {
        fout<<viz[i]<<" ";
    }
    return 0;
}