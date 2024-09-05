#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int viz[101], matrix[101][101], n;
int coada[1001], st, dr;

void BFS(int nod)
{
    st = 0;
    coada[dr++] = nod;
    int d = 1;
    viz[nod] = 1;
    while(dr != st)
    {

        for(int i=0;i<n;i++)
            if(matrix[coada[st]][i] && viz[i] == 0)
            {
                cout<<i<<" "<<d<<"\n";
                coada[dr++] = i;
                viz[i] = 1;
            }
        st++;
        d++;
    }
}

int main()
{
    int x, y, nod;
    fin>>n;
    while(fin>>x>>y)
    {
        matrix[x][y] = 1;
    }
    cin>>nod;
    BFS(nod);
    return 0;
}

// Pentru un graf dat să se afișeze pe ecran vârfurile descoperite de algoritmul BFS și distanța față de vârful sursă