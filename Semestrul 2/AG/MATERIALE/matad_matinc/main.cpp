#include <iostream>

using namespace std;

int mat_adc[251][251],mat_inc[251][251],n,m;

int main() {
    int x,y,k=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin >> x >> y;
        mat_adc[x][y]=1;
        mat_adc[y][x]=1;
    }

    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(mat_adc[i][j]==1) {
                k++;
                mat_inc[i][k]=1;
                mat_inc[j][k]=1;
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
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