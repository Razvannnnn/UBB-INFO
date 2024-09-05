#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int viz[101], matrix[101][101], n;
int grup[101]; // Vectorul pentru a memora grupul fiecărui nod
int nr_grupuri = 0; // Numărul de grupuri

void DFS(int nod)
{
    viz[nod] = 1;
    grup[nod] = nr_grupuri;

    for (int i = 0; i < n; i++)
    {
        if (matrix[nod][i] && !viz[i])
        {
            DFS(i);
        }
    }
}

void findGroups()
{
    for (int i = 0; i < n; i++)
    {
        if (!viz[i])
        {
            DFS(i);
            nr_grupuri++;
        }
    }
}

int main()
{
    int x, y, nod;
    cin >> n;
    while (fin >> x >> y)
    {
        matrix[x][y] = 1; // Marcam muchiile grafului orientat
    }
    fin.close();

    findGroups();

    // Afisarea grupurilor
    for (int i = 0; i < nr_grupuri; i++)
    {
        cout << "Grupul " << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            if (grup[j] == i)
                cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}