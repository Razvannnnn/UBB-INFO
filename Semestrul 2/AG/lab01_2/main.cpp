#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("graf.txt");

int matrice[101][101], v[101], n;


void dfs(int k){
    v[k]=1;
    for(int i=1;i<=n;i++)
    {
        if(matrice[k][i]==1 && v[i]==0) dfs(i);
    }
}

int main() {
    int x, y;
    fin>>n;
    while(fin>>x>>y)
    {
        matrice[x][y]=1;
        matrice[y][x]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<matrice[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Noduri izolate: ";
    for(int i=1;i<=n;i++)
    {
        int ok=0;
        for(int j=1;j<=n;j++)
        {
            if(matrice[i][j]==1) ok=1;
        }
        if(ok==0) cout<<i<<" ";
    }
    cout<<"\n";
    int nrnod=0;
    for(int i=1;i<=n;i++)
    {
        if(matrice[1][i]==1) nrnod++;
    }
    int ok=0;
    for(int i=1;i<=n;i++)
    {
        int k=0;
        for(int j=1;j<=n;j++)
        {
            if(matrice[i][j]==1) {
                k++;
            }
        }
        if(k!=nrnod) ok=1;
    }
    if(ok==1) cout<<"Graful nu este regulat!\n";
    else cout<<"Graful este regulat!\n";
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i != j && matrice[i][j]==0 && matrice[i][k]!=0 && matrice[k][j]!=0) {
                    matrice[i][j] = matrice[i][k] + matrice[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<matrice[i][j]<<" ";
        }
        cout<<"\n";
    }
    dfs(1);
    ok=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0) ok=1;
    }
    if(ok==1) cout<<"Graful nu este conex!";
    else cout<<"Graful este conex!";
    return 0;
}
