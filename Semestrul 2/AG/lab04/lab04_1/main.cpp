#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fisier.in");
ofstream fout("fisier.out");

int parinte[101], prufer[101];

int frunzaMin(int n) {
    int fr=0, i=0;
    while (i<n) {
        if(fr == parinte[i]) {
            fr++;
            i=-1;
        }
        i++;
    }
    return fr;
}

void Prufer(int n) {
    for(int i=0;i<n-1;i++) {
        int fr = frunzaMin(n);
        prufer[i] = parinte[fr];
        parinte[fr] = fr;
    }
}

int main() {
    int n;
    fin>>n;
    for(int i=0;i<n;i++) {
        fin>>parinte[i];
    }
    Prufer(n);
    fout<<n-1<<"\n";
    for(int i=0;i<n-1;i++) {
        fout<<prufer[i]<<" ";
    }
    return 0;
}
