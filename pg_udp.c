#include "postgres.h"
#include "fmgr.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1( udp_send );
void _PG_init(void);
void _PG_fini(void);


void
_PG_init(void)
{
	
}

void
_PG_fini(void)
{
	
}


Datum
udp_send(PG_FUNCTION_ARGS)
{
	char	   *hostname,
			   *data;
	int			sock,
				port;
	struct sockaddr_in	server_addr;
	struct hostent	   *host;

	hostname = PG_GETARG_CSTRING(0);
	port = PG_GETARG_UINT32(1);
	data = PG_GETARG_CSTRING(2);

	host = (struct hostent *) gethostbyname((char *) hostname);

	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		elog(ERROR, "Socket error");
	}

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(port);
	server_addr.sin_addr = *((struct in_addr *) host->h_addr);
	bzero(&(server_addr.sin_zero), 8);

	sendto(sock, data, strlen(data), 0,
		   (struct sockaddr *) &server_addr, sizeof(struct sockaddr));

	PG_RETURN_NULL();
}
