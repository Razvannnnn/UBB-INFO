#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

// Funcție pentru tratarea semnalului SIGUSR1 în procesul fiu
void child_signal_handler(int signum) {
    printf("Procesul fiu a primit semnalul SIGUSR1 și se încheie.\n");
    exit(0);
}

int main() {
    pid_t child_pid;

    // Creăm un proces fiu
    child_pid = fork();

    if (child_pid < 0) {
        perror("Eroare la fork()");
        exit(1);
    } else if (child_pid == 0) {
        // Suntem în procesul fiu

        // Instalăm handler-ul pentru semnalul SIGUSR1 în procesul fiu
        signal(SIGUSR1, child_signal_handler);

        printf("Procesul fiu rulează...\n");

        // Procesul fiu așteaptă semnalul SIGUSR1
        while(1) {
            sleep(1); // Așteptare activă
        }
    } else {
        // Suntem în procesul părinte

        // Așteptăm o scurtă pauză pentru a ne asigura că procesul fiu a fost creat
        sleep(1);

        printf("Procesul părinte rulează. Trimitem semnalul SIGUSR1 către procesul fiu...\n");

        // Trimitem semnalul SIGUSR1 către procesul fiu
        kill(child_pid, SIGUSR1);

        // Instalăm un handler gol pentru semnalul SIGUSR1 în procesul părinte pentru a preveni terminarea acestuia
        signal(SIGUSR1, SIG_IGN);

        // Așteptăm terminarea procesului fiu
        int status;
        waitpid(child_pid, &status, 0);
        if (WIFEXITED(status)) {
            printf("Procesul fiu s-a încheiat cu codul de ieșire: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
