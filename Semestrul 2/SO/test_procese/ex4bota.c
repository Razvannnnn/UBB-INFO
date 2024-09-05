//4. Să se scrie un program C care creează un proces copil cu care comunică prin pipe. Procesul părinte citeşte de la tastatură două numere întregi pe care le trimite prin pipe procesului copil, iar procesul copil returnează prin pipe suma lor.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int pd[2];
    int a, b, sum = 0 ;
    int rez = pipe(pd);
    if(rez == -1)
    {
        perror("pipe()");
        exit(1);
    }
    
    int pid = fork();
    if(pid == -1)
    {
        perror("fork()");
        exit(1);
    }
    if(pid == 0)  //proces copil
    {
        close(pd[1]);
   
        read(pd[0], &a, sizeof(int));
        read(pd[0], &b, sizeof(int));

        sum = a+b;
        write(pd[1], &sum, sizeof(int));
        close(pd[0]);
        exit(0);
    }
    else          //proces parinte
    {
        close(pd[0]);
        printf("Read nr:");
        scanf("%d %d", &a, &b);
        write(pd[1], &a, sizeof(int));
        write(pd[1], &b, sizeof(int));
        close(pd[1]);
        wait(NULL);
    }
    return 0;
}
