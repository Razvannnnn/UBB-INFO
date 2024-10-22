#include<iostream>
#include<climits>
#include<fstream>

using namespace std;

ifstream fin("graf.in");

int graf[20][20]={0},radacini[20],distanta[20],maxim=INT_MIN;

int distante_minime(int distanta[], bool vizitat[])
{   int minim=INT_MAX,ind;

    for(int i=0;i<=maxim;i++)
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
    bool vizitat[maxim+2];

    for(int k = 0; k<=maxim; k++)
    {
        distanta[k] = INT_MAX;
        vizitat[k] = false;
        radacini[k]=-2;
    }

    distanta[radacina] = 0;
    radacini[radacina] = -1;

    for(i = 0; i<=maxim; i++)
    {   int m=distante_minime(distanta,vizitat);
        vizitat[m]=true;

        for(int k = 0; k<=maxim; k++)
            if(!vizitat[k] && graf[m][k] && distanta[m]!=INT_MAX && distanta[m]+graf[m][k]<distanta[k])
            {distanta[k]=distanta[m]+graf[m][k];
                radacini[k]=m;}
    }

}


int main()
{   int nod_inceput,sfarsit;
    fin>>nod_inceput>>sfarsit;

    int muchii,i,j,k,cost;
    fin>>muchii;
    for(k=1;k<=muchii;k++){
        fin>>i>>j>>cost;
        graf[i][j]=cost;
        if(i>maxim) maxim=i;
        if(j>maxim) maxim=j;
    }
    /*for(i=0;i<=maxim;i++)
    {for(j=0;j<=maxim;j++)
    cout<<graf[i][j]<<" ";
    cout<<endl;}*/

    dijkstra(nod_inceput);

    if(distanta[sfarsit] == INT_MAX)
        cout<<"Nu exista un drum intre aceste atractii."<<endl;
    else
    {   cout<<sfarsit<<" ";
        while(radacini[sfarsit] != -1)
        {   sfarsit = radacini[sfarsit];
            cout<<sfarsit<< " ";
        }
    }
    return 0;
}

