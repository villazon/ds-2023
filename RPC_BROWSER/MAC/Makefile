# Compilacion de cliente y servidor RPC
# Funciona con Linux
# En MacOSX posiblemente hay que quitar -lnsl 
all:	client server

browser_svc.c browser_clnt.c browser_xdr.c: browser.h

browser.h: browser.x
	rpcgen browser.x

client: browser_clnt.c browser_xdr.c browserclient.o browser_clnt.o browser_xdr.o
	cc -o client browserclient.o browser_clnt.o browser_xdr.o #-lnsl


server: browser_svc.c browser_xdr.c browserserver.o browser_svc.o browser_xdr.o
	cc -o server browserserver.o browser_svc.o browser_xdr.o #-lnsl

test:	test.c
	cc -o test test.c

clean:
	rm -f *.o test client server browser.h browser_clnt.c browser_svc.c browser_xdr.c *~
