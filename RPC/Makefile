# Compilacion de cliente y servidor RPC
# Funciona con Linux
# En MacOSX posiblemente hay que quitar -lnsl 
all:	client server

hello_svc.c hello_clnt.c: hello.h

hello.h: hello.x
	rpcgen hello.x


client: hello_clnt.c helloclient.o hello_clnt.o
	cc -o client helloclient.o hello_clnt.o #-lnsl


server: hello_svc.c helloserver.o hello_svc.o
	cc -o server helloserver.o hello_svc.o #-lnsl

clean:
	rm -f *.o client server hello.h hello_clnt.c hello_svc.c *~