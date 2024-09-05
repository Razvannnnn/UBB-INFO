#include <iostream>

using namespace std;

int mat_inc[251][251],n,m;

int main() {
    int x,y,k=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin >> x >> y;
        mat_inc[x][i]=1;
        mat_inc[y][i]=1;
        k++;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            cout<<mat_inc[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/*

4
5
1 2
2 3
2 4
3 4
4 1

 */