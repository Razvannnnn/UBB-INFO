#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt");
string s, linie;


struct Nod {
	int lt, rt, nr_ap;
	char c;
}arbore[255];


char decodare(int a, int& k)
{
	Nod& nod = arbore[a];
	//daca am ajuns la frunza, in nod.c avem caracterul
	if (nod.lt == -1 && nod.rt == -1)
		return nod.c;

	//cat timp nu am ajuns la frunza ia urmatorul caracter (0 sau 1) din s si il pune in ch
	//daca e 0 decodez pe stanga, daca e 1 pe dreapta
	else
	{
		char ch = s[k];
		k++;
		if (ch == '0') return decodare(nod.lt, k);
		else if (ch == '1') return decodare(nod.rt, k);
		else return 0;
	}
}


int main()
{
	auto cmp = [](int lhs, int rhs) { return arbore[lhs].nr_ap > arbore[rhs].nr_ap || (arbore[lhs].nr_ap == arbore[rhs].nr_ap && arbore[lhs].c > arbore[rhs].c); };
	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
	int n, k = 0, q = 0;
	f >> n;

	//citesc perechile (chr frecventa) si creez nodurile arborelui
	for (int i = 0; i < n; ++i)
	{
		Nod& nod = arbore[q];
		nod.lt = nod.rt = -1;
		getline(f, linie);
		nod.c = f.get();
		f.get();
		f >> nod.nr_ap;

		//adaug nodurile in coada cu prioritati
		pq.push(q); q++;
	}

	//construim arborele (ca si la codare)
	while (pq.size() >= 2)
	{
		auto lt = pq.top(); pq.pop();
		auto rt = pq.top(); pq.pop();

		Nod& nod = arbore[q];
		nod.nr_ap = arbore[lt].nr_ap + arbore[rt].nr_ap;
		nod.c = min(arbore[lt].c, arbore[rt].c);
		nod.lt = lt;
		nod.rt = rt;
		pq.push(q); q++;
	}

	f >> s;
	while (k < s.size())
		g << decodare(q - 1, k);

	f.close();
	g.close();
	return 0;
}