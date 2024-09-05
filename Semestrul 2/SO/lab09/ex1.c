#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_SIZE 100

int main() {
	char sir[] = "aeiouBaeiouC";

	char vocale[] = "aeiouAEIOU";

	for( int i=0;i<strlen(vocale);i++ ) {
		int pd[2];
		if(pipe(pd) == -1) {
			perror("pipe()");
			exit(1);
		}
		int pid = fork();
		if(pid == -1) {
			perror("fork()");
			exit(1);
		}
		if(pid == 0) {
			close(pd[0]);

			char* tmp = malloc(MAX_SIZE * sizeof(char));
			int k = 0;

			for(int j=0;j<strlen(sir);j++) {
				if(sir[j] != vocale[i]) {
					tmp[k++] = sir[j];
				}
			}
			tmp[k] = '\0';
			write(pd[1], tmp, MAX_SIZE);
			close(pd[1]);
			free(tmp);
			exit(0);
		}
		close(pd[1]);
		char* tmp = malloc(MAX_SIZE * sizeof(char));
		read(pd[0], tmp, MAX_SIZE);
		strcpy(sir, tmp);
		free(tmp);
		close(pd[0]);
		wait(NULL);

	}
	printf("Sir final: %s\n", sir);
	return 0;
}
