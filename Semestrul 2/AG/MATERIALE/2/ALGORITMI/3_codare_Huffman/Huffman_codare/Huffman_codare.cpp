#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt");
string s, cod[128];
int fr[128];


struct Nod {
	int lt, rt, nr_ap;
	char c;
}arbore[255];


void codare(int a, string c)
{	
	//daca nu mai are nici left tree nici right tree, ce am obt. pana acum e codul literei
	Nod& nod = arbore[a];
	if (nod.lt == -1 && nod.rt == -1)
		cod[(int)nod.c] = c;
	//altfel continuam pana la frunza
	else
	{
		codare(nod.lt, c + '0');
		codare(nod.rt, c + '1');
	}
}


int main()
{
	int n = 0, q = 0;
	auto cmp = [](int lhs, int rhs)
	{
		return arbore[lhs].nr_ap > arbore[rhs].nr_ap || (arbore[lhs].nr_ap == arbore[rhs].nr_ap && arbore[lhs].c > arbore[rhs].c);
	};
	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

	//citim si identificam caracterele si numaram frecventa
	getline(f, s);
	for (auto c : s)
	{
		if (fr[(int)c] == 0) n++; //n este numarul de caractere distincte, pt a crea alfabetul
		fr[(int)c]++;
	}
	g << n << endl;

	//punem toate nodurile existente intr-o coada cu prioritati - alfabetul (adica de la cel cu cea mai mare frecventa, la cel cu cea mai mica frecventa)
	for (int c = 0; c < 128; c++)
	{
		if (fr[c] != 0)
		{
			g << (char)c << " " << fr[c] << endl; //afisez litera si frecventa ei
			Nod& nod = arbore[q]; //q este nr. nodului la care am ajuns in arbore

			//actualizam informatiile din nod
			nod.c = (char)c;
			nod.lt = nod.rt = -1;
			nod.nr_ap = fr[c];

			//adaugam in coada de prioritati numarul nodului (functia cmp il introduce bine)
			pq.push(q); q++;
		}
	}

	//construim arborele
	while (pq.size() >= 2)
	{
		//construim un nod nou, cu cele mai mici 2 frecvente din nodurile pe care le avem
		auto lt = pq.top(); pq.pop();
		auto rt = pq.top(); pq.pop();

		Nod& nod = arbore[q];
		nod.nr_ap = arbore[lt].nr_ap + arbore[rt].nr_ap;
		nod.c = min(arbore[lt].c, arbore[rt].c);
		nod.lt = lt;
		nod.rt = rt;

		//adaugam in coada de prioritati noul nod
		pq.push(q); q++;
	}

	//parcurgem arborele si generam codul fiecarui caracter lipind la vectorul de string-uri 0 si 1
	codare(q - 1, "");

	//afisam
	for (auto c : s)
		g << cod[(int)c];

	f.close();
	g.close();
	return 0;
}