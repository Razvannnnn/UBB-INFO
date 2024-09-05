#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("graf.txt");

int matrix[51][51], vizitat[101], coada[101], parinte[101];

void moore(int matrix[][51], int n, int vf_sursa, int vf_dest) {
    int st=0, dr=0;
    vizitat[vf_sursa] = 1;
    coada[dr++] = vf_sursa;
    parinte[vf_sursa] = 0;

    while(st != dr) {
         int nod = coada[st++];
         if (nod == vf_dest) {
             break;
         }
         for(int i=1;i<=n;i++) {
             if(matrix[nod][i] == 1) {
                 int vecin = i;
                 if(vizitat[vecin] == 0) {
                     coada[dr++] = vecin;
                     vizitat[vecin] = 1;
                     parinte[vecin] = nod;
                 }
             }
         }
    }
    int j = vf_dest;
    if(parinte[j] == 0) {
        cout<<"Nu exista drum pana la "<<vf_dest;
    } else{
        cout<<"Cel mai scurt lant de la varful "<<vf_sursa<<" la varful "<<vf_dest<<": ";
        while (j != 0) {
            cout<<j<<" ";
            j = parinte[j];
        }
    }
    cout<<"\n";
}

int main() {
    int n, m=0, x, y, vf;
    fin>>n;
    while(fin>>x>>y)
    {
        matrix[x][y] = 1;
        m++;
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout<<"\n";
    }
    cout<<"Varful de inceput:";
    cin>>vf;
    for(int i=1;i<=n;i++) {
        if(i!=vf) {
            moore(matrix, n, vf, i);
        }
    }
    cout<<" ";
    return 0;
}

// lanțul cel mai scurt dintr-un vârf