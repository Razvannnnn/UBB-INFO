//DIJKSTA RADACINA
#include<iostream>
#include<limits.h>
#include<fstream>
using namespace std;

ifstream fin("graf.in");

int graf[10][10],n,x,y,radacini[10],distanta[10];

int distante_minime(int distanta[], bool vizitat[])
{   int minim=INT_MAX,ind;

    for(int i=1;i<=n;i++)
    {
        if(vizitat[i]==false && distanta[i]<=minim)
        {
            minim=distanta[i];
            ind=i;
        }
    }
    return ind;
}

void dijkstra(int radacina)
{
    int i;
    bool vizitat[n];


    for(int k = 1; k<=n; k++)
    {
        distanta[k] = INT_MAX;
        vizitat[k] = false;
        radacini[k]=-1;
    }

    distanta[radacina] = 0;
    radacini[radacina]=0;

    for(i = 1; i<=n; i++)
    {   int m=distante_minime(distanta,vizitat);

        vizitat[m]=true;
        for(int k = 1; k<=n; k++)
            if(!vizitat[k] && graf[m][k] && distanta[m]!=INT_MAX && distanta[m]+graf[m][k]<distanta[k])
                {distanta[k]=distanta[m]+graf[m][k];
                radacini[k]=m;}

    }

}

void citire_graf() {
	fin >> n;
	int x,y;
	while(fin>>x>>y) {
		graf[x][y] = 1;
	}
}

int main()
{   int nod_inceput,sfarsit;
    fin>>nod_inceput>>sfarsit;
    citire_graf();
    dijkstra(nod_inceput);

    if(distanta[sfarsit] == INT_MAX)
        cout<<"Nu exista un drum intre aceste noduri.";
    else
    {   cout<<sfarsit<<" ";
        while(radacini[sfarsit] != 0)
        {   sfarsit = radacini[sfarsit];
            cout<<sfarsit<< " ";
        }
    }
    return 0;
}
