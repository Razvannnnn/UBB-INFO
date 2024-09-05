#include <iostream>
#include <fstream>

using namespace std;

typedef struct muchie {
    int x, y, w;
};

int V, E, t[101];
muchie m[5000];

int main()
{
    ifstream f("in.txt");
    int i, j, s = 0, nr = 0, ax, ay;
    bool ok = true;
    muchie aux;

    ///citesc datele
    f >> V >> E;
    for (i = 0; i < E; i++)
        f >> m[i].x >> m[i].y >> m[i].w;

    ///sortez muchiile crescator, dupa cost
    do {
        ok = true;
        for (i = 0; i < E - 1; i++)
            if (m[i].w > m[i + 1].w)
            {
                aux.x = m[i].x;      aux.y = m[i].y;      aux.w = m[i].w;
                m[i].x = m[i + 1].x;   m[i].y = m[i + 1].y;   m[i].w = m[i + 1].w;
                m[i + 1].x = aux.x;    m[i + 1].y = aux.y;    m[i + 1].w = aux.w;

                ok = false;
            }
    } while (ok == false);

    ///initializez
    for (i = 0; i < V; i++)
        t[i] = i;

    ///determin arborele minim de acoperire
    for (i = 0; i < E; i++)
        if (t[m[i].x] != t[m[i].y]) /// extremitatile apartin de subarbori diferiti
        {
            s = s + m[i].w;
            nr++;
            cout << m[i].x << " " << m[i].y << endl;

            ///reunesc subarborii (basically reunesc cele 2 noduri in unul)
            ax = t[m[i].x];
            ay = t[m[i].y];
            for (j = 0; j < V; j++)
                if (t[j] == ay)
                    t[j] = ax;
        }
    cout << nr << endl << s << endl;
    return 0;
}
