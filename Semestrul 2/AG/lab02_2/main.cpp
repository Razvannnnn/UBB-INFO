#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("graf.txt");

int matrix[51][51], matrix_tranzitv[51][51], coada[101], st, dr;

int main() {
    int n, x, y;
    fin>>n;
    while(fin>>x>>y)
    {
        matrix[x][y] = 1;
    }
    for(int i=1;i<=n;i++) {
        st = 0;
        coada[0] = i;
        dr = 1;
        while (st < dr) {
            for(int j=1;j<=n;j++) {
                if(matrix[coada[st]][j]==1) {
                    coada[dr++] = j;
                }
            }
            st++;
            if(st != dr) {
                matrix_tranzitv[i][coada[st]] = 1;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix_tranzitv[i][j] << " ";
        }
        cout<<"\n";
    }
    return 0;
}

// MATRICEA DE INCHIDERE TRANZITIVA