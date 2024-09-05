#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
ifstream f("in.txt");
ofstream g("out.txt");

int n;
vector <int> parinte, nr_succesori, k;
set <int> frunze;

int main()
{
	f >> n;
	nr_succesori.resize(n + 1);
	parinte.resize(n + 1);
	//stabilim statusul nodurilor (frunza sau nu)
	for (int i = 0; i < n; i++)
	{
		f >> parinte[i];
		if (parinte[i] != -1)
			//daca are succesori, nu e frunza
			nr_succesori[parinte[i]]++;
	}
	for (int i = 0; i < n; i++)
		if (nr_succesori[i] == 0)
			//daca nr de succesori e 0, este frunza
			frunze.insert(i);
	//cat timp mai exista frunze
	while (frunze.size() > 0)
	{
		int f = *frunze.begin();
		//stergem din arbore cea mai mica frunza (set pt ca le memoreaza in ord. cresc.)
		frunze.erase(frunze.begin());
		if (parinte[f] != -1)
		{
			int pr = parinte[f];
			//ii adaugam parintele in codare
			k.push_back(pr);
			nr_succesori[pr]--;
			//daca parintele a devenit frunza, il adaugam la frunze
			if (nr_succesori[pr] == 0)
				frunze.insert(parinte[f]);
		}

	}
	//afisam
	g << k.size() << endl;
	for (int i = 0; i < k.size(); i++)
		g << k[i] << " ";
	g << endl;
	f.close();
	g.close();
	return 0;
}