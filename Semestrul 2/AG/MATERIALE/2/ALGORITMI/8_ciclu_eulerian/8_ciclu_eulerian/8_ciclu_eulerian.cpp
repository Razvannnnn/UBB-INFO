#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt");
vector <pair<int, int>> graf[100]; //salvam si nr muchiei sa putem marca vizitatele
int viz[500];
stack <int> stiva;
int v, m,prim;

//plecam de la ideea ca se da un graf ce are un ciclu eulerian
void Euler()
{
	int nod, muchie, y;
	stiva.push(prim); //un nod care sigur are legaturi, il punem in stiva
	while (!stiva.empty())
	{
		nod = stiva.top();
		//se opreste in momentul in care nu mai are nodul de inceput legaturi
		if (graf[nod].size() == 0)
		{
			stiva.pop();
			g << nod << " ";
		}
		else
		{
			y = graf[nod].back().first; //un nod cu care x are muchie
			muchie = graf[nod].back().second; //numarul muchiei
			graf[nod].pop_back(); //scoatem nodul vechi din stiva
			if (viz[muchie] == 0)
			{
				viz[muchie] = 1; //marcam muchia ca fiind vizitata (sa nu mai trecem prin ea)
				stiva.push(y); //punem nodul y in stiva (sa continuam parcurgerea)
			}
		}
	}
}


int main()
{
	int x, y, ok=0;
	f >> v >> m;
	for (int i = 0; i < m; i++)
	{
		f >> x >> y;
		if (ok == 0) {prim = x; ok = 1;} //primul nod ce are o legatura cu restul
		graf[x].push_back({ y,i }); //salvez si extremitatea si numarul muchiei (ma ajuta sa nu trec de 2 ori printr-o muchie)
		graf[y].push_back({ x,i });
	}
	Euler();
	f.close();
	g.close();
	return 0;
}