//DIJKSTA
#include<iostream>
#include<limits.h>
#include<fstream>
using namespace std;

ifstream fin("graf.in");

int graf[10][10],n,x,y;

int distante_minime(int distanta[], bool vizitat[])
{   int minim=INT_MAX,ind;

    for(int i=0;i<6;i++)
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
    int distanta[n],i;
    bool vizitat[n];


    for(int k = 0; k<n; k++)
    {
        distanta[k] = INT_MAX;
        vizitat[k] = false;
    }

    distanta[radacina] = 0;
    for(i = 0; i<n; i++)
    {   int m=distante_minime(distanta,vizitat);

        vizitat[m]=true;
        for(int k = 0; k<n; k++)
            if(!vizitat[k] && graf[m][k] && distanta[m]!=INT_MAX && distanta[m]+graf[m][k]<distanta[k])
                distanta[k]=distanta[m]+graf[m][k];

    }
    for(i = 0; i<n; i++)
    {
        cout<<char('A'+i)<<"   "<<distanta[i]<<endl;
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
{   int nod_inceput;
    fin>>nod_inceput;
    citire_graf();
    dijkstra(nod_inceput);
    return 0;
}
