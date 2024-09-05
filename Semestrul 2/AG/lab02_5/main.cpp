#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int viz[101], matrix[101][101], n;

void DFS(int nod)
{
    for(int i=1;i<=n;i++)
        if(viz[i] == 0 && matrix[nod][i])
        {
            cout<<i<<" ";
            viz[i] = 1;
            DFS(i);
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
    cin >> nod;
    DFS(nod);
    return 0;
}

//Pentru un graf dat să se afișeze pe ecran vârfurile descoperite de apelul recursiv al procedurii DFS_VISIT(G, u)