#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt");
vector <int> parinte;
queue <int> coada;
map <int, int> nu_exista; //map ca sa le gasim cu complexitate theta(1) - hash table in spate
map <int, int> nrAparitii;

int main()
{
	int n, m, x, y;
	f >> m;
	n = m + 1;
	parinte.resize(n);
	//initializam cu -1 toti parintii
	//momentan presupunem ca toate nodurile exista (nu_exista=0)
	for (int i = 0; i < n; i++)
	{
		parinte[i] = -1;
		nu_exista[i] = 0;
	}

	//citim codarea(facem un vector de aparitii si de nu_exista
	//daca nu_exista[x]=0, el exista, altfel nu exista in codare
	for (int i = 0; i < m; i++)
	{
		f >> x;
		coada.push(x);
		nu_exista.erase(x);
		nrAparitii[x]++;
	}

	//lucram cu primul elem din coada
	for (int i = 0; i < m; i++)
	{
		x = coada.front();
		coada.pop(); //il stergem
		y = (*nu_exista.begin()).first; //primul nr natural ce nu e in codare
		if (nrAparitii[x] == 1) //daca x era singura sa aparitie, il punem in nu exista si il stergem din aparitii
		{
			nrAparitii.erase(x);
			nu_exista[x] = 1;
		}
		else
			nrAparitii[x]--; //altfel doar scadem nr de aparitii
		
		nrAparitii[y]++;

		//acum exista y si nu mai vrem sa l luam in considerare cand cautam cmm nr nat ce nu e in codare
		nu_exista.erase(y);
		parinte[y] = x; //y-ul gasit e fiul lui x
	}

	//afisare sir pe baza vectorului de parinti
	g << n << endl;
	for (int i = 0; i < n; i++)
		g << parinte[i] << " ";
	f.close();
	g.close();
	return 0;
}