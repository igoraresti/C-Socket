/* 
 * File:   main.c
 * Author: igor
 *
 * Created on 28 de mayo de 2012, 18:03
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#define PORT 5000
#define DIRSIZE 80

main (int argc, char *argv[])
{
char dir [DIRSIZE];
int fdc;
struct sockaddr_in server_in;
struct hostent *hp;
if(argc != 3){
printf("Uso %s servidor frase\n", argv[0]);
exit(1);
}
if ((hp = gethostbyname(argv[1])) == NULL)
{
perror("gethostbyname");
exit (1);
}
server_in.sin_family = AF_INET;
server_in.sin_addr.s_addr = ((struct in_addr *)(hp->h_addr)) ->s_addr;
server_in.sin_port = htons(PORT);
if ((fdc = socket(PF_INET, SOCK_STREAM, 0)) == -1){
perror ("socket");
exit (1);
}
if (connect(fdc,(struct sockaddr*)&server_in, sizeof(server_in))== -1){
perror ("connect");
exit (1);
}

if ( write(fdc, argv[2], strlen(argv[2])+1) == -1){
perror ("send");
exit (1);
}
if (read(fdc, dir, DIRSIZE) == -1){
perror ("recv");
exit (1);
}
printf ("Ha llegado del servidor: %s\n", dir);
close (fdc);
}


