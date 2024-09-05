//BELLMAN_RADACINA
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ifstream fin("garf.in");
int distanta[50],radacina[50];
void BellmanFord(int g[][3], int v, int m, int src)
{  for (int i = 0; i <= v; i++)
        {distanta[i] = INT_MAX;
        radacina[i]=-1;}

    distanta[src] = 0;
    radacina[src]=0;

    for (int i = 1; i < v ; i++)
    for (int j = 0; j < m; j++)
    {
        if (distanta[g[j][0]] != INT_MAX && distanta[g[j][0]] + g[j][2] < distanta[g[j][1]])
                {distanta[g[j][1]] = distanta[g[j][0]] + g[j][2];
                radacina[g[j][1]]=g[j][0];
                }
    }

    for (int i = 0; i < m; i++)
    {
        int x = g[i][0];
        int y = g[i][1];
        int cost = g[i][2];
        if (distanta[x] != INT_MAX && distanta[x] + cost < distanta[y])
            cout << "Contine ciclu negativ." << endl;
    }
}

int main()
{
    int x,y,i,j,v,m,a,b,inceput,sfarsit;
    fin>>v>>m;
    int g[20][3]={0},varfuri[20][3]={0};
    for(i=0;i<v;i++){
        fin>>x>>y;
        varfuri[i][0]=x;
        varfuri[i][1]=y;
    } for(i=0;i<3;i++)
    for(i=0;i<m;i++){
        fin>>a>>b;
        g[i][0]=a;
        g[i][1]=b;
        g[i][2]=sqrt((varfuri[b-1][0]-varfuri[a-1][0])*(varfuri[b-1][0]-varfuri[a-1][0])+(varfuri[b-1][1]-varfuri[a-1][1])*(varfuri[b-1][1]-varfuri[a-1][1]));
    }

    cout<<"Introduceti nodul de inceput si nodul de sfarsit: ";
    cin>>inceput>>sfarsit;
    BellmanFord(g, v, m, inceput);

    if(distanta[sfarsit] == INT_MAX)
        cout<<"Nu exista un drum intre aceste noduri.";
    else
    {   cout<<sfarsit<<" ";
        while(radacina[sfarsit] != 0)
        {   sfarsit = radacina[sfarsit];
            cout<<sfarsit<< " ";
        }
    }
    ///nodurile sunt numerotate de la 1!!!!!

    return 0;
}
