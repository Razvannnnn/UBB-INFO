

int i=0;

send(c, &i, sizeof(i));        //c descriptor client
recv(c', &i, sizeof(i));             // primire in server

// pentru a nu avea probleme cand trimitem numere spre server
// folosim int17_t, uint32_t, uint8_t

uint16_t n;
send(c, &n, sizeof(n));
recv(c', &n, sizeof(n), MSG_WAITALL);      // FLAG - asteapta pana ii citeste pe toti


uint16_t k = 1234;
send(c, &k, sizeof(k));        // --> in memorie va fi [04h][D2h]

int16_t k = 1234;
send(c, &k, sizeof(k));        // --> in memorie va fi tot [04h][D2h], dar in server sa fie declarat tot ca int16_t

    //transformam k intr un sir de caractere
	sprintf(buf, "%hu", k)  // "1234"
	send(c, buf, strlen(buf));

send(c, buf, strlen(buf));    // trimitem spre server
recv(c, buf, strlen(buf));    // gresit, ar trebui sa trimitem inainte lungimea buffer-ului
