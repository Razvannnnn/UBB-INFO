#include <bits/stdc++.h>
using namespace std;

void BellmanFord(int g[][3], int V, int E, int src)
{   int distanta[V];
    for (int i = 0; i < V; i++)
        distanta[i] = INT_MAX;

    distanta[src] = 0;

    for (int i = 0; i < V - 1; i++)
    for (int j = 0; j < E; j++)
    {
        if (distanta[g[j][0]] != INT_MAX && distanta[g[j][0]] + g[j][2] < distanta[g[j][1]])
                distanta[g[j][1]] = distanta[g[j][0]] + g[j][2];
    }

    for (int i = 0; i < E; i++)
    {
        int x = g[i][0];
        int y = g[i][1];
        int cost = g[i][2];
        if (distanta[x] != INT_MAX && distanta[x] + cost < distanta[y])
            cout << "Contine ciclu negativ." << endl;
    }
    for (int i = 0; i < V; i++)
        cout << i << ": "<< distanta[i] << endl;
}

int main()
{
    int n = 5;
    int E = 8;

    int g[][3] = { { 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 }, { 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 } };

    BellmanFord(g, n, E, 0);
    return 0;
}
