#include <stdio.h>

int main()
{
    int x, v[101],k=0;
    printf("Sirul de numere:");
    while(scanf("%x", &x))
    {
        if(x==0) break;
        v[++k]=x;
    }
    for(int i=1;i<=k;i++)
    {
        modul(v[i]);
        printf("\n");
    }
	printf("Programul a fost realizat cu succes!");
	return 0;
}

int modul(int);