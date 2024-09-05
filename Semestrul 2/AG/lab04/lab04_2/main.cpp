#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("fisier.in");
ofstream fout("fisier.out");

int parinte[101], prufer[101], grad[101];

int frunzaMin(int n) {
    for(int i=0;i<=n;i++) {
        if(grad[i] == 1) {   // frunza
            return i;
        }
    }
    return -1;
}

void decodPrufer(int n) {
    for(int i=0;i<=n;i++) {
        grad[i] = 1; // consideram nodurile frunza
    }
    for(int i=0;i<=n;i++) {
        grad[prufer[i]]++; // gradul real al nodurilor
    }
    for(int i=0;i<=n;i++) {
        int fr = frunzaMin(n);
        int p = prufer[i];

        parinte[fr] = p;  // parintele frunzei
        grad[p]--;        // reducem gradul
        grad[fr] = 0;     // marcam frunza ca vizitata
    }

    // conectam ultimele 2 frunza
    int fr1 = frunzaMin(n);
    grad[fr1] = -1;
    int fr2 = frunzaMin(n);
    parinte[fr1] = fr2;
}

int main() {
    int n;
    fin>>n;
    for(int i=0;i<n;i++) {
        fin>>prufer[i];
    }
    decodPrufer(n);
    fout<<n+1<<"\n";
    for(int i=0;i<=n;i++) {
        fout<<parinte[i]<<" ";
    }
    return 0;
}
