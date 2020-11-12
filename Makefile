# Modèle de fichier Makefile, à adapter pour le TP

# options de compilation
CC = gcc
CCFLAGS = -Wall
LIBS = 
LIBSDIR = -L/tp5-gbenmo

# fichiers du projet
SRC = blackjack.c carte.c
OBJ = $(SRC:.c=.o)
EXEC = blackjack.exe


# règle initiale
all: $(EXEC)

# dépendance des .h
carte.o: carte.h
blackjack.o: carte.h
# règles de compilation
%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<
	
# règles d'édition de liens
$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LIBS) $(LIBSDIR)

# règles supplémentaires
clean:
	rm -f *.o
mproper:
	rm -f $(EXEC) *.o
