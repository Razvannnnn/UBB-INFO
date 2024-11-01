#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
 
int main() {
  int s;
  struct sockaddr_in server, client;
  int c, l;
  
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    printf("Eroare la crearea socketului server\n");
    return 1;
  }
  
  memset(&server, 0, sizeof(server));
  server.sin_port = htons(1234);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  
  if (bind(s, (struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Eroare la bind\n");
    return 1;
  }
 
  listen(s, 5);
  
  l = sizeof(client);
  memset(&client, 0, sizeof(client));
  
  while (1) {
    char a[256], b[256], chr[2] = {0};
    uint16_t rez;
    int fr[256] = {0}, maxi = 0;

    c = accept(s, (struct sockaddr *) &client, &l);
    printf("S-a conectat un client.\n");
    // deservirea clientului
    recv(c, a, sizeof(a), MSG_WAITALL);
    recv(c, b, sizeof(b), MSG_WAITALL);
    int len_a = strlen(a);
    int len_b = strlen(b);
    int mini = len_a < len_b ? len_a : len_b;

    for(int i=0;i<mini;i++) {
	if(a[i] == b[i]) {
	    fr[a[i]]++;
	    if(fr[a[i]] > maxi) {
		maxi = fr[a[i]];
		chr[0] = a[i];
	    }
	}
    }

    rez = htons(maxi);
    send(c, chr, 2, 0);
    send(c, &rez, sizeof(rez), 0); 
    close(c);
    // sfarsitul deservirii clientului;
  }
}
