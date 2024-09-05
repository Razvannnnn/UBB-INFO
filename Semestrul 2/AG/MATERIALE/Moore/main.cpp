//MOORE RADACINA
#include <iostream>
#include <queue>
#include <fstream>
#define inf 10000
using namespace std;
ifstream fin("graf.in");

int a[20][20],distanta[20],radacina[20],n,vizitat[20];
queue<int>coada;

void moore(int inceput){
    int crt,i;
    vizitat[inceput] = 1;
    coada.push(inceput);

    for (i=1;i<=n;i++)
    {
        distanta[i] = inf;
        radacina[i] = -1;
    }

    distanta[inceput] = 0;
    radacina[inceput] = 0;

    while(coada.empty() != 1)
    {   crt = coada.front();
        coada.pop();
        for(i=1;i<=n;i++)
        {
            if(a[crt][i]==1 && !vizitat[i])
            {   vizitat[i] = 1;
                distanta[i] = distanta[crt] + 1;
                radacina[i] = crt;
                coada.push(i);
            }
        }
    }
}

void citeste_graf() {
	fin >> n;
	int x, y;
	while (fin >> x >> y) {
		a[x][y] = 1;
	}
}

int main()
{
    int i,j,inceput,sfarsit;
    citeste_graf();

    cout<<"Introduceti nodul de inceput si nodul de sfarsit: ";
    cin>>inceput>>sfarsit;
    moore(inceput);

    if(distanta[sfarsit] == inf)
        cout<<"Nu exista un drum intre aceste noduri.";
    else
    {   cout<<sfarsit<<" ";
        while(radacina[sfarsit] != 0)
        {   sfarsit = radacina[sfarsit];
            cout<<sfarsit<< " ";
        }
    }

    return 0;
}
