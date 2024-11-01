#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
 
int main() {
  int c;
  struct sockaddr_in server;
  uint16_t rez;
  char a[256], b[256], chr[2];
  
  c = socket(AF_INET, SOCK_STREAM, 0);
  if (c < 0) {
    printf("Eroare la crearea socketului client\n");
    return 1;
  }
  
  memset(&server, 0, sizeof(server));
  server.sin_port = htons(1234);
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  if (connect(c, (struct sockaddr *) &server, sizeof(server)) < 0) {
    printf("Eroare la conectarea la server\n");
    return 1;
  }

  printf("Primul sir = ");
  scanf("%s", &a);
  printf("Al doilea sir = ");
  scanf("%s", &b);

  send(c, a, sizeof(a), 0);
  send(c, b, sizeof(b), 0);

  recv(c, chr, 2, 0);
  recv(c, &rez, sizeof(rez), 0);
  rez = ntohs(rez);
  if(rez == 0) {
	printf("Nu s-a gasit un caracter comun\n");
  }
  else printf("Caracterul: %c, nr aparitii: %hu\n", chr[0], rez);
  close(c);
}
