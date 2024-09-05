#include <iostream>

using namespace std;

void incidenta_to_lista(int in[20][20],int cnt,int n) ///muchii apoi noduri
{   int inceput,sfarsit,ok,m[20][20]={0};
    for(int j=1;j<=cnt;j++)
    {ok=0;
        for(int i=1;i<=n;i++)
    {
        if(in[i][j]==1 && ok==0)
        {
            inceput=i;
            ok=1;
        }
        if(in[i][j]==1 && ok==1)
        {
            sfarsit=i;
        }
    }
    m[inceput][sfarsit]=1;
    m[sfarsit][inceput]=1;
    }
    cout<<endl<<"Lista de adiacenta obtinuta din matricea de incidenta este:"<<endl;
    for(int i=1;i<=n;i++)
    {   cout<<i<<": ";
        for(int j=1;j<=n;j++)
        {
         if(m[i][j]==1)
                cout<<j<<" ";
        }
        cout<<endl;
    }
}
