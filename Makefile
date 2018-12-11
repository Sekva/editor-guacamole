CFLAGS= -g -L/usr/X11R6/lib -lX11

OBJETOS=./objs/main.o

all: limpa janela #som.o final

janela: $(OBJETOS)
	$(CC) $(CFLAGS) $(OBJETOS) -o ./out/janela $(LIBS)

$(OBJETOS): ./src/main.c
	$(CC) $(CFLAGS) -c ./src/main.c -o ./objs/main.o

limpa:
	rm -f ./out/* ./objs/*
