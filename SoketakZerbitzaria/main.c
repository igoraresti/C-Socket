/* 
 * File:   main.c
 * Author: igor
 *
 * Created on 28 de mayo de 2012, 17:37
 */


#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>



#define PORT 5000
#define DIRSIZE 80
main ()
{
char dir [DIRSIZE];
int sd, fd, addrlen, i;
struct sockaddr_in server_in;
struct sockaddr_in client_in;
if ((sd = socket(PF_INET, SOCK_STREAM, 0)) == -1){
perror ("socket");
exit (1);
}
memset (&server_in, 0, sizeof(server_in));
server_in.sin_family = AF_INET;
server_in.sin_addr.s_addr = INADDR_ANY;
server_in.sin_port = htons(PORT);
if (bind(sd, (struct sockaddr*)&server_in, sizeof(struct sockaddr_in)) == -1){
perror ("bind");
exit (1);
}
if (listen(sd, 5) == -1){
perror ("listen");
exit (1);
}
addrlen= sizeof(struct sockaddr_in);
if ((fd = accept (sd, (struct sockaddr*)&client_in, &addrlen)) == -1){
perror ("accept");
exit (1);
}
if (read(fd, dir, sizeof (dir)) == -1){
perror ("recv");
exit (1);
}
printf("Ha llegado del cliente: %s\n", dir);
for (i=0; i < strlen(dir); i++){
dir[i]=toupper(dir[i]);
}
if (write(fd, dir, strlen(dir)+1)== -1){
perror ("send");
exit (1);
}
close (fd);
close (sd);


}