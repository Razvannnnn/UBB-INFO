#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("in.txt");

int matrice_adiac[101][101];
int lista_adiac[101][101];
int matrice_incid[101][101];

int main() {
    int n, x, y, m = 0, muchie, a = 0, b = 0;
    fin >> n;
    //MATRICE ADIACENTA
    for (int i = 1; i <= n; i++) {
        fin >> x >> y;
        m++;
        matrice_adiac[x][y] = 1;
        matrice_adiac[y][x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrice_adiac[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    //LISTA ADIACENTA
    for (int i = 1; i <= n; i++) {
        lista_adiac[i][0] = 0;
        int k = 0;
        for (int j = 1; j <= n; j++) {
            if (matrice_adiac[i][j] == 1) {
                lista_adiac[i][++k] = j;
                lista_adiac[i][0]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int k = 1;
        cout << i << ". ";
        while (lista_adiac[i][k] != 0) {
            cout << lista_adiac[i][k] << " ";
            k++;
        }
        cout << "\n";
    }
    cout << "\n";

    //MATRICE INCIDENTA
    muchie = 0;
    for (int i = 1; i <= n; i++) {
        int k = lista_adiac[i][0];
        for (int j = 1; j <= k; j++) {
            if (lista_adiac[i][j] > i) {
                matrice_incid[i][++muchie] = 1;
                matrice_incid[lista_adiac[i][j]][muchie] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << matrice_incid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    //LISTA ADIACENTA
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            lista_adiac[i][j] = 0;
        }
    }
    for (int j = 1; j <= muchie; j++) {
        a = 0;
        b = 0;
        for (int i = 1; i <= m; i++) {
            if (matrice_incid[i][j] == 1) {
                if (a == 0) a = i;
                b = i;
            }
        }
        int k = lista_adiac[a][0];
        lista_adiac[a][++k] = b;
        lista_adiac[a][0] = k;
        k = lista_adiac[b][0];
        lista_adiac[b][++k] = a;
        lista_adiac[b][0] = k;
    }
    for (int i = 1; i <= n; i++) {
        int k = 1;
        cout << i << ". ";
        while (lista_adiac[i][k] != 0) {
            cout << lista_adiac[i][k] << " ";
            k++;
        }
        cout << "\n";
    }
    cout << "\n";
    //MATRICE ADIACENTA
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrice_adiac[i][j]=0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(lista_adiac[i][j]!=0)
            {
                matrice_adiac[i][lista_adiac[i][j]]=1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrice_adiac[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    //LISTA
    cout<<n<<"\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(matrice_adiac[i][j]==1) {
                cout<<i<<" "<<j<<"\n";
            }
        }
    }
    return 0;
}
