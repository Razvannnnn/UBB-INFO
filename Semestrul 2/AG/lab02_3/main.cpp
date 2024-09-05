#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <stdlib.h>

using namespace std;

ifstream fin("labirint_1.txt");

int n, m, istart, ifinal, jstart, jfinal, auxmatrix[251][251];
int di[5] = {0, 1,-1, 0};
int dj[5] = {1, 0, 0, -1};
char matrix[251][251];

struct Coordonate
{
    int linie, coloana;
};

Coordonate Q[251];

void lee(int istart ,int jstart ,int v)
{
    int st = 1 , dr = 0;
    Q[++dr].linie = istart, Q[dr].coloana = jstart;
    auxmatrix[istart][jstart] = v++;
    while(st <= dr)
    {
        int i, j;
        i = Q[st].linie;
        j = Q[st].coloana;
        for(int k = 0 ; k < 4 ; k ++)
        {
            int ivecin, jvecin;
            ivecin = i + di[k];
            jvecin = j + dj[k];
            if(ivecin >= 1 && ivecin <= n && jvecin >= 1 && jvecin <= m && auxmatrix[ivecin][jvecin] == 0)
            {
                auxmatrix[ivecin][jvecin] = auxmatrix[i][j]+1;
                Q[++dr].linie = ivecin;
                Q[dr].coloana = jvecin;
            }
        }
        st++;
    }
}

void Traseu(int i, int j , int lg)
{
    if(auxmatrix[i][j] == 2)
    {
        cout <<"Lungime: "<< lg << "\n";
        cout << i << " " << j << "\n";
    }
    else
    {
        int p = -1;
        for(int k = 0 ; k < 4 && p == -1 ; k ++)
            if(auxmatrix[i][j] == auxmatrix[i+di[k]][j+dj[k]] + 1)
                p = k;
        Traseu(i + di[p] , j + dj[p] , lg + 1);
        cout << i << " " << j << "\n";
    }
}


int main() {
    int len = 0;
    n=0;
    while(fin.getline(matrix[n], 50))
    {
        n++;
        cout<<matrix[n]<<"\n";
    }
    m=strlen(matrix[0]);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            auxmatrix[i][j] = 0;
            if (matrix[i][j] == 'S') {
                istart = i;
                jstart = j;
            }
            if (matrix[i][j] == 'F') {
                ifinal = i;
                jfinal = j;
            }
            if (matrix[i][j] == '1') auxmatrix[i][j] = 1;
        }
    }
    lee(istart, jstart, 2);
    Traseu(ifinal, jfinal, len);
    return 0;
}

//SOLUTIE PENTRU LABIRINT