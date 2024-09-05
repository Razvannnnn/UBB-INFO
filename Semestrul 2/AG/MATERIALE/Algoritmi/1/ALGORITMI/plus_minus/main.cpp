//PLUS MINUS
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("graf.in");

int normal[20],transpus[20],n,i,m[20][20];
void df1(int x)
{
    normal[x] = 1;
    for(int i =1 ; i <= n ; i ++)
        if(normal[i] == 0 && m[x][i] == 1)
            df1(i);
}

void df2(int x)
{
    transpus[x] = 1;
    for(int i =1 ; i <= n ; i ++)
        if(transpus[i] == 0 && m[i][x] == 1)
            df2(i);
}

int main()
{   int ok=1,x,y;
    fin>>n;
    while(fin>>x>>y)
        m[x][y]=1;

    df1(1); df2(1);

    for(i=1;i<=n;i++)
        if(normal[i]!=1 || transpus[i] != 1) {cout<<"nueok"; ok=0; break;}
    if(ok) cout<<"eok";



    return 0;
}
