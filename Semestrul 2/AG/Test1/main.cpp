#include <iostream>
#include <fstream>
using namespace std;
#define inf 64000

ifstream fin("input.txt");

int dist[105];

struct bellman
{
    int x, y, len;
} drum[10005];

void relax(int u, int v, int len)
{
    if (dist[v] > dist[u] + len)
        dist[v] = dist[u] + len;
}

bool bellman_ford(int n, int v, int s)
{
    for (int i = 1; i <= n; i++)
        dist[i] = inf;
    dist[s] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=v; j++) {
            relax(drum[j].x, drum[j].y, drum[j].len);
        }
    }
    for (int j=1; j<=v; j++) {
        if (dist[drum[j].y] > dist[drum[j].x] + drum[j].len)
            return false;
    }
    return true;
}

int main() {
    int x, y, len;

    int orase = 0;
    int drumuri = 0;
    while(fin >> x >> y >> len) {
        drumuri++;
        drum[drumuri].x = x;
        drum[drumuri].y = y;
        drum[drumuri].len = len;

        if(orase < x) orase = x;
        if(orase < y) orase = y;
    }
    int start;
    cout << "Orasul de start:";
    cin >> start;
    if (!bellman_ford(orase, drumuri, start)) {
        cout << "Ciclu negativ!";
    } else {
        for (int i = 1; i <= orase; i++) {
            if (dist[i] == inf) cout <<i<<". "<< "Nu exista drum\n";
            else cout <<i<<". "<< dist[i] << "\n";
        }
    }
    fin.close();
    return 0;
}